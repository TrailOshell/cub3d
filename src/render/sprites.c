/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprites.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsomchan <tsomchan@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/21 16:00:41 by tsomchan          #+#    #+#             */
/*   Updated: 2025/05/06 20:56:52 by tsomchan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	*load_a_sprite(t_data *data, char *filename)
{
	void	*ptr;
	int		size;

	size = SIZE;
	ptr = mlx_xpm_file_to_image(data->mlx, filename, &(size), &(size));
	return (ptr);
}
