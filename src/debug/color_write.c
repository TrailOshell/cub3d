/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_write.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsomchan <tsomchan@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/12 17:41:12 by tsomchan          #+#    #+#             */
/*   Updated: 2025/05/12 17:41:37 by tsomchan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	write_color(char *msg, char *color)
{
	char	*str;

	set_color(color);
	str = ft_strdup(msg);
	if (str)
	{
		write(1, msg, ft_strlen(str));
		free(str);
	}
	set_color(NCL);
}

void	write_color_nl(char *msg, char *color)
{
	write_color(msg, color);
	write(1, "\n", 1);
}

void	write_color_nb(int nb, char *color)
{
	char	*tmp;

	tmp = ft_itoa(nb);
	write_color(tmp, color);
	free(tmp);
}

void	write_double_color(char *msg1, char *color1, char *msg2, char *color2)
{
	write_color(msg1, color1);
	write_color(msg2, color2);
}
