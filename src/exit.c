/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsomchan <tsomchan@student.42bangkok.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 19:52:24 by tsomchan          #+#    #+#             */
/*   Updated: 2025/06/29 16:52:54 by tsomchan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	error_and_exit(t_data *data, char *msg)
{
	if (data->map->grid != NULL)
		write_grid(data->map->grid);
	set_color(YLW);
	if (msg && *msg)
		write(1, msg, ft_strlen(msg));
	set_color(NCL);
	if (data)
		free_stuff(data);
	exit(0);
}

void	free_and_exit(void	*data)
{
	free_stuff(data);
	exit (0);
}
