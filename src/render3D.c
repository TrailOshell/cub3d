/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render3D.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paradari <paradari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/26 18:46:44 by paradari          #+#    #+#             */
/*   Updated: 2025/05/28 12:28:48 by paradari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	draw_ceiling(t_data *data, int i, int draw_strart)
{
	uint32_t	color;
	int			x;

	color = //add color
	x = 0;
	while (x < draw_strart)
	{
		if (i >= 0 && i < WIDTH && x >= 0 && x < HEIGHT)
			mlx_put_pixel(data->window, i, x, color);
		x++;
	}
}

void	draw_floor(t_data *data, int i, int draw_end)
{
	uint32_t	color;
	int			x;

	color = //add color
	x = draw_end;
	while (x < HEIGHT)
	{
		if (i >= 0 && i < WIDTH && x >= 0 && x < HEIGHT)
			mlx_put_pixel(data->window, i, x, color);
		x++;
	}
}

void	render3D(t_data *data, int	i)
{
	draw_ceiling(data, i, data->ray->draw_strart);
	draw_floor(data, i, data->ray->draw_end);
	render_wall()
}
