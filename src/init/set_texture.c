/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_texture.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsomchan <tsomchan@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/13 01:07:07 by tsomchan          #+#    #+#             */
/*   Updated: 2025/05/13 19:57:44y tsomchan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	error_elements(t_data *data, char *str)
{
	write_elements(data);
	error_and_exit(data, str);
}

int	get_int_color(t_data *data, char *str, int *i)
{
	int	color;

	color = 0;
	while (ft_isspace(str[*i]))
		*i += 1;
	while (str[*i] && ft_isdigit(str[*i]))
	{
		color += (str[*i] - '0');
		*i += 1;
		if (str[*i] && ft_isdigit(str[*i]))
			color *= 10;
	}
	while (ft_isspace(str[*i]))
		*i += 1;
	if (color > 255)
		error_elements(data, "ERROR! wrong color input (not 0-255)\n");
	if (str[*i] == ',')
		*i += 1;
	return (color);
}

//	set the red green and blue value to t_rgb
int	set_rgb(t_data *data, t_rgb *rgb, char *str)
{
	int	i;

	if (rgb->rgb != -1)
		error_elements(data, "ERROR! duplicate color input\n");
	i = 2;
	rgb->r = get_int_color(data, str, &i);
	rgb->g = get_int_color(data, str, &i);
	rgb->b = get_int_color(data, str, &i);
	if (!ft_isspace(str[i]) && str[i] != '\0')
		error_elements(data, "ERROR! wrong color input\n");
	rgb->rgb = rgb->r;
	rgb->rgb = (rgb->rgb << 8) + rgb->g;
	rgb->rgb = (rgb->rgb << 8) + rgb->b;
	return (1);
}
	// write_double_color("color: ", YLW, str, CYN);

//void	set_texture(t_data *data, t_tx *tx, char *str)
int	set_texture(t_data *data, char **tx, char *str)
{
	int	fd;

	if (*tx != NULL)
		error_elements(data, "ERROR! duplicate texture input\n");
	str += 3;
	if (str[0] != '.' || str[1] != '/')
		error_elements(data, "ERROR! texture input \"./\" not found)\n");
	if (ft_strrncmp(str, ".png", 3))
		error_elements(data, "ERROR! only .png texture file is allowed\n");
	fd = open(&str[2], O_RDONLY);
	if (fd < 0)
		error_and_exit(data, "ERROR! fd error on texture file\n");
	close(fd);
	*tx = ft_strdup(str);
	if (!*tx)
		error_elements(data, "ERROR! texture input failed\n");
	return (1);
}
	//write_color_nl(&str[2], GRN);

//	set elements which are NSEW textures and colors for ceiling and floor
int	set_elements(t_data *data, char	*line)
{
	if (chk_all_spaces(line))
		return (1);
	else if (line[0] == 'N' && line[1] == 'O' && ft_isspace(line[2]))
		return (set_texture(data, &data->tx->no, line));
	else if (line[0] == 'S' && line[1] == 'O' && ft_isspace(line[2]))
		return (set_texture(data, &data->tx->so, line));
	else if (line[0] == 'E' && line[1] == 'A' && ft_isspace(line[2]))
		return (set_texture(data, &data->tx->ea, line));
	else if (line[0] == 'W' && line[1] == 'E' && ft_isspace(line[2]))
		return (set_texture(data, &data->tx->we, line));
	else if (line[0] == 'C' && ft_isspace(line[1]))
		return (set_rgb(data, data->c, line));
	else if (line[0] == 'F' && ft_isspace(line[1]))
		return (set_rgb(data, data->f, line));
	else if (!chk_all_spaces(line))
		return (0);
	return (0);
}
