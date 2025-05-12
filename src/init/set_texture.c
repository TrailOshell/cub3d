/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_texture.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsomchan <tsomchan@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/09 15:03:37 by tsomchan          #+#    #+#             */
/*   Updated: 2025/05/12 16:42:59y tsomchan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int	get_int_color(t_data *data, char *str, int *i)
{
	int	color;

	color = 0;
	while (str[*i] && ft_isdigit(str[*i]))
	{
		color += (str[*i] - '0');
		*i += 1;
		if (str[*i] && ft_isdigit(str[*i]))
			color *= 10;
	}
	if (color > 255)
		error_and_exit(data, "ERROR! wrong color input (>255)\n");
	if (str[*i] == ',')
		*i += 1;
	return (color);
}

//	set the red green and blue value to t_rgb
void	set_rgb(t_data *data, int *rgb, char *str)
{
	int	r;
	int	g;
	int	b;
	int	i;

	if (*rgb != -1)
		error_and_exit(data, "ERROR! duplicate color input\n");
	i = 2;
	r = get_int_color(data, str, &i);
	g = get_int_color(data, str, &i);
	b = get_int_color(data, str, &i);
	if (str[i] != '\n' && str[i] != '\0')
		error_and_exit(data, "ERROR! wrong color input\n");
	*rgb = r;
	*rgb = (*rgb << 8) + g;
	*rgb = (*rgb << 8) + b;
}

//void	set_texture(t_data *data, t_tx *tx, char *str)
void	set_texture(t_data *data, char **tx, char *str)
{
	if (*tx != NULL)
		error_and_exit(data, "ERROR! duplicate texture input");
	str += 3;
	if (str[0] != '.' || str[1] != '/')
		error_and_exit(data, "ERROR! wrong texture input");
	*tx = ft_strdup(str);
	if (!*tx)
		error_and_exit(data, "ERROR! wrong texture input");
}

//	set elements which are NSEW textures and colors for ceiling and floor
int	set_elements(t_data *data, char	*line)
{
	if (chk_all_spaces(line))
		return (1);
	if (ft_strncmp(line, "NO ", 3) == 0)
		set_texture(data, &data->tx->no, line);
	else if (ft_strncmp(line, "SO ", 3) == 0)
		set_texture(data, &data->tx->so, line);
	else if (ft_strncmp(line, "EA ", 3) == 0)
		set_texture(data, &data->tx->ea, line);
	else if (ft_strncmp(line, "WE ", 3) == 0)
		set_texture(data, &data->tx->we, line);
	else if (ft_strncmp(line, "C ", 2))
		set_rgb(data, &data->c, line);
	else if (ft_strncmp(line, "F ", 2))
		set_rgb(data, &data->f, line);
	else if (!chk_all_spaces(line))
		return (0);
	return (1);
}
