#include "cub3D.h"

void	find_wall_dist(t_map *map, t_ray *ray)
{
	if (ray->side == 0)
		ray->wall_dist = (ray->x - data->player->x + (1 - ray->step_x) / 2) / ray->dir_x;
	else
		ray->wall_dist = (ray->y - data->player->y + (1 - ray->step_y) / 2) / ray->dir_y;
}

void	ft_line_height_wall(t_ray *ray, int *draw_start, int *draw_end)
{
	ray->line_height = (int)(HEIGHT / ray->wall_dist);
	*draw_start = -ray->line_height / 2 + HEIGHT / 2;
	if (*draw_start < 0)
		*draw_start = 0;
	*draw_end = ray->line_height / 2 + HEIGHT / 2;
	if (*draw_end >= HEIGHT)
		*draw_end = HEIGHT - 1;
}

void	get_wall_size(t_ray *ray, t_player *player)
{
	if (ray->side == 0)
		ray->wall_size = player->y + ray->wall_dist * ray->dir_y;
	else
		ray->wall_size = player->x + ray->wall_dist * ray->dir_x;
	ray->wall_size -= floor(ray->wall_size);
	ray->tx_size = (int)(ray->wall_size * 64);
	if (ray->side == 0 && ray->dir_x > 0)
		ray->tx_size = 64 - ray->tx_size - 1;
	if (ray->side == 1 && ray->dir_y < 0)
		ray->tx_size = 64 - ray->tx_size - 1;
}

void	ft_set_texture(t_ray *ray)
{
	if (ray->side == 0)
	{
		if (ray->dir_x > 0)
			ray->tx = W;
		else
			ray->tx = E;
	}
	else
	{
		if (ray->dir_y > 0)
			ray->tx = N;
		else
			ray->tx = S;
	}
}

void	calculate_wall(t_data *data)
{
	find_wall_dist(data->map, data->ray);
	ft_line_height_wall(data->ray, &data->ray->draw_start, &data->ray->draw_end);
	get_wall_size(data->ray, data->player);
	ft_set_texture(data->ray);
}