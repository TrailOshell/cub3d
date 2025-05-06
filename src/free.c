/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsomchan <tsomchan@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/19 21:38:27 by tsomchan          #+#    #+#             */
/*   Updated: 2025/05/06 21:02:05 by tsomchan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	free_if_alloc(void *mem)
{
	if (mem)
		free(mem);

}

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
		free_if_alloc(data->mlx);
		free_if_alloc(data->player);
		if (data->map)
			free_map(&data->map);
		if (data->node != NULL)
			free_node(&data->node);
		free(data);
	}
}
