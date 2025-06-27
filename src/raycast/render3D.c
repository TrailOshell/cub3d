/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render3D.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paradari <bellixz610@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/26 18:46:44 by paradari          #+#    #+#             */
/*   Updated: 2025/06/27 16:23:59 by paradari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	draw_ceiling(t_data *data, int i)
{
	uint32_t	floor_color;
	uint32_t	ceiling_color;
	int			x;

	floor_color = data->c->rgba;
	ceiling_color = data->f->rgba;
	x = 0;
	while (x < HEIGHT)
	{
		if (i >= 0 && i < WIDTH && x >= 0 && x < HEIGHT)
			mlx_put_pixel(data->win, i, x, floor_color);
		else
		{
			mlx_put_pixel(data->win, i, x, ceiling_color);
		}
		x++;
	}
}

void	draw_floor(t_data *data, int i)
{
	uint32_t	color;
	int			x;

	color = data->f->rgba;
	x = HEIGHT / 2;
	while (x < HEIGHT)
	{
		if (i >= 0 && i < WIDTH && x >= 0 && x < HEIGHT)
			mlx_put_pixel(data->win, i, x, color);
		x++;
	}
}

void	render_three_dimension(t_data *data, int i)
{
	draw_ceiling(data, i);
	draw_floor(data, i);
	// wall_render(data, i);
}
