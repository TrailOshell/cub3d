/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paradari <bellixz610@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/02 14:17:26 by paradari          #+#    #+#             */
/*   Updated: 2025/06/02 14:17:26 by paradari         ###   ########.fr       */
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
	tx_new_scale->pos = (ray->draw_start - HEIGHT / 2 + ray->line_height / 2) * tx_new_scale->range;
}

uint32_t	set_tx_color(mlx_texture_t *tx, int pos_x, int pos_y)
{
	uint8_t	*tx_color;
	int			i;

	i = (pos_y * 64 - pos_x + 63) * 4;
	tx_color = &tx->pixels[i];
	return ((tx_color[0] << 24) | (tx_color[1] << 16) | (tx_color[2] << 8) | tx_color[3]);
}

void	ft_put_wall_to_win(t_tx_scale *tx_new_scale, t_data *data, int x)
{
	t_ray	*ray;
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

void	wall_render(t_data *data, int i)
{
	t_tx_scale	tx_new_scale;
	t_ray		*ray;
	t_tx		*tx;

	ray = data->ray;
	tx = data->tx;
	if (ray->tx_hit == 'N')
	{
		ft_tx_scaling(&tx_new_scale, tx->no_tx, ray);
		ft_put_wall_to_win(&tx_new_scale, data, i);
	}
	else if (ray->tx_hit == 'S')
	{
		ft_tx_scaling(&tx_new_scale, tx->so_tx, ray);
		ft_put_wall_to_win(&tx_new_scale, data, i);
	}
	else if (ray->tx_hit == 'E')
	{
		ft_tx_scaling(&tx_new_scale, tx->ea_tx, ray);
		ft_put_wall_to_win(&tx_new_scale, data, i);
	}
	else if (ray->tx_hit == 'W')
	{
		ft_tx_scaling(&tx_new_scale, tx->we_tx, ray);
		ft_put_wall_to_win(&tx_new_scale, data, i);
	}
}