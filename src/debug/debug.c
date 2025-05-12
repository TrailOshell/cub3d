/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsomchan <tsomchan@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/17 17:06:46 by tsomchan          #+#    #+#             */
/*   Updated: 2025/05/12 17:39:57 by tsomchan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	write_grid(char **grid)
{
	int		row;
	int		col;
	char	c;

	row = 0;
	while (grid[row])
	{
		col = 0;
		while (grid[row][col])
		{
			c = grid[row][col++];
			color_from_char(c);
			write(1, &c, 1);
		}
		write(1, "\n", 1);
		row++;
	}
	set_color(NCL);
}

//	write textures and color that has been set
void	write_elements(t_data *data)
{
	if (data->tx->no)
		write_double_color("NO\t", BLU, data->tx->no, CYN);
	if (data->tx->so)
		write_double_color("SO\t", BLU, data->tx->so, CYN);
	if (data->tx->ea)
		write_double_color("EA\t", BLU, data->tx->ea, CYN);
	if (data->tx->we)
		write_double_color("WE\t", BLU, data->tx->we, CYN);
	write_color("Floor\t", BLU);
	write_color_nb(data->f, CYN);
	write_color("\n", NULL);
	write_color("Ceiling\t", BLU);
	write_color_nb(data->c, CYN);
	write_color("\n", NULL);
}
/*
	write_color("Textures (NSEW)\n", YLW);
	write_color("Color (Floor and Ceiling)\n", YLW);
*/