/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsomchan <tsomchan@student.42bangkok.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/06 01:05:48 by tsomchan          #+#    #+#             */
/*   Updated: 2025/05/06 16:19:55 by tsomchan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	set_color(char *color)
{
	write(1, color, sl_strlen(color));
}

void	color_from_char(char c)
{
	if (c == '1')
		set_color(RED);
	else if (c == 'P')
		set_color(MAGENTA);
	else if (c == 'C')
		set_color(YELLOW);
	else if (c == 'E')
		set_color(GREEN);
	else if (c == 't')
		set_color(BLUE);
	else if (c == 'T')
		set_color(CYAN);
	else if (c == '0')
		set_color(RESET);
	else
		set_color(MAGENTA);
}
