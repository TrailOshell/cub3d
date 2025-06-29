/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_row.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsomchan <tsomchan@student.42bangkok.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/21 16:43:01 by tsomchan          #+#    #+#             */
/*   Updated: 2025/06/29 15:57:31 by tsomchan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int	get_map(t_data *data)
{
	int		i;
	int		row_len;
	char	*line;

	line = data->line;
	i = 0;
	row_len = 0;
	while (line[i])
	{
		if (isvalidchar(line[i]) == 0)
		{
			write_color("ERROR! Invalid char\n", YLW);
			return (-1);
		}
		else if (line[i] != '\n' && ft_isspace(line[i]) == 0)
			row_len = i + 1;
		i++;
	}
	line[row_len] = '\0';
	add_line(&data->node, line);
	data->map->n_row++;
	if (row_len > data->map->n_col)
		data->map->n_col = row_len;
	return (1);
}

void	remove_newline(t_data *data)
{
	int	i;

	i = 0;
	while (data->line[i])
	{
		if (data->line[i] == '\n')
			data->line[i] = '\0';
		i++;
	}
}

int	get_result(int	*result, int func)
{
	*result = func;
	return (*result);
}

// this one keeps newline in the nodes
void	get_next_row(t_data *data, int fd)
{
	int	step;
	int	result;

	result = 0;
	step = 1;
	while (step)
	{
		data->line = get_next_line(fd);
		if (data->line == NULL)
			break ;
		remove_newline(data);
		if (result != -1)
		{
			if (step == 1 && get_result(&result, set_elements(data)) == 0)
				step = 2;
			if (step == 2 && get_result(&result, get_map(data) == 0))
				step = 0;
		}
		free(data->line);
		data->line = NULL;
	}
	if (result == -1)
		error_and_exit(data, NULL);
}
