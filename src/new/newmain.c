#include "../includes/cub3d.h"

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

void	ft_init_image(t_cub *game, t_texture *img)
{
	img->no = mlx_png_file_to_image(game->mlx, NO, &img->isize,
			&img->isize);
	img->so = mlx_png_file_to_image(game->mlx, SO, &img->isize,
			&img->isize);
	img->we = mlx_png_file_to_image(game->mlx, WE, &img->isize,
			&img->isize);
	img->ea = mlx_xpm_file_to_image(img->mlx, EA, &img->isize,
			&img->isize);
}

void	init_window(t_cub *game)
{
	init_player(game->player);
	game->map = get_map(); //game->map from parser
	game->mlx = mlx_init();
	game->win = mlx_new_window(game->mlx, WIDTH, HEIGHT, "cub3D");
	mlx_put_image_to_window(window->mlx, window->win, win)
}

int	main(void)
{
	t_cub	*game;

	init_window(game);
	mlx_hook(game->win, 2, 1L << 0, key_press, &game->player);
	mlx_hook(game->win, 3, 1L << 1, key_release, &game->player);
	mlx_loop_hook(game.mlx, draw_loop, &game);
	mlx_loop(game.mlx);
	return (0);
}