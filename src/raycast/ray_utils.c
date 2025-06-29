/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsomchan <tsomchan@student.42bangkok.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/28 00:38:03 by paradari          #+#    #+#             */
/*   Updated: 2025/06/28 17:46:40 by tsomchan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	ft_init_side_dist(t_ray *ray, t_player *player)
{
	if (ray->dir_x < 0)
	{
		ray->step_x = -1;
		ray->side_dx = (player->x - ray->x) * ray->ddist_x;
	}
	else
	{
		ray->step_x = 1;
		ray->side_dx = (ray->x + 1.0 - player->x) * ray->ddist_x;
	}
	if (ray->dir_y < 0)
	{
		ray->step_y = -1;
		ray->side_dy = (player->y - ray->y) * ray->ddist_y;
	}
	else
	{
		ray->step_y = 1;
		ray->side_dy = (ray->y + 1.0 - player->y) * ray->ddist_y;
	}
}

void	ft_prep_wall_dist(t_ray *ray)
{
	if (ray->side == 0)
		ray->prep_wall_dist = ray->side_dx - ray->ddist_x;
	else
		ray->prep_wall_dist = ray->side_dy - ray->ddist_y;
}

void	ft_prep_draw(t_ray *ray)
{
	ray->line_height = (int)(HEIGHT / ray->prep_wall_dist);
	ray->draw_start = -ray->line_height / 2 + HEIGHT / 2;
	if (ray->draw_start < 0)
		ray->draw_start = 0;
	ray->draw_end = ray->line_height / 2 + HEIGHT / 2;
	if (ray->draw_end >= HEIGHT)
		ray->draw_end = HEIGHT - 1;
}

void	ft_cal_value_wallx(t_ray *ray, t_player *player)
{
	if (ray->side == 0)
		ray->wallx = player->y + ray->prep_wall_dist * ray->dir_y;
	else
		ray->wallx = player->x + ray->prep_wall_dist * ray->dir_x;
	ray->wallx -= floor(ray->wallx);
	ray->tx_x = (int)(ray->wallx * (double)SIZE);
	if ((ray->side == 0 && ray->dir_x < 0)
		|| (ray->side == 1 && ray->dir_y > 0))
		ray->tx_x = SIZE - ray->tx_x - 1;
}

void	ft_set_texture(t_ray *ray)
{
	if (ray->side == 0)
	{
		if (ray->dir_x > 0)
			ray->tx_hit = 'E';
		else
			ray->tx_hit = 'W';
	}
	else
	{
		if (ray->dir_y >= 0)
			ray->tx_hit = 'S';
		else
			ray->tx_hit = 'N';
	}
}
