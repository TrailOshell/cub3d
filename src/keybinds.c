/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keybinds.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsomchan <tsomchan@student.42bangkok.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/29 14:30:47 by paradari          #+#    #+#             */
/*   Updated: 2025/05/30 15:02:30 by tsomchan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	key_ws(t_data *data, const char key)
{
	double	new_x;
	double	new_y;

	new_x = 0;
	new_y = 0;
	if (key == 'W')
	{
		new_x = data->player->x + data->player->dir_x * STEP;
		new_y = data->player->y + data->player->dir_y * STEP;
		// if (can_walk(data, new_x, new_y) == -1)
		// 	return ;
	}
	else if (key == 'S')
	{
		new_x = data->player->x - data->player->dir_x * STEP;
		new_y = data->player->y - data->player->dir_y * STEP;
		// if (can_walk(data->map, new_x, new_y) == -1)
		// 	return ;
	}
	data->player->x = new_x;
	data->player->y = new_y;
}

void	key_ad(t_data *data, const char key)
{
	double	new_x;
	double	new_y;

	new_x = 0;
	new_y = 0;
	if (key == 'A')
	{
		new_x = data->player->x + data->player->dir_x * STEP;
		new_y = data->player->y - data->player->dir_y * STEP;
		// can_walk(data->map, new_x, new_y);
	}
	else if (key == 'D')
	{
		new_x = data->player->x - data->player->dir_x * STEP;
		new_y = data->player->y + data->player->dir_y * STEP;
		// can_walk(data->map, new_x, new_y);
	}
	data->player->x = new_x;
	data->player->y = new_y;
}

void	rotateleft(t_data *data)
{
	double	tmp_x;
	double	tmp_y;

	tmp_x = data->player->dir_x;
	tmp_y = data->player->dir_y;
	data->player->dir_x = tmp_x * cos(-RSPEED) - tmp_y * sin(-RSPEED);
	data->player->dir_y = tmp_x * sin(-RSPEED) + tmp_y * cos(-RSPEED);
	tmp_x = data->player->plane_x;
	tmp_y = data->player->plane_y;
	data->player->plane_x = tmp_x * cos(-RSPEED) - tmp_y * sin(-RSPEED);
	data->player->plane_y = tmp_x * sin(-RSPEED) + tmp_y * cos(-RSPEED);
	ft_ray(data);
}

void	rotateright(t_data *data)
{
	double	tmp_x;
	double	tmp_y;

	tmp_x = data->player->dir_x;
	tmp_y = data->player->dir_y;
	data->player->dir_x = tmp_x * cos(RSPEED) - tmp_y * sin(RSPEED);
	data->player->dir_y = tmp_x * sin(RSPEED) + tmp_y * cos(RSPEED);
	tmp_x = data->player->plane_x;
	tmp_y = data->player->plane_y;
	data->player->plane_x = tmp_x * cos(RSPEED) - tmp_y * sin(RSPEED);
	data->player->plane_y = tmp_x * sin(RSPEED) + tmp_y * cos(RSPEED);
	ft_ray(data);
}

void	keybinds(void *tmp)
{
	t_data	*data;

	data = (t_data *)tmp;
	if (mlx_is_key_down(data->mlx, MLX_KEY_W))
		key_ws(data, 'W');
	if (mlx_is_key_down(data->mlx, MLX_KEY_A))
		key_ad(data, 'A');
	if (mlx_is_key_down(data->mlx, MLX_KEY_S))
		key_ws(data, 'S');
	if (mlx_is_key_down(data->mlx, MLX_KEY_D))
		key_ad(data, 'D');
	if (mlx_is_key_down(data->mlx, MLX_KEY_LEFT))
		rotateleft(data);
	if (mlx_is_key_down(data->mlx, MLX_KEY_RIGHT))
		rotateright(data);
	ft_ray(data);
	if (mlx_is_key_down(data->mlx, MLX_KEY_ESCAPE)
		|| mlx_is_key_down(data->mlx, MLX_KEY_Q))
		free_and_exit(data);
}
