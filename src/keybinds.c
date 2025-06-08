/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keybinds.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paradari <bellixz610@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/29 14:30:47 by paradari          #+#    #+#             */
/*   Updated: 2025/06/08 16:22:10 by paradari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int	can_walk(t_data *data, int new_x, int new_y)
{
	char	**map;

	map = data->map->grid;
	if (new_x < 0 || new_x > data->map->n_col)
		return (-1);
	if (new_y < 0 || new_y > data->map->n_row)
		return (-1);
	if (map[new_y][new_x] == '1' || map[new_y][new_x] == '2')
		return (-1);
	return (0);
}

void	key_ws(t_data *data, double cos_r, double sin_r)
{
	double	new_x;
	double	new_y;

	new_x = data->player->x + cos_r * STEP;
	new_y = data->player->y + sin_r * STEP;
	if (can_walk(data, (int)new_x, (int)new_y) == -1)
		return ;
	data->player->x = new_x;
	data->player->y = new_y;
}

void	key_ad(t_data *data, double cos_r, double sin_r)
{
	double	new_x;
	double	new_y;

	new_x = data->player->x + sin_r * STEP;
	new_y = data->player->y + cos_r * STEP;
	if (can_walk(data, (int)new_x, (int)new_y) == -1)
		return ;
	data->player->x = new_x;
	data->player->y = new_y;
}

void	key_leftright(t_player *player, double spd)
{
	player->radian = player->radian + spd;
	if (player->radian > 2 * PI)
		player->radian = 0;
	if (player->radian < 0)
		player->radian = 2 * PI;
}

void	keybinds(void *tmp)
{
	t_data	*data;
	double	cos_rad;
	double	sin_rad;

	data = (t_data *)tmp;
	cos_rad = cos(data->player->radian);
	sin_rad = sin(data->player->radian);
	if (mlx_is_key_down(data->mlx, MLX_KEY_LEFT))
		key_leftright(data->player, RSPEED * (-1.0));
	if (mlx_is_key_down(data->mlx, MLX_KEY_RIGHT))
		key_leftright(data->player, RSPEED);
	if (mlx_is_key_down(data->mlx, MLX_KEY_W))
		key_ws(data, cos_rad, sin_rad);
	if (mlx_is_key_down(data->mlx, MLX_KEY_S))
		key_ws(data, (cos_rad * (-1.0)), (sin_rad * (-1.0)));
	if (mlx_is_key_down(data->mlx, MLX_KEY_D))
		key_ad(data, cos_rad, (sin_rad * (-1.0)));
	if (mlx_is_key_down(data->mlx, MLX_KEY_A))
		key_ad(data, (cos_rad * -1.0), sin_rad);
	if (mlx_is_key_down(data->mlx, MLX_KEY_ESCAPE)
		|| mlx_is_key_down(data->mlx, MLX_KEY_Q))
		free_and_exit(data);
	relocate_player(data);//for debug
}
