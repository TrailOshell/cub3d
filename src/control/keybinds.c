/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keybinds.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsomchan <tsomchan@student.42bangkok.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/29 14:30:47 by paradari          #+#    #+#             */
/*   Updated: 2025/06/29 16:24:43 by tsomchan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	check_key_movement(t_data *data)
{
	double	cos_rad;
	double	sin_rad;

	cos_rad = cos(data->player->radian);
	sin_rad = sin(data->player->radian);
	if (mlx_is_key_down(data->mlx, MLX_KEY_LEFT))
		set_direction_leftright(data->player, data, -RSPEED);
	if (mlx_is_key_down(data->mlx, MLX_KEY_RIGHT))
		set_direction_leftright(data->player, data, RSPEED);
	if (mlx_is_key_down(data->mlx, MLX_KEY_W))
		key_ws(data, cos_rad, sin_rad);
	if (mlx_is_key_down(data->mlx, MLX_KEY_S))
		key_ws(data, (cos_rad * (-1.0)), (sin_rad * (-1.0)));
	if (mlx_is_key_down(data->mlx, MLX_KEY_D))
		key_ad(data, cos_rad, (sin_rad * (-1.0)));
	if (mlx_is_key_down(data->mlx, MLX_KEY_A))
		key_ad(data, (cos_rad * -1.0), sin_rad);
	ft_ray_render(data);
}

void	keybinds(void *tmp)
{
	t_data	*data;

	data = (t_data *)tmp;
	check_key_movement(data);
	if (mlx_is_key_down(data->mlx, MLX_KEY_ESCAPE)
		|| mlx_is_key_down(data->mlx, MLX_KEY_Q))
		free_and_exit(data);
	if (mlx_is_key_down(data->mlx, MLX_KEY_2))
		data->draw_mode = 2;
	else if (mlx_is_key_down(data->mlx, MLX_KEY_3))
		data->draw_mode = 3;
	relocate_player(data);
}
