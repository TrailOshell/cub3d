/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paradari <bellixz610@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/28 00:21:10 by paradari          #+#    #+#             */
/*   Updated: 2025/06/28 00:21:25 by paradari         ###   ########.fr       */
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