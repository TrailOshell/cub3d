/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_texture.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsomchan <tsomchan@student.42bangkok.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/09 15:03:37 by tsomchan          #+#    #+#             */
/*   Updated: 2025/05/09 15:51:10 by tsomchan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"



void	set_rgb(t_data *data, t_rgb *rgb, char *str)
{
	int	i;

	i = 2;
	(void)data;
	(void)i;
	(void)rgb;
	(void)str;
}
	//while (str[i])
	// r
		//rgb->r == RED;
	// g
		//rgb->r == GREEN;
	// b
		//rgb->r == BLUE;
	//else
	//	error_and_exit("ERROR! Wrong element input (Invalid color input)");

//void	set_texture(t_data *data, t_tx *tx, char *str)
void	set_texture(t_data *data, void *tx, char *str)
{
	(void)data;
	(void)tx;
	(void)str;
}
	//while (str[i])
	// path
		//tx->NO == RED;
	// g
		//rgb->SO == GREEN;
	// b
		//rgb->EA == BLUE;
	//else
	//	error_and_exit("ERROR! Wrong element input (Invalid color input)");

//	set elements which are NSEW textures and colors for celing and floor
void	set_elements(t_data *data, int fd)
{
	char	*line;

	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		if (cub_strrncmp(line, "NO ", 3) == 0)
			set_texture(data, data->tx->no, line);
		else if (cub_strrncmp(line, "SO ", 3) == 0)
			set_texture(data, data->tx->so, line);
		else if (cub_strrncmp(line, "EA ", 3) == 0)
			set_texture(data, data->tx->ea, line);
		else if (cub_strrncmp(line, "WE ", 3) == 0)
			set_texture(data, data->tx->we, line);
		else if (cub_strrncmp(line, "C ", 2))
			set_rgb(data, data->c, line);
		else if (cub_strrncmp(line, "F ", 2))
			set_rgb(data, data->f, line);
		free(line);
	}
}
