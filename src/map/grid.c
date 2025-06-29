/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   grid.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsomchan <tsomchan@student.42bangkok.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/19 22:19:20 by tsomchan          #+#    #+#             */
/*   Updated: 2025/06/12 15:38:49 by tsomchan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

char	**new_grid(t_map *map)
{
	char	**grid;
	int		row;

	grid = malloc(sizeof(char **) * (map->n_row + 1));
	row = 0;
	while (row < map->n_row)
	{
		grid[row] = malloc(sizeof(char *) * (map->n_col + 1));
		grid[row][0] = '\0';
		row++;
	}
	grid[row] = NULL;
	return (grid);
}

char	**dupe_grid(t_map *map)
{
	char	**dupe;
	int		y;

	dupe = new_grid(map);
	y = 0;
	while (map->grid[y])
	{
		line_copy(dupe[y], map->grid[y]);
		y++;
	}
	dupe[y] = NULL;
	return (dupe);
}
