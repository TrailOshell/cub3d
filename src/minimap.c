/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paradari <bellixz610@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/02 15:16:35 by paradari          #+#    #+#             */
/*   Updated: 2025/06/02 16:53:46 by paradari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	draw_wall(int y, int x, t_data *data)
{
	int	i;

	i = 0;
	while (i < 64)
	{
		mlx_put_pixel(data->win, x + i, y, 0x0000FF);
		i++;
	}
	i = 0;
	while (i < 64)
	{
		mlx_put_pixel(data->win, x, y + i, 0x0000FF);
		i++;
	}
	i = 0;
	while (i < 64)
	{
		mlx_put_pixel(data->win, x + i, y + 64, 0x0000FF);
		i++;
	}
	i = 0;
	while (i < 64)
	{
		mlx_put_pixel(data->win, x + 64, y + i, 0x0000FF);
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
				draw_wall(y * 64, x * 64, data);
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
	draw_player(data, data->player->x * 64, data->player->y * 64);
}