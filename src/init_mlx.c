#include "cub3D.h"

int	ft_import_image_png(mlx_t *mlx, t_tx *tx)//uh
{
	tx->no_tx = mlx_load_png(tx->no_path);
	tx->so_tx = mlx_load_png(tx->so_path);
	tx->we_tx = mlx_load_png(tx->we_path);
	tx->ea_tx = mlx_load_png(tx->ea_path);
	if (!tx->no_tx || !tx->so_tx || !tx->we_tx || !tx->ea_tx)
		return (-1);
	tx->no_img = mlx_texture_to_image(mlx, tx->no_tx);
	tx->so_img = mlx_texture_to_image(mlx, tx->so_tx);
	tx->we_img = mlx_texture_to_image(mlx, tx->we_tx);
	tx->ea_img = mlx_texture_to_image(mlx, tx->ea_tx);
	if (!tx->no_img || !tx->so_img || !tx->we_img || !tx->ea_img)
		return (-1);
	return (0);
}

void	init_mlx(t_data *data)//uh
{
	data->mlx = mlx_init(WIDTH, HEIGHT, "CUB3D", true);
	// if (!data->mlx)
		//can't init error;
	data->win = mlx_new_image(data->mlx, WIDTH, HEIGHT);
	if (mlx_image_to_window(data->mlx, data->win, 0, 0) == -1)
		return ;//can't put image error
	if (ft_import_image_png(data->mlx, data->tx) == -1)
		return ;//can't load image error
	return ;
}