/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keybind_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paradari <bellixz610@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/29 15:05:10 by paradari          #+#    #+#             */
/*   Updated: 2025/05/29 15:05:25 by paradari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int	can_walk(data->map, new_x, new_y)
{
	if (cant)
	{
		if (W)
		{
			data->player->x -= data->player->dir_x * STEP;
			data->player->y -= data->player->dir_y * STEP;
			return ;
		}
		if (S)
		{
			data->player->x += data->player->dir_x * STEP;
			data->player->y += data->player->dir_y * STEP;
			return ;
		}
		if (A)
		{
			data->player->x -= data->player->dir_x * STEP;
			data->player->y += data->player->dir_y * STEP;
			return ;
		}
		if (D)
		{
			data->player->x += data->player->dir_x * STEP;
			data->player->y -= data->player->dir_y * STEP;
			return ;
		}
	}
}