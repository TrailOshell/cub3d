#include "../includes/cub3d.h"

void	put_pixel(int x, int y, int color, t_win *window)
{
	if (x >= WIDTH || y >= HEIGHT || x < 0 || y < 0)
		return ;
	int index = y * window->size_line + x * window->bpp / 8;
	window->data[index] = color & 0xFF;
	window->data[index + 1] = (color >> 8) & 0xFF;
	window->data[index + 2] = (color >> 16) & 0xFF;
}

void	draw_square(int x, int y, int size, int color, t_win *window)
{
	for (int i = 0; i < size; i++)
		put_pixel(x + i, y, color, window);
	for (int i = 0; i < size; i++)
		put_pixel(x, y + i, color, window);
	for (int i = 0; i < size; i++)
		put_pixel(x + size, y, color, window);
	for (int i = 0; i < size; i++)
		put_pixel(x, y + size, color, window);
}

void	draw_map(t_win *window)
{
	char	**map = window->map;
	int	color = 0x0000FF;
	int x = 0;
	int y = 0;
	for (y = 0; map[y][x]; x++)
		for (x = 0; map[y][x]; x++);
			if (map[y][x] == '1')
				draw_square (x * 64, y * 64, 64, color, window);
}

void	clear_image(t_win *window)
{
	for (int y = 0; y < HEIGHT; y++)
		for (int x = 0; x < WIDTH; x++)
			put_pixel(x, y, 0, window);
}

char	**get_map(void)
{
	char **map = malloc(sizeof(char *) * 11);
	map[0] = "111111111111111";
	map[1] = "100000000000001";
	map[2] = "100000000000001";
	map[3] = "100000000000001";
	map[4] = "100000000000001";
	map[5] = "100000000000001";
	map[6] = "100000000000001";
	map[7] = "100000000000001";
	map[8] = "100000000000001";
	map[9] = "100000000000001";
	map[10] = NULL;
	return (map);
}

void	init_window(t_win *window)
{
	init_player(&window->player);
	window->map = get_map();
	window->mlx = mlx_init();
	window->win = mlx_new_window(window->mlx, WIDTH, HEIGHT, "Start");
	window->img = mlx_new_image(window->mlx, WIDTH, HEIGHT);
	window->data = mlx_get_data_addr(window->img, &window->bpp, &window->size_line, &window->endian);
	mlx_put_image_to_window(window->mlx, window->win, window->img, 0, 0);
}

bool	touch(float px, float py, t_win *window)
{
	int	x = px / 64;
	int y = py / 64;
	if (window->map[y][x] == '1')
		return true;
	return false;
}

float	get_distance(float x, float y)
{
	return (sqrt(x * x + y * y));
}

void	line_of_sight(t_player *player, t_win *window, float start_x, int x)
{
	(void)start_x;
	(void)x;
	float ray_x = player->x;
	float ray_y = player->y;
	float cos_angle = cos(player->angle);
	float sin_angle = sin(player->angle);

	while(!touch(ray_x, ray_y, window))
	{
		put_pixel (ray_x, ray_y, 0xFF0000, window);
		ray_x += cos_angle;
		ray_y += sin_angle;
	}
}
int	draw_loop(t_win *window)
{
	t_player	*player = &window->player;
	move(player);
	clear_image(window);
	draw_square(player->x, player->y, 7, 0x00FF00, window);
	draw_map(window);

	
	// while(!touch(ray_x, ray_y, window))
	// {
	// 	put_pixel (ray_x, ray_y, 0xFF0000, window);
	// 	ray_x += cos_angle;
	// 	ray_y += sin_angle;
	// }
	float	fraction = PI / 3 / WIDTH;
	float	start_x = player->angle - PI / 6;
	int	i = 0;
	while (i < WIDTH)
	{
		line_of_sight(player, window, start_x, i);
		start_x += fraction;
		i++;
	}
	float ray_x = player->x;
	float ray_y = player->y;
	// float cos_angle = cos(player->angle);
	// float sin_angle = sin(player->angle);
	float dist = get_distance(ray_x - player->x, ray_y - player->y);
	float height = (64 / dist) * (WIDTH / 2);
	int start_y = (HEIGHT - height) / 2;
	int	end = start_y + height;
	while (start_y < end)
	{
		put_pixel(i, start_y, 255, window);
		start_y++;
	}

	mlx_put_image_to_window(window->mlx, window->win, window->img, 0, 0);
	return (0);
}

int	main(void)
{
	t_win	window;
	
	init_window(&window);

	mlx_hook(window.win, 2, 1L<<0, key_press, &window.player);
	mlx_hook(window.win, 3, 1L<<1, key_release, &window.player);

	mlx_loop_hook(window.mlx, draw_loop, &window);
	mlx_loop(window.mlx);
	return (0);
}