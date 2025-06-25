/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsomchan <tsomchan@student.42bangkok.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/02 15:16:35 by paradari          #+#    #+#             */
/*   Updated: 2025/06/12 15:37:10 by tsomchan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	draw_square(int y, int x, t_data *data, int color, int size)//for debug
{
	int	i;

	i = 0;
	x = x * size;
	y = y * size;
	while (i < size)
		mlx_put_pixel(data->win, x + i++, y, color);
	i = 0;
	while (i < size)
		mlx_put_pixel(data->win, x, y + i++, color);
	i = 0;
	while (i < size)
		mlx_put_pixel(data->win, x + i++, y + size, color);
	i = 0;
	while (i < size)
		mlx_put_pixel(data->win, x + size, y + i++, color);
}

void	draw_player(int y, int x, t_data *data, int color, int size)//for debug
{
	int	i;

	i = 0;
	while (i < size)
		mlx_put_pixel(data->win, x + i++, y, color);
	i = 0;
	while (i < size)
		mlx_put_pixel(data->win, x, y + i++, color);
	i = 0;
	while (i < size)
		mlx_put_pixel(data->win, x + i++, y + size, color);
	i = 0;
	while (i < size)
		mlx_put_pixel(data->win, x + size, y + i++, color);
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
				draw_square(y, x, data, MAP_WALL_CLR, 64);
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
	draw_square(data->player->y, data->player->x, data, WALL_CLR, 64);
}
