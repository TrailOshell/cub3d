/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprites.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsomchan <tsomchan@student.42bangkok.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/21 16:00:41 by tsomchan          #+#    #+#             */
/*   Updated: 2025/05/06 16:39:07 by tsomchan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	*load_a_sprite(t_data *data, char *filename)
{
	void	*ptr;
	//char	*pth;
	int		size;

	size = SIZE;
	(void)filename;
	//if (SIZE == 16)
	//	pth = sl_strjoin(PTH_16, filename);
	//else if (SIZE == 32)
	//	pth = sl_strjoin(PTH_32, filename);
	//else if (SIZE == 64)
	//	pth = sl_strjoin(PTH_64, filename);
	//else if (SIZE == 128)
	//	pth = sl_strjoin(PTH_128, filename);
	//else
	//	pth = sl_strjoin(PTH_64, filename);
	//ptr = mlx_xpm_file_to_image(data->mlx, pth, &(size), &(size));
	ptr = mlx_xpm_file_to_image(data->mlx, filename, &(size), &(size));
	//free(pth);
	return (ptr);
}

void	load_sprites(t_data *data)
{
	(void)data;
}
