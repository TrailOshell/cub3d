/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculate_wall.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paradari <bellixz610@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/26 18:47:04 by paradari          #+#    #+#             */
/*   Updated: 2025/06/08 14:24:52 by paradari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	find_wall_dist(t_player *player, t_ray *ray)
{
	if (ray->side == 0)
		ray->wall_dist = player->y;
	else
		ray->wall_dist = player->x;
}

void	ft_line_height_wall(t_ray *ray, int *draw_start, int *draw_end)
{
	ray->line_height = (int)(HEIGHT / ray->wall_dist);
	*draw_start = -ray->line_height / 2 + HEIGHT / 2;
	if (*draw_start < 0)
		*draw_start = 0;
	*draw_end = ray->line_height / 2 + HEIGHT / 2;
	if (*draw_end >= HEIGHT)
		*draw_end = HEIGHT - 1;
}

void	get_wall_size(t_ray *ray, t_player *player)
{
	if (ray->side == 0)
		ray->wall_size = player->y + ray->wall_dist * ray->dir_y;
	else
		ray->wall_size = player->x + ray->wall_dist * ray->dir_x;
	ray->wall_size -= floor(ray->wall_size);
	ray->tx_pos_x = (int)(ray->wall_size * 64);
	if (ray->side == 0 && ray->dir_x > 0)
		ray->tx_pos_x = 64 - ray->tx_pos_x - 1;
	if (ray->side == 1 && ray->dir_y < 0)
		ray->tx_pos_x = 64 - ray->tx_pos_x - 1;
}

void	ft_set_texture(t_ray *ray)
{
	if (ray->side == 0)
	{
		if (ray->dir_x > 0)
			ray->tx_hit = 'W';
		else
			ray->tx_hit = 'E';
	}
	else
	{
		if (ray->dir_y > 0)
			ray->tx_hit = 'N';
		else
			ray->tx_hit = 'S';
	}
}

void	calculate_wall(t_data *data)
{
	find_wall_dist(data->player, data->ray);
	ft_line_height_wall(data->ray, &data->ray->draw_start, &data->ray->draw_end);
	get_wall_size(data->ray, data->player);
	ft_set_texture(data->ray);
}