/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsomchan <tsomchan@student.42bangkok.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/21 16:42:30 by tsomchan          #+#    #+#             */
/*   Updated: 2025/05/14 17:08:47 by tsomchan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int	check_map_size(t_data *data)
{
	if (data->map->n_row == 1)
		error_and_exit(data, "ERROR! Only 1 row\n");
	else if (data->map->n_row == 2)
		error_and_exit(data, "ERROR! Only 2 rows\n");
	else if (data->map->n_col == 1)
		error_and_exit(data, "ERROR! Only 1 column\n");
	else if (data->map->n_col == 2)
		error_and_exit(data, "ERROR! Only 2 columns\n");
	return (1);
}

int	check_player_pos(t_data *data, char *line, int y)
{
	int	x;

	x = 0;
	while (line[x])
	{
		if (isplayerchar(line[x]))
		{
			if (data->player->x != -1 || data->player->y != -1)
				error_and_exit(data, "ERROR! duplicated player\n");
			data->player->x = x;
			data->player->y = y;
			return (1);
		}
		x++;
	}
	return (0);
}

void	set_map(t_data *data, t_node *node)
{
	int		y;

	data->map->grid = new_grid(data->map);
	y = 0;
	while (node != NULL)
	{
		check_player_pos(data, node->line, y);
		line_copy(data->map->grid[y], node->line);
		node = node->next;
		y++;
	}
	check_map_size(data);
	if (data->player->x == -1 || data->player->y == -1)
		error_and_exit(data, "ERROR! player not found\n");
	free_node(&data->node);
}
