/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keybinds.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paradari <paradari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/29 14:30:47 by paradari          #+#    #+#             */
/*   Updated: 2025/06/27 09:27:20 by paradari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	walking(t_data *data, double new_x, double new_y)
{
	char	**grid;

	grid = data->map->grid;
	if (new_x >= 0 && new_x <= data->map->n_col
		&& iswalkable(grid[(int)data->player->y][(int)new_x]))
		data->player->x = new_x;
	if (new_y >= 0 && new_y <= data->map->n_row
		&& iswalkable(grid[(int)new_y][(int)data->player->x]))
		data->player->y = new_y;
}

void	key_ws(t_data *data, double cos_r, double sin_r)
{
	double	new_x;
	double	new_y;

	new_x = data->player->x + cos_r * STEP;
	new_y = data->player->y + sin_r * STEP;
	walking(data, new_x, new_y);
}

void	key_ad(t_data *data, double cos_r, double sin_r)
{
	double	new_x;
	double	new_y;

	new_x = data->player->x + sin_r * STEP;
	new_y = data->player->y + cos_r * STEP;
	walking(data, new_x, new_y);
}

void	key_leftright(t_player *player, double spd)
{
	player->radian = player->radian + spd;
	if (player->radian > 2 * PI)
		player->radian = 0;
	if (player->radian < 0)
		player->radian = 2 * PI;
}

void	set_direction_left(t_player *player)
{
	double	tmpX;
	double	tmpY;

	tmpX = player->dir_x;
	tmpY = player->dir_y;
	player->dir_x = tmpX * cos(-RSPEED) - tmpY * sin(-RSPEED);
	player->dir_x = tmpX * sin(-RSPEED) + tmpY * cos(-RSPEED);
	tmpX = player->plane_x;
	tmpY = player->plane_y;
	player->plane_x = tmpX * cos(-RSPEED) - tmpY * sin(-RSPEED);
	player->plane_y = tmpX * sin(-RSPEED) + tmpY * cos(-RSPEED);
}

void	set_direction_right(t_player *player)
{
	double	tmpX;
	double	tmpY;

	tmpX = player->dir_x;
	tmpY = player->dir_y;
	player->dir_x = tmpX * cos(RSPEED) - tmpY * sin(RSPEED);
	player->dir_y = tmpX * sin(RSPEED) + tmpY * cos(RSPEED);
	tmpX = player->plane_x;
	tmpY = player->plane_y;
	player->plane_x = tmpX * cos(RSPEED) - tmpY * sin(RSPEED);
	player->plane_y = tmpX * sin(RSPEED) + tmpY * cos(RSPEED);
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
		set_direction_left(data->player);
	}
	if (mlx_is_key_down(data->mlx, MLX_KEY_RIGHT))
	{
		key_leftright(data->player, RSPEED);
		set_direction_right(data->player);
	}	
	if (mlx_is_key_down(data->mlx, MLX_KEY_W))
		key_ws(data, cos_rad, sin_rad);
	if (mlx_is_key_down(data->mlx, MLX_KEY_S))
		key_ws(data, (cos_rad * (-1.0)), (sin_rad * (-1.0)));
	if (mlx_is_key_down(data->mlx, MLX_KEY_D))
		key_ad(data, cos_rad, (sin_rad * (-1.0)));
	if (mlx_is_key_down(data->mlx, MLX_KEY_A))
		key_ad(data, (cos_rad * -1.0), sin_rad);
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
