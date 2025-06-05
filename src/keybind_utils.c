/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keybind_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paradari <bellixz610@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/29 15:05:10 by paradari          #+#    #+#             */
/*   Updated: 2025/06/05 15:16:35 by paradari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	clear_image(t_data *data)//for debug
{
	for(int y = 0; y < HEIGHT; y++)
		for(int x = 0; x < WIDTH; x++)
			mlx_put_pixel(data->win, x, y, 0);

}

int	is_ray_hit(float ray_x, float ray_y, t_data *data)
{
	int	x;
	int	y;

	x = (int)((ray_x) / 64);
	y = (int)((ray_y) / 64);
	if (x < 0 || x >= data->map->n_col || y < 0 || y >= data->map->n_row)
		return (1);
	if (data->map->grid[y][x] == '1')
		return (1);
	return (0);
}

void	draw_ray(t_player *player, t_data *data, float start_x, int i)
{
	float	ray_x;
	float	ray_y;
	float	cos_rad;
	float	sin_rad;

	(void)i;
	ray_x = player->x * 64 + 32;
	ray_y = player->y * 64 + 32;
	cos_rad = cos(start_x);
	sin_rad = sin(start_x);
	mlx_put_pixel(data->win, ray_x, ray_y, 0xFFFFFF);//for debug

	while (is_ray_hit(ray_x, ray_y, data) != 1)
	{
		ray_x += cos_rad;
		ray_y += sin_rad;
		mlx_put_pixel(data->win, ray_x, ray_y, 0xFFFFFF);//for debug
	}
}

void	relocate_player(t_data *data) //for debug
{
	clear_image(data);
	draw_map(data->map, data);
	draw_player(data->player->y *64 + 20, data->player->x * 64 + 20, data, 255, 12);
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