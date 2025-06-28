/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   relocate_player.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsomchan <tsomchan@student.42bangkok.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/29 15:05:10 by paradari          #+#    #+#             */
/*   Updated: 2025/06/28 17:48:57 by tsomchan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	clear_minimap(t_data *data)//for debug
{
	int	x;
	int	y;

	y = 0;
	while (y < MAP_SIZE * data->map->n_row)
	{
		x = 0;
		while (x < MAP_SIZE * data->map->n_col)
		{
			mlx_put_pixel(data->win, x, y, 0xFF000000);
			x++;
		}
		y++;
	}
}

void	set_ray_pos(double *ray_x, double *ray_y, double x, double y)
{
	*ray_x = x;
	*ray_y = y;
}

void	draw_ray(t_player *player, t_data *data, float start_x)
{
	double	ray_x;
	double	ray_y;
	float	cos_rad;
	float	sin_rad;

	if (data->draw_mode == 3)
		set_ray_pos(&ray_x, &ray_y, player->x, player->y);
	else if (data->draw_mode == 2)
		set_ray_pos(&ray_x, &ray_y, player->x * MAP_SIZE, player->y * MAP_SIZE);
	else
		return ;
	cos_rad = cos(start_x);
	sin_rad = sin(start_x);
	if (data->draw_mode == 2)
		mlx_put_pixel(data->win, ray_x, ray_y, PLAYER_CLR);
	while (is_ray_hit(ray_x, ray_y, data) != 1)
	{
		ray_x += cos_rad;
		ray_y += sin_rad;
		if (data->draw_mode == 2)
			mlx_put_pixel(data->win, ray_x, ray_y, RAY_CLR);
	}
	if (data->draw_mode == 3)
		ft_ray_render(data);
}

void	relocate_player(t_data *data)
{
	float	fov;
	float	start_x;
	int		i;

	if (data->draw_mode == 2)
	{
		clear_minimap(data);
		draw_map(data->map, data);
		draw_player(data->player->y * MAP_SIZE - 6,
			data->player->x * MAP_SIZE - 6, data, PLAYER_CLR, 12);
		fov = PI / 3 / WIDTH;
		start_x = data->player->radian - PI / 6;
		i = 0;
		while (i < WIDTH)
		{
			draw_ray(data->player, data, start_x);
			start_x += fov;
			i++;
		}
	}
}
