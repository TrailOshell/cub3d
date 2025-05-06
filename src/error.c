/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsomchan <tsomchan@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 19:52:24 by tsomchan          #+#    #+#             */
/*   Updated: 2025/05/06 21:04:22 by tsomchan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	error_and_exit(t_data *data, char *msg)
{
	if (data->map->grid != NULL)
		write_grid(data->map->grid);
	set_color(YLW);
	if (msg && *msg)
		write(1, msg, sl_strlen(msg));
	else
		write(1, "Error\n", 6);
	set_color(NCL);
	mlx_destroy_display(data->mlx);
	free_stuff(data);
	exit(0);
}
