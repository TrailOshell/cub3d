/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paradari <paradari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/26 18:44:51 by paradari          #+#    #+#             */
/*   Updated: 2025/06/26 10:52:58 by paradari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	init_player(t_player *player)
{
	player->dir_x = 0;
	player->dir_y = 0;
	if (player->direction == 'N')
	{
		player->radian = PI / 2;
		player->dir_y = -1;
	}
	else if (player->direction == 'S')
	{
		player->radian = 3 * PI / 2;
		player->dir_y = 1;
	}
	else if (player->direction == 'E')
	{
		player->radian = 0;
		player->dir_x = 1;
	}
	else if (player->direction == 'W')
	{
		player->radian = PI;
		player->dir_x = -1;
	}
	player->plane_x = player->dir_y * (-0.66);
	player->plane_y = player->dir_x * 0.66;
}
