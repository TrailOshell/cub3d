/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsomchan <tsomchan@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/05 17:13:10 by tsomchan          #+#    #+#             */
/*   Updated: 2025/06/28 11:00:38 by tsomchan         ###   ########.fr       */
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

int	main(int argc, char **argv)
{
	t_data	*data;

	data = NULL;
	data = init_data(data);
	if (argc != 2)
		error_and_exit(data, "ERROR! Input arguments not equal 2\n");
	read_map(argv, data);
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

//Valgrind cub3D

// HEAP SUMMARY:
// ==2645196==     in use at exit: 317,955 bytes in 3,107 blocks
// ==2645196==   total heap usage: 87,973 allocs, 84,866 frees, 35,288,496 bytes allocated
// ==2645196== 
// ==2645196== LEAK SUMMARY:
// ==2645196==    definitely lost: 0 bytes in 1 blocks
// ==2645196==    indirectly lost: 0 bytes in 0 blocks
// ==2645196==      possibly lost: 0 bytes in 0 blocks
// ==2645196==    still reachable: 317,899 bytes in 3,104 blocks
// ==2645196==         suppressed: 56 bytes in 2 blocks
// ==2645196== Rerun with --leak-check=full to see details of leaked memory
// ==2645196== 
// ==2645196== Use --track-origins=yes to see where uninitialised values come from
// ==2645196== For lists of detected and suppressed errors, rerun with: -s
// ==2645196== ERROR SUMMARY: 409354 errors from 14 contexts (suppressed: 0 from 0)

// int	main()
// {
// 	mlx_t *mlx;
	
// 	mlx = mlx_init(WIDTH, HEIGHT, "Test leak", true);
// 	mlx_terminate(mlx);
// 	return (0);
// }

//Valgrind MLX
// ==2532420== HEAP SUMMARY:
// ==2532420==     in use at exit: 317,955 bytes in 3,107 blocks
// ==2532420==   total heap usage: 73,445 allocs, 70,338 frees, 20,358,366 bytes allocated
// ==2532420== 
// ==2532420== LEAK SUMMARY:
// ==2532420==    definitely lost: 0 bytes in 1 blocks
// ==2532420==    indirectly lost: 0 bytes in 0 blocks
// ==2532420==      possibly lost: 0 bytes in 0 blocks
// ==2532420==    still reachable: 317,899 bytes in 3,104 blocks
// ==2532420==         suppressed: 56 bytes in 2 blocks
// ==2532420== Rerun with --leak-check=full to see details of leaked memory
// ==2532420== 
// ==2532420== For lists of detected and suppressed errors, rerun with: -s
// ==2532420== ERROR SUMMARY: 0 errors from 0 contexts (suppressed: 0 from 0)