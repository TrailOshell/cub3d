/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsomchan <tsomchan@student.42bangkok.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/16 14:30:18 by tsomchan          #+#    #+#             */
/*   Updated: 2025/05/14 17:28:05 by tsomchan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int	check_unenclosed_wall(t_data *data, int x, int y, t_map *flood)
{
	if (y == 0 && flood->grid[y][x] != '1')
		error_and_exit(data, "ERROR! Unenclosed wall (top must be wall)\n");
	else if (y == data->map->n_row - 1 && flood->grid[y][x] != '1')
		error_and_exit(data, "ERROR! Unenclosed wall (bottom must be wall)\n");
	return (0);
}

int	painting(char *c, t_data *data)
{
	if (!*c)
		error_and_exit(data, "ERROR! Unenclosed wall\n");
	if (iswalkable(*c) == 0)
		return (0);
	*c = 'P';
	return (1);
}

void	paintnear(int y, int x, t_data *data, t_map *flood)
{
	check_unenclosed_wall(data, x, y, flood);
	if (painting(&flood->grid[y + 1][x], data) == 1)
		paintnear(y + 1, x, data, flood);
	if (painting(&flood->grid[y - 1][x], data) == 1)
		paintnear(y - 1, x, data, flood);
	if (painting(&flood->grid[y][x + 1], data) == 1)
		paintnear(y, x + 1, data, flood);
	if (painting(&flood->grid[y][x - 1], data) == 1)
		paintnear(y, x - 1, data, flood);
}

int	flood_fill(t_data *data)
{
	t_map	*flood;

	if (!data || !data->map)
		return (0);
	flood = NULL;
	flood = init_map(flood);
	flood->grid = dupe_grid(data->map);
	if (!flood || !flood->grid)
		return (0);
	paintnear(data->player->y, data->player->x, data, flood);
	write_color("Map is valid (flood_filled)\n", PUR);
	write_grid(flood->grid);
	free_map(&flood);
	return (1);
}
