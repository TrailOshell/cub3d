#include "../includes/cub3d.h"

void	ft_suit_up(t_data *game)
{
	if (game->p_status < 4)
	{
		game->p_status++;
		if (game->p_status == 1)
			game->player = game->player_2;
		if (game->p_status == 2)
			game->player = game->player_3;
		if (game->p_status == 3)
			game->player = game->player_4;
	}
}

void	ft_check_collect(t_data *game)
{
	if (game->collect_counter == game->c_status)
	{
		ft_suit_up(game);
		game->e_status = 0;
		game->exit = game->exit_unlocked;
		mlx_put_image_to_window(game->mlx, game->window, game->exit,
			game->exit_x * IMG_SIZE, game->exit_y * IMG_SIZE);
	}
}

void	ft_put_move(int move)
{
	char	*tmp;

	tmp = ft_itoa(move);
	ft_putstr_fd("Move : ", 1);
	ft_putstr_fd(tmp, 1);
	ft_putstr_fd("\n", 1);
	free (tmp);
}

void	ft_move(t_data *game, int new_x, int new_y)
{
	if (game->map[game->pos_y + new_y][game->pos_x + new_x] == '1')
		return ;
	game->move_counter++;
	ft_put_move(game->move_counter);
	else
		mlx_put_image_to_window(game->mlx, game->window, game->tile,
			game->pos_x * IMG_SIZE, game->pos_y * IMG_SIZE);
	game->pos_x += new_x;
	game->pos_y += new_y;
	if (game->map[game->pos_y][game->pos_x] == 'C')
	{
		game->map[game->pos_y][game->pos_x] = '0';
		game->collect_counter++;
	}
	ft_check_collect(game);
	if ((game->map[game->pos_y][game->pos_x] == 'E') && game->e_status == 0)
		ft_destroy(game);
	mlx_put_image_to_window(game->mlx, game->window, game->player,
		game->pos_x * IMG_SIZE, game->pos_y * IMG_SIZE);
}

int	ft_keybinds(int key, t_data *game)
{
	if (key == ESC)
		ft_destroy(game);
	else if (key == W || key == UP)
		ft_move(game, 0, -1);
	else if (key == A || key == LEFT)
		ft_move(game, -1, 0);
	else if (key == S || key == DOWN)
		ft_move(game, 0, 1);
	else if (key == D || key == RIGHT)
		ft_move(game, 1, 0);
	return (0);
}
