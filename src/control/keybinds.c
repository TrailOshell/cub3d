/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keybinds.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paradari <bellixz610@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/29 14:30:47 by paradari          #+#    #+#             */
/*   Updated: 2025/06/28 09:38:47 by paradari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	set_direction_left(t_player *player, t_data *data)
{
	double	tmp_x;

	tmp_x = player->dir_x;
	player->dir_x = player->dir_x * cos(-RSPEED) - player->dir_y * sin(-RSPEED);
	player->dir_y = tmp_x * sin(-RSPEED) + player->dir_y * cos(-RSPEED);
	tmp_x = player->plane_x;
	player->plane_x = tmp_x * cos(-RSPEED) - player->plane_y * sin(-RSPEED);
	player->plane_y = tmp_x * sin(-RSPEED) + player->plane_y * cos(-RSPEED);
	ft_ray_render(data);
}

void	set_direction_right(t_player *player, t_data *data)
{
	double	tmp_x;

	tmp_x = player->dir_x;
	player->dir_x = player->dir_x * cos(RSPEED) - player->dir_y * sin(RSPEED);
	player->dir_y = tmp_x * sin(RSPEED) + player->dir_y * cos(RSPEED);
	tmp_x = player->plane_x;
	player->plane_x = tmp_x * cos(RSPEED) - player->plane_y * sin(RSPEED);
	player->plane_y = tmp_x * sin(RSPEED) + player->plane_y * cos(RSPEED);
	ft_ray_render(data);
}

void	check_key_movement(t_data *data)
{
	double	cos_rad;
	double	sin_rad;

	cos_rad = cos(data->player->radian);
	sin_rad = sin(data->player->radian);
	if (mlx_is_key_down(data->mlx, MLX_KEY_LEFT))
	{
		key_leftright(data->player, RSPEED * (-1.0));
		set_direction_left(data->player, data);
	}
	if (mlx_is_key_down(data->mlx, MLX_KEY_RIGHT))
	{
		key_leftright(data->player, RSPEED);
		set_direction_right(data->player, data);
	}
	if (mlx_is_key_down(data->mlx, MLX_KEY_W))
		key_ws(data, cos_rad, sin_rad);
	if (mlx_is_key_down(data->mlx, MLX_KEY_S))
		key_ws(data, (cos_rad * (-1.0)), (sin_rad * (-1.0)));
	if (mlx_is_key_down(data->mlx, MLX_KEY_D))
		key_ad(data, cos_rad, (sin_rad * (-1.0)));
	if (mlx_is_key_down(data->mlx, MLX_KEY_A))
		key_ad(data, (cos_rad * -1.0), sin_rad);
	ft_ray_render(data);
}

void	keybinds(void *tmp)
{
	t_data	*data;

	data = (t_data *)tmp;
	check_key_movement(data);
	if (mlx_is_key_down(data->mlx, MLX_KEY_ESCAPE)
		|| mlx_is_key_down(data->mlx, MLX_KEY_Q))
		free_and_exit(data);
	if (mlx_is_key_down(data->mlx, MLX_KEY_2))
		data->draw_mode = 2;
	else if (mlx_is_key_down(data->mlx, MLX_KEY_3))
		data->draw_mode = 3;
	relocate_player(data);
}
