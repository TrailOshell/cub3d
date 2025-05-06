/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsomchan <tsomchan@student.42bangkok.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/21 16:42:30 by tsomchan          #+#    #+#             */
/*   Updated: 2025/05/06 16:48:14 by tsomchan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	set_map(t_data *data, t_node *node)
{
	int		y;

	data->map->grid = new_map(data->map);
	y = 0;
	while (node != NULL)
	{
		line_copy(data->map->grid[y], node->line);
		node = node->next;
		y++;
	}
	check_map_by_lines(data, data->map->grid);
	check_map_size(data);
	check_map_enclosed_walls(data, data->map->grid);
	free_node(&data->node);
}
