/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsomchan <tsomchan@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/05 17:13:10 by tsomchan          #+#    #+#             */
/*   Updated: 2025/05/12 15:45:31 by tsomchan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

t_map	*start_map(t_map *map)
{
	map = malloc(sizeof(t_map));
	map->n_col = 0;
	map->n_row = 0;
	map->grid = NULL;
	return (map);
}

t_data	*start_data(t_data *data)
{
	if (!data)
		data = malloc(sizeof(t_data));
	data->mlx = mlx_init();
	data->map = start_map(data->map);
	data->node = NULL;
	data->player = malloc(sizeof(t_player));
	return (data);
}

int	read_map(char **argv, t_data *data)
{
	int		fd;

	fd = open(argv[1], O_RDONLY);
	if (fd < 0)
		error_and_exit(data, "ERROR! fd error\n");
	if (ft_strrncmp(argv[1], ".cub", 4))
		error_and_exit(data, "ERROR! only .cub file is allowed\n");
	else if (ft_strrncmp(argv[1], "/.cub", 5) == 0 || argv[1][0] == '.')
		error_and_exit(data, "ERROR! hidden file not allowed\n");
	get_next_row(data, fd);
	write_elements(data);
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
	data = start_data(data);
	if (argc != 2)
		error_and_exit(data, "ERROR! Input arguments not equal 2\n");
	if (!data->mlx)
		return (0);
	read_map(argv, data);
	data->win = mlx_new_window(data->mlx, data->map->n_col * SIZE, data->map->n_row * SIZE, "cub3D");
	if (!data->win)
		return (free(data->mlx), 1);
	mlx_loop(data->mlx);
	return (0);
}
