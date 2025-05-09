#include "../includes/cub3d.h"


void	ft_init_player(t_cub *game)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (game->game[y])
	{
		while (game->game[y][x])
		{
			if (game->game[y][x] == 'P')
			{
				game->pos_x = x;
				game->pos_y = y;
			}
			x++;
		}
		x = 0;
		y++;
	}
}

void	ft_init_mlx(t_cub *game)
{
	game->mlx = mlx_init();
	game->window = mlx_new_window(game->mlx, WIDTH, HEIGHT,
			"Game Start\n");
	if (!game->window)
		free(game->window);
}

void	ft_init_image(t_cub *game)
{
	game->north_texture = mlx_load_png(NO);
	game->south_texture = mlx_load_png(SO);
	game->west_texture = mlx_load_png(WE);
	game->east_texture = mlx_load_png(EA);
	game->p1_texture = mlx_load_png(P1);
	if (!game->north_texture || !game->south_texture || !game->west_texture
		|| !game->east_texture)
		return (-1);
	game->north_image = mlx_texture_to_image(mlx, game->north_texture);
	game->south_image = mlx_texture_to_image(mlx, game->south_texture);
	game->west_image = mlx_texture_to_image(mlx, game->west_texture);
	game->east_image = mlx_texture_to_image(mlx, game->east_texture);
	game->p1 = mlx_texture_to_image(mlx, game->p1_texture);
	if (!game->north_image || !game->south_image || !game->west_image
		|| !game->east_image)
		return (-1);
	return (0);
}

void	ft_set_status(char c, t_cub *game, int i, int j)
{
	if (c == 'P')
	{
		game->pos_x = j;
		game->pos_y = i;
		game->p_status++;
	}
	if (c == 'E')
	{
		game->exit_x = j;
		game->exit_y = i;
		game->e_status++;
	}
}

void	ft_init_game(t_cub *game)
{
	ft_init_player(game);
	ft_init_mlx(game);
	ft_init_image(game);
}

char	**get_map(void)
{
	char **game = malloc(sizeof(char *) * 11);
	game[0] = "111111111111111";
	game[1] = "100000000000001";
	game[2] = "100000000000001";
	game[3] = "100000000000001";
	game[4] = "1000P0000000001";
	game[5] = "100000000000001";
	game[6] = "100000000000001";
	game[7] = "100000000000001";
	game[8] = "100000000000001";
	game[9] = "100000000000001";
	game[10] = NULL;
	return (game);
}

void	ft_fill(t_cub *game, int i, int j)
{
	if (game->map[i][j] == '1')
		mlx_put_image_to_window(game->mlx, game->window, game->north_image,
			j * IMG, i * IMG);
	else if (game->map[i][j] == 'P')
		mlx_put_image_to_window(game->mlx, game->window, game->p1,
			j * IMG, i * IMG);
}

int	ft_put_graphic(t_cub *game)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (game->map[i])
	{
		while (game->map[i][j] && game->map[i][j] != '\n')
		{
			ft_fill(game, i, j);
			j++;
		}
		i++;
		j = 0;
	}
	return (0);
}

int	main(int ac, char **av)
{
	t_cub	game;

	game->game = get_map();
	ft_init_game(&game);
	ft_put_graphic(game);
	mlx_hook(game->window, KeyPress, KeyPressMask, &ft_keybinds, game);
	mlx_hook(game->window, DestroyNotify, StructureNotifyMask,
		&ft_destroy, game);
	mlx_loop(game->mlx);
	return (0);
}
