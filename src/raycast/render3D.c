/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render3D.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paradari <bellixz610@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/26 18:46:44 by paradari          #+#    #+#             */
/*   Updated: 2025/06/27 21:01:26 by paradari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

// void	draw_ceiling(t_data *data)
// {
// 	int	x;
// 	int	y;

// 	x = 0;
// 	while (x < WIDTH)
// 	{
// 		y = 0;
// 		while (y < HEIGHT / 2)
// 		{
// 			mlx_put_pixel(data->win, x, y, data->c->rgba);
// 			y++;
// 		}
// 		x++;
// 	}
// }

// void	draw_floor(t_data *data, int x)
// {
	// uint32_t	color;
	// int			y;
	// (void)x;
	// (void)data;

	// color = data->f->rgba;
	// y = HEIGHT / 2;
	// while (x < HEIGHT)
	// {
	// 	if (i >= 0 && i < WIDTH && x >= 0 && x < HEIGHT)
	// 		mlx_put_pixel(data->win, i, x, color);
	// 	x++;
	// }
// }

void	render_three_dimension(t_data *data, int i)
{
	// (void)data;
	// (void)i;
	// draw_ceiling(data);
	// draw_floor(data, i);
	wall_render(data, i);
}
