/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keybind_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paradari <bellixz610@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/29 15:05:10 by paradari          #+#    #+#             */
/*   Updated: 2025/06/10 16:18:40 by paradari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	clear_image(t_data *data)//for debug
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

int	is_ray_hit(float ray_x, float ray_y, t_data *data)
{
	int	x;
	int	y;

	if (data->draw_mode == 2)
	{
		x = (int)(ray_x / 64);
		y = (int)(ray_y / 64);
	}
	else if(data->draw_mode == 3)
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

double	ft_getdistance(double x, double y)
{
	return (sqrt(x * x + y * y));
}

double rescale(double x1, double y1, double x2, double y2, t_data *data)
{
	double	distance;

	float dx = x2 - x1;
	float dy = y2 - y1;
	float angle = atan2(dy, dx) - data->player->radian;
	distance = ft_getdistance(dx, dy) * cos(angle);
	return distance;
}

void	draw_ray(t_player *player, t_data *data, float start_x, int i)
{
	double	ray_x;
	double	ray_y;
	float	cos_rad;
	float	sin_rad;

	(void)i;
	cos_rad = cos(start_x);
	sin_rad = sin(start_x);
	if (data->draw_mode == 3)
	{
		ray_x = player->x;
		ray_y = player->y;
	}
	else if (data->draw_mode == 2)
	{
		ray_x = (double)player->x * 64;
		ray_y = (double)player->y * 64;
		mlx_put_pixel(data->win, ray_x, ray_y, RAY_CLR);//for debug
	}
	else
		return ;

	while (is_ray_hit(ray_x, ray_y, data) != 1)
	{
		ray_x += cos_rad;
		ray_y += sin_rad;
		if (data->draw_mode == 2)
			mlx_put_pixel(data->win, ray_x, ray_y, RAY_CLR);//for debug
	}

	if (data->draw_mode == 3)
	{
		float	distance = ft_getdistance(ray_x - player->x, ray_y - player->y);
		if (distance <= 0)
			distance = 0.0001;
		float	line_height = (int)HEIGHT / distance;
		float	draw_start = HEIGHT / 2 - line_height;
		if (draw_start <= 0)
			draw_start = 0;
		float	draw_end = draw_start + line_height;
		printf("lineh = %f\tdraw_start = %f\tdraw_end = %f\n", line_height, draw_start, draw_end);
		while(draw_start < draw_end)
		{
			mlx_put_pixel(data->win, i, draw_start, RAY_CLR);
			draw_start++;
		}
	}
}

void	relocate_player(t_data *data) //for debug
{
	clear_image(data);
	if (data->draw_mode == 2)
	{
		draw_map(data->map, data);
		draw_player(data->player->y *64 - 6, data->player->x * 64 - 6, data, PLAYER_CLR, 12);
	}
	float	fov = PI / 3 / WIDTH;
	float	start_x = data->player->radian - PI / 6;
	int	i = 0;
	while (i < WIDTH)
	{
		draw_ray(data->player, data, start_x, i);
		start_x += fov;
		i++;
	}
}
