/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render3D.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsomchan <tsomchan@student.42bangkok.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/26 18:46:44 by paradari          #+#    #+#             */
/*   Updated: 2025/05/29 15:49:14 by tsomchan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	draw_ceiling(t_data *data, int i, int draw_start)
{
	uint32_t	floor_color;
	uint32_t	ceiling_color;
	int			x;

	(void)draw_start;
	floor_color = data->c->rgb;
	ceiling_color = data->f->rgb;
	x = 0;
	while (x < HEIGHT)
	{
		if (i >= 0 && i < WIDTH && x >= 0 && x < HEIGHT)
			mlx_put_pixel(data->win, i, x, floor_color);
		else
			mlx_put_pixel(data->win, i, x, ceiling_color);
		x++;
	}
}

void	draw_floor(t_data *data, int i, int draw_end)
{
	uint32_t	color;
	int			x;

	(void)draw_end;
	color = 65303;
	x = HEIGHT/2;
	while (x < HEIGHT)
	{
		if (i >= 0 && i < WIDTH && x >= 0 && x < HEIGHT)
			mlx_put_pixel(data->win, i, x, color);
		x++;
	}
}

void	renderTD(t_data *data, int i)
{
	draw_ceiling(data, i, data->ray->draw_start);
	draw_floor(data, i, data->ray->draw_end);
	// render_wall()
}
