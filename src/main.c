/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsomchan <tsomchan@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/05 17:13:10 by tsomchan          #+#    #+#             */
/*   Updated: 2025/05/16 18:12:29 by tsomchan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int	read_map(char **argv, t_data *data)
{
	int		fd;

	if (ft_strrncmp(argv[1], ".cub", 4))
		error_and_exit(data, "ERROR! only .cub file is allowed\n");
	else if (ft_strrncmp(argv[1], "/.cub", 5) == 0 || argv[1][0] == '.')
		error_and_exit(data, "ERROR! hidden file not allowed\n");
	fd = open(argv[1], O_RDONLY);
	if (fd < 0)
		error_and_exit(data, "ERROR! fd error\n");
	get_next_row(data, fd);
	write_elements(data);
	if (!data->tx->no || !data->tx->so || !data->tx->ea || !data->tx->we
		|| data->c->rgb == -1 || data->f->rgb == -1)
		error_and_exit(data, "ERROR! missing elements input\n");
	else if (data->node == NULL)
		error_and_exit(data, "ERROR! Empty map\n");
	set_map(data, data->node);
	flood_fill(data);
	write_color("Initial map\n", GRN);
	write_grid(data->map->grid);
	return (1);
}

int	main(int argc, char **argv)
{
	t_data	*data;

	data = NULL;
	data = init_data(data);
	if (argc != 2)
		error_and_exit(data, "ERROR! Input arguments not equal 2\n");
	if (!data->mlx)
		return (0);
	read_map(argv, data);
	data->win = mlx_new_window(data->mlx,
			data->map->n_col * SIZE, data->map->n_row * SIZE, "cub3D");
	if (!data->win)
		return (free(data->mlx), 1);
	mlx_hook(data->win, KEYPRESS, (1L << 0), &on_keypress, data);
	mlx_hook(data->win, DESTROYNOTIFY, (1L << 2), &game_exit, data);
	mlx_loop(data->mlx);
	return (0);
}

	//mlx_destroy_display(data->mlx);
	//free_stuff(data);
	//write_color("End of test\n", YLW);