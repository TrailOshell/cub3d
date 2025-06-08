/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keybind_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paradari <bellixz610@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/29 15:05:10 by paradari          #+#    #+#             */
/*   Updated: 2025/06/08 16:12:52 by paradari         ###   ########.fr       */
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

	x = (int)(ray_x / 64);
	y = (int)(ray_y / 64);
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

	// ray_x = data->ray->x;
	// ray_y = data->ray->y;
	ray_x = (double)player->x * 64;
	ray_y = (double)player->y * 64;
	// ray_x = player->x;
	// ray_y = player->y;
	cos_rad = cos(start_x);
	sin_rad = sin(start_x);
	mlx_put_pixel(data->win, ray_x, ray_y, 0xFFFFFF);//for debug

	while (is_ray_hit(ray_x, ray_y, data) != 1)
	{
		ray_x += cos_rad;
		ray_y += sin_rad;
		mlx_put_pixel(data->win, ray_x, ray_y, 0xFFFFFF);//for debug
	}

	// float	distance = ft_getdistance(ray_x - player->x, ray_y - player->y);
	// int		line_height = (int)HEIGHT / distance;
	// int	draw_start = (HEIGHT / 2) - (line_height / 2);
	// int draw_end = draw_start + line_height;
	// while(draw_start < draw_end)
	// {
	// 	mlx_put_pixel(data->win, i, draw_start, 0xFFFFFF);
	// 	draw_start++;
	// }
}

void	relocate_player(t_data *data) //for debug
{
	clear_image(data);
	draw_map(data->map, data);
	draw_player(data->player->y *64 - 6, data->player->x * 64 - 6, data, 0xFFFF64FF, 12);
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
