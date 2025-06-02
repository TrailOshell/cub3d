/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keybinds.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paradari <bellixz610@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/29 14:30:47 by paradari          #+#    #+#             */
/*   Updated: 2025/06/02 16:50:15 by paradari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int	can_walk(t_data *data, double new_x, double new_y)
{
	if (new_x < 0 || new_x > data->map->n_col)
		return (-1);
	else if (new_y < 0 || new_y > data->map->n_row)
		return (-1);
	return (0);
}

void	key_wasd(t_data *data, int sign_x, int sign_y)
{
	double	new_x;
	double	new_y;

	new_x = data->player->x + (sign_x * data->player->dir_x * STEP);
	new_y = data->player->y + (sign_y * data->player->dir_y * STEP);
	if (can_walk(data, new_x, new_y) == -1)
		return ;
	clear_player(data, data->player->x * 64, data->player->y * 64);//for debug
	data->player->x = new_x;
	data->player->y = new_y;
	draw_player(data, data->player->x * 64, data->player->y * 64);//for debug
}

void	key_rotate(t_data *data, double rot_spd)
{
	double		tmp_x;
	double		tmp_y;
	t_player	*player;

	player = data->player;
	tmp_x = player->dir_x * cos(rot_spd) - player->dir_y * sin(rot_spd);
	tmp_y = player->dir_x * sin(rot_spd) + player->dir_y * cos(rot_spd);
	player->dir_x = tmp_x;
	player->dir_y = tmp_y;
	tmp_x = player->plane_x * cos(rot_spd) - player->plane_y * sin(rot_spd);
	tmp_y = player->plane_x * sin(rot_spd) + player->plane_y * cos(rot_spd);
	player->plane_x = tmp_x;
	player->plane_y = tmp_y;
	ft_ray(data);
}

void	keybinds(void *tmp)
{
	t_data	*data;

	data = (t_data *)tmp;
	if (mlx_is_key_down(data->mlx, MLX_KEY_W))
		key_wasd(data, 1, 1);
	if (mlx_is_key_down(data->mlx, MLX_KEY_A))
		key_wasd(data, 1, -1);
	if (mlx_is_key_down(data->mlx, MLX_KEY_S))
		key_wasd(data, -1, 1);
	if (mlx_is_key_down(data->mlx, MLX_KEY_D))
		key_wasd(data, -1, 1);
	if (mlx_is_key_down(data->mlx, MLX_KEY_LEFT))
		key_rotate(data, -RSPEED);
	if (mlx_is_key_down(data->mlx, MLX_KEY_RIGHT))
		key_rotate(data, RSPEED);
	ft_ray(data);
	if (mlx_is_key_down(data->mlx, MLX_KEY_ESCAPE)
		|| mlx_is_key_down(data->mlx, MLX_KEY_Q))
		free_and_exit(data);
}
