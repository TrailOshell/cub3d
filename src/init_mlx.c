/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_mlx.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paradari <bellixz610@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/26 18:44:36 by paradari          #+#    #+#             */
/*   Updated: 2025/05/26 18:55:29 by paradari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int	ft_import_image_png(mlx_t *mlx, t_tx *tx)
{
	tx->no_tx = mlx_load_png(tx->no);
	tx->so_tx = mlx_load_png(tx->so);
	tx->we_tx = mlx_load_png(tx->we);
	tx->ea_tx = mlx_load_png(tx->ea);
	if (!tx->no_tx || !tx->so_tx || !tx->we_tx || !tx->ea_tx)
		return (-1);
	tx->no_img = mlx_texture_to_image(mlx, tx->no_tx);
	tx->so_img = mlx_texture_to_image(mlx, tx->so_tx);
	tx->we_img = mlx_texture_to_image(mlx, tx->we_tx);
	tx->ea_img = mlx_texture_to_image(mlx, tx->ea_tx);
	if (!tx->no_img || !tx->so_img || !tx->we_img || !tx->ea_img)
		return (-1);
	return (0);
}

void	init_mlx(t_data *data)
{
	data->mlx = mlx_init(WIDTH, HEIGHT, "CUB3D", true);
	if (!data->mlx)
		error_and_exit(data, "Error: can't initialize mlx\n");
	data->win = mlx_new_image(data->mlx, WIDTH, HEIGHT);
	if (!data->win)
		error_and_exit(data, "Error: can't create new window image\n");
	if (mlx_image_to_window(data->mlx, data->win, 0, 0) == -1)
		error_and_exit(data, "Error: can't put image to window\n");
	// if (ft_import_image_png(data->mlx, data->tx) == -1)
	// 	error_and_exit(data, "Error: can't load textures\n");
	return ;
}