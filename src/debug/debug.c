/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsomchan <tsomchan@student.42bangkok.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/17 17:06:46 by tsomchan          #+#    #+#             */
/*   Updated: 2025/05/06 16:45:59 by tsomchan         ###   ########.fr       */
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
	set_color(RESET);
}

void	write_value(char *msg, int int_val)
{
	char	*str;

	set_color(BLUE);
	str = sl_strdup(msg);
	write(1, msg, sl_strlen(str));
	free(str);
	write(1, ": ", 2);
	set_color(RESET);
	str = sl_itoa(int_val);
	write(1, str, sl_strlen(str));
	free(str);
}

void	write_color(char *msg, char *color)
{
	char	*str;

	set_color(color);
	str = sl_strdup(msg);
	write(1, msg, sl_strlen(str));
	free(str);
	set_color(RESET);
}

void	write_color_exit(t_data *data, char *msg, char *color)
{
	write_color(msg, color);
	game_exit(data);
}
