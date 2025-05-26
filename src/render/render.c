/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsomchan <tsomchan@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/21 15:44:50 by tsomchan          #+#    #+#             */
/*   Updated: 2025/05/06 20:56:51 by tsomchan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	render_tile(t_data *data, int x, int y)
{
	(void)data;
	(void)x;
	(void)y;
}
/*
	if (data->map->grid[y][x] == '1')
		mlx_put_image_to_window(data->mlx, data->win, \
			data->sprite, x * SIZE, y * SIZE);
*/

void	render_map(t_data *data)
{
	int	x;
	int	y;

	y = 0;
	while (data->map->grid[y])
	{
		x = 0;
		while (data->map->grid[y][x])
		{
			render_tile(data, x, y);
			x++;
		}
		y++;
	}
}
