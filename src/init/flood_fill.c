/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsomchan <tsomchan@student.42bangkok.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/16 14:30:18 by tsomchan          #+#    #+#             */
/*   Updated: 2025/05/14 16:57:13 by tsomchan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int	painting(char *c, t_map *map)
{
	(void)map;
	if (iswalkable(*c) == 0)
		return (0);
	*c = 'P';
	return (1);
}

void	paintnear(int y, int x, t_map *map)
{
	if (painting(&map->grid[y + 1][x], map) == 1)
		paintnear(y + 1, x, map);
	if (painting(&map->grid[y - 1][x], map) == 1)
		paintnear(y - 1, x, map);
	if (painting(&map->grid[y][x + 1], map) == 1)
		paintnear(y, x + 1, map);
	if (painting(&map->grid[y][x - 1], map) == 1)
		paintnear(y, x - 1, map);
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
	paintnear(data->player->y, data->player->x, flood);
	write_color("Map is valid (flood_filled)\n", PUR);
	write_grid(flood->grid);
	free_map(&flood);
	return (1);
}
