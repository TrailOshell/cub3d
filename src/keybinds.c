/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keybinds.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paradari <paradari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/29 14:30:47 by paradari          #+#    #+#             */
/*   Updated: 2025/06/05 11:09:06 by paradari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

// int	can_walk(t_data *data, double new_x, double new_y)
// {
// 	if (new_x < 0 || new_x > data->map->n_col)
// 		return (-1);
// 	else if (new_y < 0 || new_y > data->map->n_row)
// 		return (-1);
// 	return (0);
// }

void	clear_image(t_data *data)
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
	return (-1);
}

// void	draw_ray(t_data *data)
// {
// 	float	ray_x;
// 	float	ray_y;
// 	float	cos_rad;
// 	float	sin_rad;


// 	ray_x = data->player->x;
// 	ray_y = data->player->y;
// 	cos_rad = cos(data->player->radian);
// 	sin_rad = sin(data->player->radian);
// 	while (is_ray_hit(ray_x, ray_y, data) == -1)
// 	{
// 		draw_square(ray_x, ray_y, data, 0xFFFFFF, 10);
// 		ray_x += cos_rad;
// 		ray_y += sin_rad;
// 	}
// }

float	ft_cal_dist(float x, float y)
{
	return sqrt(x * x + y * y);
}

void	draw_ray(t_player *player, t_data *data, float start_x, int i)
{
	float	ray_x;
	float	ray_y;
	float	cos_rad;
	float	sin_rad;

	ray_x = player->x * 64 + 32;
	ray_y = player->y * 64 + 32;
	cos_rad = cos(start_x);
	sin_rad = sin(start_x);
	mlx_put_pixel(data->win, ray_x, ray_y, 0xFF0000); // Draw player position for debug
	
	while (is_ray_hit(ray_x, ray_y, data) == -1)
	{
		ray_x += cos_rad;
		ray_y += sin_rad;
		mlx_put_pixel(data->win, ray_x, ray_y, 0xFFFFFF);
	}

	// float	distance = ft_cal_dist(ray_x - player->x, ray_y - player->y);
	// float	line_height = (64 / distance) * (WIDTH / 2);
	// int	start_y = (HEIGHT - line_height) / 2;
	// int end = start_y + line_height;
	(void)i;
	// while (start_y < end)
	// {
	// 	printf("line_height = %f\nstart_y = % d\ni = %d\n", line_height, start_y, i);
	// 	mlx_put_pixel(data->win, i, start_y, 255);
	// 	start_y++;
	// }
}

void	relocate_player(t_data *data)
{
	clear_image(data);
	draw_map(data->map, data);
	// draw_square(data->player->y, data->player->x, data, 0x00FFFF,64);

	float	fraction = PI / 3 / WIDTH;
	float	start_x = data->player->radian - PI / 6;
	int	i = 0;
	while (i < WIDTH)
	{
		draw_ray(data->player, data, start_x, i);
		start_x += fraction;
		i++;
	}
}

void	keybinds(void *tmp)
{
	t_data	*data;
	float	cos_rad;
	float	sin_rad;

	data = (t_data *)tmp;
	cos_rad = cos(data->player->radian);
	sin_rad = sin(data->player->radian);
	if (mlx_is_key_down(data->mlx, MLX_KEY_LEFT))
		data->player->radian -= RSPEED;
	if (mlx_is_key_down(data->mlx, MLX_KEY_RIGHT))
		data->player->radian += RSPEED;
	if (data->player->radian > 2 * PI)
		data->player->radian = 0;
	if (data->player->radian < 0)
		data->player->radian = 2 * PI;

	if (mlx_is_key_down(data->mlx, MLX_KEY_W))
	{
		data->player->x += cos_rad * STEP;
		data->player->y += sin_rad * STEP;
	}
	if (mlx_is_key_down(data->mlx, MLX_KEY_S))
	{
		data->player->x -= cos_rad * STEP;
		data->player->y -= sin_rad * STEP;
	}
	if (mlx_is_key_down(data->mlx, MLX_KEY_D))
	{
		data->player->x -= sin_rad * STEP;
		data->player->y += cos_rad * STEP;
	}
	if (mlx_is_key_down(data->mlx, MLX_KEY_A))
	{
		data->player->x += sin_rad * STEP;
		data->player->y -= cos_rad * STEP;
	}
	relocate_player(data);
	// ft_ray(data);
	if (mlx_is_key_down(data->mlx, MLX_KEY_ESCAPE)
		|| mlx_is_key_down(data->mlx, MLX_KEY_Q))
		free_and_exit(data);
}
