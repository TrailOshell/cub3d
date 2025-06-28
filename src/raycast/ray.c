/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsomchan <tsomchan@student.42bangkok.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/29 14:30:35 by paradari          #+#    #+#             */
/*   Updated: 2025/06/28 17:01:52 by tsomchan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

static void	ft_set_ray(t_ray *ray, t_player *player, int x)
{
	ray->x = (int)player->x;
	ray->y = (int)player->y;
	ray->fov = 2 * x / (float)WIDTH - 1;
	ray->dir_x = player->dir_x + (player->plane_x * ray->fov);
	ray->dir_y = player->dir_y + (player->plane_y * ray->fov);
	ray->ddist_x = fabs(1 / ray->dir_x);
	ray->ddist_y = fabs(1 / ray->dir_y);
	ray->hit = false;
	ft_init_side_dist(ray, player);
}

int	is_ray_hit(float ray_x, float ray_y, t_data *data)
{
	int	x;
	int	y;

	if (data->draw_mode == 2)
	{
		x = (int)(ray_x / MAP_SIZE);
		y = (int)(ray_y / MAP_SIZE);
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

static void	ft_dda(t_data *data)
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

void	clear_image(t_data *data)
{
	int	x;
	int	y;

	y = 0;
	while (y < HEIGHT)
	{
		x = 0;
		while (x < WIDTH)
		{
			mlx_put_pixel(data->win, x, y, 0);
			x++;
		}
		y++;
	}
}

void	ft_ray_render(t_data *data)
{
	int	x;

	x = 0;
	clear_image(data);
	draw_ceiling(data);
	draw_floor(data);
	while (x < WIDTH)
	{
		ft_set_ray(data->ray, data->player, x);
		ft_dda(data);
		ft_prep_wall_dist(data->ray);
		ft_prep_draw(data->ray);
		ft_cal_value_wallx(data->ray, data->player);
		ft_set_texture(data->ray);
		wall_render(data, x);
		x++;
	}
}
