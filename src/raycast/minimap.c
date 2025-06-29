/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsomchan <tsomchan@student.42bangkok.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/28 01:02:15 by paradari          #+#    #+#             */
/*   Updated: 2025/06/28 17:54:33 by tsomchan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	draw_square(int y, int x, t_data *data, int color)//for debug
{
	int	i;

	i = 0;
	x = x * MAP_SIZE;
	y = y * MAP_SIZE;
	while (i < MAP_SIZE)
		mlx_put_pixel(data->win, x + i++, y, color);
	i = 0;
	while (i < MAP_SIZE)
		mlx_put_pixel(data->win, x, y + i++, color);
	i = 0;
	while (i < MAP_SIZE)
		mlx_put_pixel(data->win, x + i++, y + MAP_SIZE, color);
	i = 0;
	while (i < MAP_SIZE)
		mlx_put_pixel(data->win, x + MAP_SIZE, y + i++, color);
}

void	draw_player(int y, int x, t_data *data, int color)//for debug
{
	int	i;

	i = 0;
	while (i < 12)
		mlx_put_pixel(data->win, x + i++, y, color);
	i = 0;
	while (i < 12)
		mlx_put_pixel(data->win, x, y + i++, color);
	i = 0;
	while (i < 12)
		mlx_put_pixel(data->win, x + i++, y + 12, color);
	i = 0;
	while (i < 12)
		mlx_put_pixel(data->win, x + 12, y + i++, color);
}

void	draw_map(t_map *map, t_data *data)//for debug
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (map->grid[y])
	{
		x = 0;
		while (map->grid[y][x])
		{
			if (map->grid[y][x] == '1')
				draw_square(y, x, data, MAP_WALL_CLR);
			x++;
		}
		y++;
	}
}

void	minimap(t_data *data)//for debug
{
	t_map	*map;

	map = data->map;
	draw_map(map, data);
	draw_square(data->player->y, data->player->x, data, WALL_CLR);
}
