/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsomchan <tsomchan@student.42bangkok.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/14 16:57:43 by tsomchan          #+#    #+#             */
/*   Updated: 2025/05/14 17:02:59 by tsomchan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

t_map	*init_map(t_map *map)
{
	map = malloc(sizeof(t_map));
	map->n_col = 0;
	map->n_row = 0;
	map->grid = NULL;
	return (map);
}

t_tx	*init_tx(t_tx *tx)
{
	tx = malloc(sizeof(t_tx));
	tx->no = NULL;
	tx->so = NULL;
	tx->ea = NULL;
	tx->we = NULL;
	return (tx);
}

t_rgb	*init_rgb(t_rgb *rgb)
{
	rgb = malloc(sizeof(t_rgb));
	rgb->r = -1;
	rgb->g = -1;
	rgb->b = -1;
	rgb->rgb = -1;
	return (rgb);
}

t_data	*init_data(t_data *data)
{
	if (!data)
		data = malloc(sizeof(t_data));
	data->mlx = mlx_init();
	data->map = init_map(data->map);
	data->node = NULL;
	data->tx = init_tx(data->tx);
	data->f = init_rgb(data->f);
	data->c = init_rgb(data->c);
	data->line = NULL;
	data->player = malloc(sizeof(t_player));
	data->player->x = -1;
	data->player->y = -1;
	return (data);
}
