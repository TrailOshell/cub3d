/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsomchan <tsomchan@student.42bangkok.co    +#+  +:+       +#+        */ /*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/19 21:38:27 by tsomchan          #+#    #+#             */
/*   Updated: 2025/05/13 00:17:49 by tsomchan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	free_if_alloc(void *mem)
{
	if (mem)
		free(mem);
}

void	free_map(t_map *map)
{
	int	i;

	if (map->grid)
	{
		i = 0;
		while (map->grid[i])
			free(map->grid[i++]);
		free(map->grid);
	}
	free(map);
	map = NULL;
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

void	free_tx(t_tx *tx)
{
	free_if_alloc(tx->no);
	free_if_alloc(tx->so);
	free_if_alloc(tx->ea);
	free_if_alloc(tx->we);
	free(tx);
}

void	free_stuff(t_data *data)
{
	if (data)
	{
		free_if_alloc(data->mlx);
		free_if_alloc(data->player);
		if (data->map)
			free_map(data->map);
		if (data->node != NULL)
			free_node(&data->node);
		if (data->tx)
			free_tx(data->tx);
		// if (data->ray)
		// 	free_ray(data->ray);
		free_if_alloc(data->line);
		free_if_alloc(data->f);
		free_if_alloc(data->c);
		free(data);
	}
}
