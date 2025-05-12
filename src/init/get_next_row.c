/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_row.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsomchan <tsomchan@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/21 16:43:01 by tsomchan          #+#    #+#             */
/*   Updated: 2025/05/12 14:59:15 by tsomchan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int	get_map(t_data *data, char *line)
{
	int		i;
	int		row_len;

	i = 0;
	while (line[i])
	{
		if (isvalidchar(line[i]) == 0)
			error_and_exit(data, "ERROR! Invalid char\n");
		else if (ft_isspace(line[i]) == 0)
			row_len = i + 1;
		i++;
	}
	line[row_len] = '\0';
	add_line(&data->node, line);
	data->map->n_row++;
	return (1);
}

// this one keeps newline in the nodes
void	get_next_row(t_data *data, int fd)
{
	char	*line;
	int		step;

	step = 1;
	while (step)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		if (step == 1 && set_elements(data, line) == 0)
		{
			if (!data->tx->no || !data->tx->so || !data->tx->ea || !data->tx->we
				|| data->c->rgb == -1 || data->f->rgb == -1)
				error_and_exit(data, "ERROR! missing elements input");
			step = 2;
		}
		if (step == 2 && get_map(data, line) == 0)
		{
			if (data->node == NULL)
				error_and_exit(data, "ERROR! Empty map\n");
			step = 0;
		}
		free(line);
	}
}
