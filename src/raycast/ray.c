/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paradari <bellixz610@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/29 14:30:35 by paradari          #+#    #+#             */
/*   Updated: 2025/06/27 21:59:09 by paradari         ###   ########.fr       */
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

static int	is_ray_hit(float ray_x, float ray_y, t_data *data)
{
	int	x;
	int	y;

	if (data->draw_mode == 2)
	{
		x = (int)(ray_x / 64);
		y = (int)(ray_y / 64);
	}
	else if (data->draw_mode == 3)
	{
		x = (int)ray_x;
		y = (int)ray_y;
	}
	else
		return (0);
	if (x < 0 || x >= data->map->n_col || y < 0 || y >= data->map->n_row)
		return (1);
	if (data->map->grid[y][x] == '1' || data->map->grid[y][x] == '2')
		return (1);
	return (0);
}

void	ft_set_ray(t_ray *ray, t_player *player, int x)
{
	ray->x = (int)player->x;
	ray->y = (int)player->y;
	ray->fov = 2 * x / (float)WIDTH - 1;
	ray->dir_x = player->dir_x + (player->plane_x * ray->fov);
	ray->dir_y = player->dir_y + (player->plane_y * ray->fov);
	ray->ddist_x = fabs(1 / ray->dir_x);
	ray->ddist_y = fabs(1 / ray->dir_y);
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
		ray->wallX = player->y + ray->prep_wall_dist * ray->dir_y;
	else
		ray->wallX = player->x + ray->prep_wall_dist * ray->dir_x;
	ray->wallX -= floor(ray->wallX);
	ray->tx_X = (int)(ray->wallX * (double)SIZE);
	if (ray->side == 0 && ray->dir_x > 0)
		ray->tx_X = SIZE - ray->tx_X - 1;
	if (ray->side == 1 && ray->dir_y < 0)
		ray->tx_X = SIZE - ray->tx_X - 1;
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
		if (ray->dir_y >= 0)
			ray->tx_hit = 'N';
		else
			ray->tx_hit = 'S';
	}
}

void	ft_ray_render(t_data *data)
{
	int x;

	x = 0;
	clear_image(data);
	draw_ceiling(data);
	draw_floor(data);
	while (x < WIDTH)
	{
		ft_set_ray(data->ray, data->player, x);
		ft_dda(data);
		ft_prepWallDist(data->ray);
		ft_prepDraw(data->ray);
		ft_cal_value_wallx(data->ray, data->player);
		ft_set_texture(data->ray);
		render_three_dimension(data, x);
		x++;
	}
}
