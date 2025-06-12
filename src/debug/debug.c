/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsomchan <tsomchan@student.42bangkok.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/17 17:06:46 by tsomchan          #+#    #+#             */
/*   Updated: 2025/06/12 15:39:02 by tsomchan         ###   ########.fr       */
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

void	write_itoa(int nb)
{
	char	*tmp;

	tmp = ft_itoa(nb);
	write(1, tmp, ft_strlen(tmp));
	free(tmp);
}

//	write info about the color inputed from .cub
void	write_color_input(t_rgb *rgb)
{
	write(1, "  ", 2);
	write(1, "\033[48;2;", 8);
	write_itoa(rgb->r);
	write(1, ";", 1);
	write_itoa(rgb->g);
	write(1, ";", 1);
	write_itoa(rgb->b);
	write(1, "m", 1);
	write(1, "     ", 5);
	write(1, "\033[0;49m", 8);
	write(1, "  ", 2);
	write_color_nb(rgb->r, RED);
	write_color(",", NULL);
	write_color_nb(rgb->g, GRN);
	write_color(",", NULL);
	write_color_nb(rgb->b, CYN);
	write(1, "\t", 1);
	write_color_nb(rgb->rgb, CYN);
	write_color("\n", NULL);
}

//	write textures and color that has been set
void	write_elements(t_data *data)
{
	write_double_color("NO\t", BLU, data->tx->no, CYN);
	if (!data->tx->no)
		write_color("No input", YLW);
	write_color("\n", NULL);
	write_double_color("SO\t", BLU, data->tx->so, CYN);
	if (!data->tx->so)
		write_color("No input", YLW);
	write_color("\n", NULL);
	write_double_color("EA\t", BLU, data->tx->ea, CYN);
	if (!data->tx->ea)
		write_color("No input", YLW);
	write_color("\n", NULL);
	write_double_color("WE\t", BLU, data->tx->we, CYN);
	if (!data->tx->we)
		write_color("No input", YLW);
	write_color("\n", NULL);
	write_color("Floor\t", BLU);
	write_color_input(data->f);
	write_color("Ceiling\t", BLU);
	write_color_input(data->c);
}
