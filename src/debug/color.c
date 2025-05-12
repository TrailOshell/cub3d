/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsomchan <tsomchan@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/06 01:05:48 by tsomchan          #+#    #+#             */
/*   Updated: 2025/05/12 15:23:53 by tsomchan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	set_color(char *color)
{
	write(1, color, ft_strlen(color));
}

void	color_from_char(char c)
{
	if (c == '1')
		set_color(RED);
	else if (isplayerchar(c))
		set_color(PUR);
	else if (c == '0')
		set_color(NCL);
	else
		set_color(PUR);
}
