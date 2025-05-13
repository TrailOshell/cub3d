/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_row.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsomchan <tsomchan@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/21 16:43:01 by tsomchan          #+#    #+#             */
/*   Updated: 2025/05/13 21:00:52 by tsomchan         ###   ########.fr       */
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
	int		step;

	step = 1;
	while (step)
	{
		data->line = get_next_line(fd);
		if (data->line == NULL)
			break ;
		if (step == 1 && set_elements(data, data->line) == 0)
			step = 2;
		if (step == 2 && get_map(data, data->line) == 0)
			step = 0;
		free(data->line);
		data->line = NULL;
	}
	write_elements(data);
	if (!data->tx->no || !data->tx->so || !data->tx->ea || !data->tx->we
		|| data->c->rgb == -1 || data->f->rgb == -1)
		error_and_exit(data, "ERROR! missing elements input\n");
	else if (data->node == NULL)
		error_and_exit(data, "ERROR! Empty map\n");
}
