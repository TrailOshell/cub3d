/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paradari <paradari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/29 14:30:35 by paradari          #+#    #+#             */
/*   Updated: 2025/06/26 10:52:56 by paradari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	ft_init_sideDist(t_ray *ray, t_player *player)
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

void	ft_set_ray(t_ray *ray, t_player *player, int x)
{
	ray->x = (int)player->x;
	ray->y = (int)player->y;
	ray->fov = 2 * x / (float)WIDTH - 1;
	ray->dir_x = player->dir_x + (player->plane_x * ray->fov);
	ray->dir_y = player->dir_y + (player->plane_y * ray->fov);
	ray->ddist_x = abs(1 / ray->dir_x);
	ray->ddist_y = abs(1 / ray->dir_y);
	ray->hit = false;
	ft_init_sideDist(ray, player);
}

void	ft_dda(t_data *data)
{
	t_ray	*ray;

	ray = data->ray;
	while (ray->hit == false)
	{
		if (ray->side_dx < ray->side_dy)
		{
			ray->side_dx += ray->ddist_x;
			ray->x += ray->step_x;
			ray->side = 0;
		}
		else
		{
			ray->side_dy += ray->ddist_y;
			ray->y += ray->step_y;
			ray->side = 1;
		}
		if (is_ray_hit(ray->x, ray->y, data) == 1)
			ray->hit = true;
	}
}

void	ft_prepWallDist(t_ray *ray)
{
	if (ray->side == 0)
		ray->prep_wall_dist = ray->side_dx - ray->ddist_x;
	else
		ray->prep_wall_dist = ray->side_dy - ray->ddist_y;
}

void	ft_prepDraw(t_ray *ray)
{
	ray->line_height = (int)(HEIGHT / prep_wall_dist);
	ray->draw_start = -ray->line_height / 2 + HEIGHT / 2;
	if (ray->draw_start < 0)
		ray->draw_start = 0;
	ray->draw_end = line_height / 2 + HEIGHT / 2;
	if (ray->draw_end >= HEIGHT)
		ray->draw_end = HEIGHT - 1;
}

void	ft_cal_value_wallx(t_ray *ray, t_player *player)
{
	if (ray->side == 0)
		ray->wallX = player->y + ray->prep_wall_dist * ray->dir_y;
}

void	ft_ray_render(t_data *data)
{
	int x;

	x = 0;
	while (x < WIDTH)
	{
		ft_set_ray(data->ray, data->player, x);
		ft_dda(data->ray, data->map);
		ft_prepWallDist(data->ray);
		ft_prepDraw(data->ray);
		ft_cal_value_wallx(data->ray, data->player);
		x++;
	}
}
