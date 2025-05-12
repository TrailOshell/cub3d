/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_texture.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsomchan <tsomchan@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/09 15:03:37 by tsomchan          #+#    #+#             */
/*   Updated: 2025/05/12 15:04:25 by tsomchan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int	get_int_color(t_data *data, char *str)
{
	int	color;
	int	i;

	color = 0;
	i = 0;
	while (ft_isalpha(str[i]) && str[i] != ',')
	{
		color += (str[i] - '0');
		i++;
		if (ft_isalpha(str[i + 1]))
			color *= 10;
	}
	if (color > 255)
		error_and_exit(data, "ERROR! wrong color input");
	return (color);
}

//	set the red green and blue value to t_rgb
void	set_rgb(t_data *data, t_rgb *rgb, char *str)
{
	if (rgb->rgb != -1)
		error_and_exit(data, "ERROR! duplicate color input");
	str += 2;
	rgb->r = get_int_color(data, str);
	while (ft_isalpha(*str) || *str == ',')
		str++;
	rgb->g = get_int_color(data, str);
	while (ft_isalpha(*str) || *str == ',')
		str++;
	rgb->b = get_int_color(data, str);
	while (ft_isalpha(*str))
		str++;
	if (*str != '\0')
		error_and_exit(data, "ERROR! wrong color input");
	rgb->rgb = rgb->r;
	rgb->rgb = (rgb->rgb << 8) + rgb->g;
	rgb->rgb = (rgb->rgb << 8) + rgb->b;
}

//void	set_texture(t_data *data, t_tx *tx, char *str)
void	set_texture(t_data *data, char *tx, char *str)
{
	if (tx != NULL)
		error_and_exit(data, "ERROR! duplicate texture input");
	str += 3;
	if (str[0] != '.' || str[1] != '/')
		error_and_exit(data, "ERROR! wrong texture input");
	tx = ft_strdup(str);
	if (!tx)
		error_and_exit(data, "ERROR! wrong texture input");
}

//	set elements which are NSEW textures and colors for ceiling and floor
int	set_elements(t_data *data, char	*line)
{
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
	else if (!chk_all_spaces(line))
		return (0);
	return (1);
}
