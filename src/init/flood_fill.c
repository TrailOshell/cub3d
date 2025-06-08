/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsomchan <tsomchan@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/16 14:30:18 by tsomchan          #+#    #+#             */
/*   Updated: 2025/05/16 19:15:28y tsomchan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	err_map(t_data *data, t_map *map, char *msg)
{
	free_map(map);
	error_and_exit(data, msg);
}

int	check_unenclosed_wall(t_data *data, int x, int y, t_map *flood)
{
	if (y == 0 && flood->grid[y][x] != '1')
		err_map(data, flood, "ERROR! Unenclosed wall (top must be wall)\n");
	else if (y == data->map->n_row - 1 && flood->grid[y][x] != '1')
		err_map(data, flood, "ERROR! Unenclosed wall (bottom must be wall)\n");
	return (0);
}

int	painting(char *c, t_data *data, t_map *flood)
{
	if (!*c)
		err_map(data, flood, "ERROR! Unenclosed wall\n");
	if (iswalkable(*c) == 0)
		return (0);
	*c = 'P';
	return (1);
}

void	paintnear(int y, int x, t_data *data, t_map *flood)
{
	check_unenclosed_wall(data, x, y, flood);
	if (painting(&flood->grid[y + 1][x], data, flood) == 1)
		paintnear(y + 1, x, data, flood);
	if (painting(&flood->grid[y - 1][x], data, flood) == 1)
		paintnear(y - 1, x, data, flood);
	if (painting(&flood->grid[y][x + 1], data, flood) == 1)
		paintnear(y, x + 1, data, flood);
	if (painting(&flood->grid[y][x - 1], data, flood) == 1)
		paintnear(y, x - 1, data, flood);
}

void	flood_outer_wall(t_data *data, t_map	*flood)
{
	int		x;
	int		y;
	t_map	*map;

	map = data->map;

	x = 0;
	y = 0;
	while (y < map->n_row)
	{
		while (x < map->n_col)
		{

			if (flood->grid[y][x] == '0' || ft_isspace(flood->grid[y][x]) 
				|| flood->grid[y][x] == 0)
			{
				flood->grid[y][x] = '2';
				map->grid[y][x] = flood->grid[y][x];
			}
			x++;
		}
		y++;
		x = 0;
	}
}

int	flood_fill(t_data *data)
{
	t_map	*flood;

	if (!data || !data->map)
		return (0);
	flood = NULL;
	flood = init_map(flood);
	if (!flood)
		return (0);
	flood->grid = dupe_grid(data->map);
	if (!flood->grid)
	{
		free(flood);
		return (0);
	}
	paintnear(data->player->y, data->player->x, data, flood);
	flood_outer_wall(data, flood);
	write_color("Map is valid (flood_filled)\n", PUR);
	write_grid(flood->grid);
	free_map(flood);
	return (1);
}
