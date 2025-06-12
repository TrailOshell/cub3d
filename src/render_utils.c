/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsomchan <tsomchan@student.42bangkok.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/02 14:17:26 by paradari          #+#    #+#             */
/*   Updated: 2025/06/12 16:05:00 by tsomchan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	ft_tx_scaling(t_tx_scale *tx_new_scale, mlx_texture_t *tx, t_ray *ray)
{
	tx_new_scale->tx = tx;
	tx_new_scale->height = 64;
	tx_new_scale->width = 64;
	if (ray->line_height > 0)
		tx_new_scale->range = 1.0 * tx_new_scale->height / ray->line_height;
	else
		tx_new_scale->range = 1.0 * tx_new_scale->height;
	tx_new_scale->pos = (ray->draw_start - HEIGHT / 2 + ray->line_height / 2)
		* tx_new_scale->range;
}

uint32_t	set_tx_color(mlx_texture_t *tx, int pos_x, int pos_y)
{
	uint8_t		*tx_color;
	int			i;

	i = (pos_y * 64 - pos_x + 63) * 4;
	tx_color = &tx->pixels[i];
	return ((tx_color[0] << 24)
		| (tx_color[1] << 16)
		| (tx_color[2] << 8)
		| tx_color[3]);
}

void	ft_put_wall_to_win(t_tx_scale *tx_new_scale, t_data *data, int x)
{
	t_ray		*ray;
	int			y;
	int			tx_pos_y;
	uint32_t	color;

	ray = data->ray;
	y = ray->draw_start;
	while (y < ray->draw_end)
	{
		tx_pos_y = (int)tx_new_scale->pos & (tx_new_scale->height - 1);
		tx_new_scale->pos += tx_new_scale->range;
		color = set_tx_color(tx_new_scale->tx, ray->tx_pos_x, tx_pos_y);
		if (x >= 0 && x < WIDTH && y >= 0 && y < HEIGHT)
			mlx_put_pixel(data->win, x, y, color);
		y++;
	}
}

void	draw_scaled_wall(t_data *data, mlx_texture_t *tx, int i)
{
	t_tx_scale	tx_new_scale;

	ft_tx_scaling(&tx_new_scale, tx, data->ray);
	ft_put_wall_to_win(&tx_new_scale, data, i);
}

void	wall_render(t_data *data, int i)
{
	if (data->ray->tx_hit == 'N')
		draw_scaled_wall(data, data->tx->no_tx, i);
	else if (data->ray->tx_hit == 'S')
		draw_scaled_wall(data, data->tx->so_tx, i);
	else if (data->ray->tx_hit == 'E')
		draw_scaled_wall(data, data->tx->ea_tx, i);
	else if (data->ray->tx_hit == 'W')
		draw_scaled_wall(data, data->tx->we_tx, i);
}
