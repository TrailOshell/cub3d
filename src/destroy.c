#include "../includes/cub3d.h"

void	ft_clear_img(t_data *game)
{
	if (game->north_image)
		mlx_delete_image(game->mlx, game->north_image);
	if (game->south_image)
		mlx_delete_image(game->mlx, game->south_image);
	if (game->west_image)
		mlx_delete_image(game->mlx, game->west_image);
	if (game->east_image)
		mlx_delete_image(game->mlx, game->east_image);
	if (game->p1)
		mlx_delete_image(game->mlx, game->p1);
	if (game->north_texture)
		mlx_delete_texture(game->north_texture);
	if (game->south_texture)
		mlx_delete_texture(game->south_texture);
	if (game->west_texture)
		mlx_delete_texture(game->west_texture);
	if (game->east_texture)
		mlx_delete_texture(game->east_texture);
	if (game->p1_texture)
		mlx_delete_texture(game->p1_texture);
}

void	ft_clear_mlx(t_data *game)
{
	ft_clear_img(game);
	if (game->window)
		mlx_destroy_window(game->mlx, game->window);
	// game->player = NULL;
	// game->exit = NULL;
	if (game->mlx)
	{
		mlx_destroy_display(game->mlx);
		free (game->mlx);
	}
}

int	ft_destroy_2(t_data *game)
{
	ft_free_map(game->map);
	ft_free_map(game->tmp);
	free(game);
	exit(0);
}

int	ft_destroy(t_data *game)
{
	// ft_free_map(game->map);
	// ft_free_map(game->tmp);
	ft_clear_mlx(game);
	// free(game);
	exit(0);
}
