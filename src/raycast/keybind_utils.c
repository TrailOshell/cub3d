/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keybind_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsomchan <tsomchan@student.42bangkok.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/29 15:05:10 by paradari          #+#    #+#             */
/*   Updated: 2025/06/12 17:27:47 by tsomchan         ###   ########.fr       */
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

double	ft_getdistance(double x, double y)
{
	double	x2;
	double	y2;
	double	xy2;

	x2 = x * x;
	y2 = y * y;
	xy2 = x2 + y2;
	printf(GRN"sqrt = "NCL"%.2f\t", sqrt(x2 + y2));
	printf(YLW"x*x + y*y = "NCL"\t%.2f\t", x2 + y2);
	printf(PUR"xy2 = "NCL"%.2f\t", xy2);
	printf(CYN"x*x = "NCL"%.2f\t", x2);
	printf(CYN"y*y = "NCL"%.2f\n", y2);
	return (sqrt((x * x) + (y * y)));
}

//	use like this --> rescale(x2 - x1, y2 - y1, data);
double	rescale(double dx, double dy, t_data *data)
{
	double	distance;
	float	angle;

	angle = atan2(dy, dx) - data->player->radian;
	distance = ft_getdistance(dx, dy) * cos(angle);
	return (distance);
}

//	use like this...
//	draw_three_dimension(data, ray_x - player->x, ray_y - player->y, i)
void	draw_three_dimension(t_data *data, double dx, double dy, int i)
{
	float	distance;
	float	line_height;
	float	draw_start;
	float	draw_end;

	distance = ft_getdistance(dx, dy);
	if (distance <= 0)
		distance = 0.0001;
	line_height = HEIGHT / distance;
	draw_start = HEIGHT / 2 - line_height;
	if (draw_start <= 0)
		draw_start = 0;
	draw_end = draw_start + line_height;
	while (draw_start < draw_end)
		mlx_put_pixel(data->win, i, draw_start++, RAY_CLR);
}

void	set_ray_pos(double *ray_x, double *ray_y, double x, double y)
{
	*ray_x = x;
	*ray_y = y;
}

void	draw_ray(t_player *player, t_data *data, float start_x, int i)
{
	double	ray_x;
	double	ray_y;
	float	cos_rad;
	float	sin_rad;

	if (data->draw_mode == 3)
		set_ray_pos(&ray_x, &ray_y, player->x, player->y);
	else if (data->draw_mode == 2)
		set_ray_pos(&ray_x, &ray_y, player->x * 64, player->y * 64);
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
		draw_three_dimension(data, ray_x - player->x, ray_y - player->y, i);
}

//for debug
void	relocate_player(t_data *data)
{
	float	fov;
	float	start_x;
	int		i;

	clear_image(data);
	if (data->draw_mode == 2)
	{
		draw_map(data->map, data);
		draw_player(data->player->y * 64 - 6, data->player->x * 64 - 6,
			data, PLAYER_CLR, 12);
	}
	fov = PI / 3 / WIDTH;
	start_x = data->player->radian - PI / 6;
	i = 0;
	while (i < WIDTH)
	{
		draw_ray(data->player, data, start_x, i);
		start_x += fov;
		i++;
	}
}
