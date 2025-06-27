/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paradari <bellixz610@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/05 17:13:10 by tsomchan          #+#    #+#             */
/*   Updated: 2025/06/27 15:59:01 by paradari         ###   ########.fr       */
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

void	free_and_exit(void	*data)
{
	free_stuff(data);
	exit (0);
}

void	printmap(char **grid)
{
	int	i;

	i = 0;
	while (grid[i])
		printf("%s\n", grid[i++]);
}

int	main(int argc, char **argv)
{
	t_data	*data;

	data = NULL;
	data = init_data(data);
	if (argc != 2)
		error_and_exit(data, "ERROR! Input arguments not equal 2\n");
	read_map(argv, data);
	printmap(data->map->grid);
	init_mlx(data);
	init_player(data->player);
	data->ray = malloc(sizeof(t_ray));
	if (!data->ray)
		error_and_exit(data, "Error: can't initialize ray\n");
	ft_bzero(data->ray, sizeof(t_ray));
	write_color("Raycasting...\n", GRN);
	minimap(data);
	ft_ray_render(data);
	mlx_loop_hook(data->mlx, keybinds, data);
	mlx_close_hook(data->mlx, free_and_exit, data);
	mlx_loop(data->mlx);
	return (0);
}

	//mlx_destroy_display(data->mlx);
	//free_stuff(data);
	//write_color("End of test\n", YLW);