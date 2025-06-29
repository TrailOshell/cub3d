/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsomchan <tsomchan@student.42bangkok.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/28 00:21:10 by paradari          #+#    #+#             */
/*   Updated: 2025/06/29 16:23:34 by tsomchan         ###   ########.fr       */
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

void	set_direction_leftright(t_player *player, t_data *data, double rspeed)
{
	double	tmp_x;

	player->radian = player->radian + rspeed;
	if (player->radian > 2 * PI)
		player->radian = 0;
	else if (player->radian < 0)
		player->radian = 2 * PI;
	tmp_x = player->dir_x;
	player->dir_x = player->dir_x * cos(rspeed) - player->dir_y * sin(rspeed);
	player->dir_y = tmp_x * sin(rspeed) + player->dir_y * cos(rspeed);
	tmp_x = player->plane_x;
	player->plane_x = tmp_x * cos(rspeed) - player->plane_y * sin(rspeed);
	player->plane_y = tmp_x * sin(rspeed) + player->plane_y * cos(rspeed);
	ft_ray_render(data);
}
