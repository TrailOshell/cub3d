/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsomchan <tsomchan@student.42bangkok.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/19 21:38:27 by tsomchan          #+#    #+#             */
/*   Updated: 2025/05/06 16:46:18 by tsomchan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	free_map(t_map **map)
{
	int	i;

	if ((*map)->grid)
	{
		i = 0;
		while ((*map)->grid[i])
			free((*map)->grid[i++]);
		free((*map)->grid);
	}
	free(*map);
	*map = NULL;
}

void	free_node(t_node **node)
{
	t_node	*tmp;

	while (*node)
	{
		tmp = (*node)->next;
		free((*node)->line);
		free(*node);
		*node = tmp;
	}
}

void	free_stuff(t_data *data)
{
	if (data)
	{
		if (data->mlx)
			free(data->mlx);
		if (data->player)
			free(data->player);
		if (data->map)
			free_map(&data->map);
		if (data->node != NULL)
			free_node(&data->node);
		free(data);
	}
}
