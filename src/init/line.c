/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsomchan <tsomchan@student.42bangkok.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/19 21:40:29 by tsomchan          #+#    #+#             */
/*   Updated: 2025/05/09 15:23:31 by tsomchan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	add_line(t_node **node, char *line)
{
	t_node	*new;
	t_node	*tmp;

	new = malloc(sizeof(t_node));
	new->next = NULL;
	new->line = line_dupe(line);
	if (!*node)
	{
		*node = new;
		return ;
	}
	tmp = *node;
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = new;
}

char	*line_dupe(char *line)
{
	char	*new;
	int		len;
	int		i;

	len = cub_strlen(line);
	new = malloc(sizeof(char) * len + 1);
	i = 0;
	while (len--)
	{
		new[i] = line[i];
		i++;
	}
	new[i] = '\0';
	return (new);
}

char	*line_copy(char *copy, char *line)
{
	int	i;

	i = 0;
	while (line[i] && line[i] != '\n')
	{
		copy[i] = line[i];
		i++;
	}
	copy[i] = '\0';
	return (copy);
}
