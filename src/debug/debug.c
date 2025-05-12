/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsomchan <tsomchan@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/17 17:06:46 by tsomchan          #+#    #+#             */
/*   Updated: 2025/05/12 15:23:53 by tsomchan         ###   ########.fr       */
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

void	write_color(char *msg, char *color)
{
	char	*str;

	set_color(color);
	str = ft_strdup(msg);
	write(1, msg, ft_strlen(str));
	free(str);
	set_color(NCL);
}
