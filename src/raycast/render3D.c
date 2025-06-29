/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render3D.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsomchan <tsomchan@student.42bangkok.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/26 18:46:44 by paradari          #+#    #+#             */
/*   Updated: 2025/06/29 15:51:44 by tsomchan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

static void	ft_tx_scaling(t_tx_scale *tx_new, mlx_texture_t *tx, t_ray *ray)
{
	tx_new->tx = tx;
	tx_new->height = SIZE;
	tx_new->width = SIZE;
	if (ray->line_height > 0)
		tx_new->range = 1.0 * tx_new->height / ray->line_height;
	else
		tx_new->range = 1.0 * tx_new->height;
	tx_new->pos = (ray->draw_start - HEIGHT / 2 + ray->line_height / 2)
		* tx_new->range;
}

static uint32_t	set_tx_color(mlx_texture_t *tx, int pos_x, int pos_y)
{
	int			i;
	int			r;
	int			g;
	int			b;
	int			a;

	i = ((pos_y * SIZE) + pos_x) * 4;
	r = tx->pixels[i];
	g = tx->pixels[i + 1];
	b = tx->pixels[i + 2];
	a = tx->pixels[i + 3];
	return (r << 24 | g << 16 | b << 8 | a);
}

static void	ft_put_wall_to_win(t_tx_scale *tx_new_scale, t_data *data, int x)
{
	t_ray		*ray;
	int			y;
	int			tx_y;
	uint32_t	color;

	ray = data->ray;
	y = ray->draw_start;
	while (y < ray->draw_end)
	{
		tx_y = (int)tx_new_scale->pos & (tx_new_scale->height - 1);
		tx_new_scale->pos += tx_new_scale->range;
		color = set_tx_color(tx_new_scale->tx, ray->tx_x, tx_y);
		if (x >= 0 && x < WIDTH && y >= 0 && y < HEIGHT)
			mlx_put_pixel(data->win, x, y, color);
		y++;
	}
}

static void	draw_scaled_wall(t_data *data, mlx_texture_t *tx, int i)
{
	t_tx_scale	tx_new_scale;

	ft_tx_scaling(&tx_new_scale, tx, data->ray);
	ft_put_wall_to_win(&tx_new_scale, data, i);
}

void	wall_render(t_data *data, int i)
{
	if (data->ray->tx_hit == 'N')
		draw_scaled_wall(data, data->tx->so_tx, i);
	else if (data->ray->tx_hit == 'S')
		draw_scaled_wall(data, data->tx->no_tx, i);
	else if (data->ray->tx_hit == 'E')
		draw_scaled_wall(data, data->tx->we_tx, i);
	else if (data->ray->tx_hit == 'W')
		draw_scaled_wall(data, data->tx->ea_tx, i);
}
