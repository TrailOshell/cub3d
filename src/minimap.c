/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paradari <paradari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/02 15:16:35 by paradari          #+#    #+#             */
/*   Updated: 2025/06/05 01:36:49 by paradari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	draw_square(int y, int x, t_data *data, int color, int size)
{
	int	i;

	i = 0;
	x = x * size;
	y = y * size;
	while (i < size)
	{
		mlx_put_pixel(data->win, x + i, y, color);
		i++;
	}
	i = 0;
	while (i < size)
	{
		mlx_put_pixel(data->win, x, y + i, color);
		i++;
	}
	i = 0;
	while (i < size)
	{
		mlx_put_pixel(data->win, x + i, y + size, color);
		i++;
	}
	i = 0;
	while (i < size)
	{
		mlx_put_pixel(data->win, x + size, y + i, color);
		i++;
	}
}

void	draw_player(t_data *data, int x, int y)
{
	int	i;

	i = 0;
	while (i < 64)
	{
		mlx_put_pixel(data->win, x + i, y, 0x00FFFF);
		i++;
	}
	i = 0;
	while (i < 64)
	{
		mlx_put_pixel(data->win, x, y + i, 0x00FFFF);
		i++;
	}
	i = 0;
	while (i < 64)
	{
		mlx_put_pixel(data->win, x + i, y + 64, 0x00FFFF);
		i++;
	}
	i = 0;
	while (i < 64)
	{
		mlx_put_pixel(data->win, x + 64, y + i, 0x00FFFF);
		i++;
	}
}

void	clear_player(t_data *data, int x, int y)
{
	int	i;

	i = 0;
	while (i < 64)
	{
		mlx_put_pixel(data->win, x + i, y, 0x00);
		i++;
	}
	i = 0;
	while (i < 64)
	{
		mlx_put_pixel(data->win, x, y + i, 0x00);
		i++;
	}
	i = 0;
	while (i < 64)
	{
		mlx_put_pixel(data->win, x + i, y + 64, 0x00);
		i++;
	}
	i = 0;
	while (i < 64)
	{
		mlx_put_pixel(data->win, x + 64, y + i, 0x00);
		i++;
	}
}

void	draw_map(t_map *map, t_data *data)
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
				draw_square(y, x, data, 0x0000FF, 64);
			x++;
		}
		y++;
	}
}

void	minimap(t_data *data)
{
	t_map	*map;

	map = data->map;
	draw_map(map, data);
	draw_square(data->player->y, data->player->x, data, 0x00FFFF, 64);
	
}