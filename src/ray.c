/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paradari <bellixz610@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/29 14:30:35 by paradari          #+#    #+#             */
/*   Updated: 2025/06/02 16:42:27 by paradari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	set_ray_dir(t_ray *ray, t_player *player)
{
	if (ray->dir_x < 0)
	{
		ray->step_x = -1;
		ray->side_dx = (player->x - ray->x) * ray->dx;
	}
	else
	{
		ray->step_x = 1;
		ray->side_dx = (1 + ray->x - player->x) * ray->dx;
	}
	if (ray->dir_y < 0)
	{
		ray->step_y = -1;
		ray->side_dy = (player->y - ray->y) * ray->dy;
	}
	else
	{
		ray->step_y = 1;
		ray->side_dy = (1 + ray->y - player->y) * ray->dy;
	}
}

void	init_ray(t_player *player, t_ray *ray, int i)
{
	ray->x = (int)player->x;
	ray->y = (int)player->y;
	ray->pov = 2 * i / (double)WIDTH - 1;
	ray->dir_x = player->dir_x + (player->plane_x * ray->pov);
	ray->dir_y = player->dir_y + (player->plane_y * ray->pov);
	ray->dx = fabs(1 / ray->dir_x);
	ray->dy = fabs(1 / ray->dir_y);
	ray->hit = 0;
	set_ray_dir(ray, player);
}

void	ft_dda(t_map *map, t_ray *ray)
{
	while (ray->hit == 0)
	{
		if (ray->side_dx < ray->side_dy)
		{
			ray->side_dx += ray->dx;
			ray->x += ray->step_x;
			ray->side = 0;
		}
		else
		{
			ray->side_dy += ray->dy;
			ray->y += ray->step_y;
			ray->side = 1;
		}
		if (ray->y <= 0 || ray->y >= map->n_col || ray->x <= 0
			|| ray->x >= map->n_row)
			return ;
		if (map->grid[ray->y][ray->x] == '1')
			ray->hit = 1;
	}
}

void	ft_ray(t_data *data)
{
	int	i;

	i = 0;
	while (i < WIDTH)
	{
		init_ray(data->player, data->ray, i);
		ft_dda(data->map, data->ray);
		calculate_wall(data);
		// renderTD(data, i);
		i++;
	}
	return ;
}
