/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsomchan <tsomchan@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 19:07:41 by tsomchan          #+#    #+#             */
/*   Updated: 2025/05/12 15:25:56 by tsomchan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int	ft_strrncmp(char *s1, char *s2, size_t n)
{
	while (*s1)
		s1++;
	while (*s2)
		s2++;
	while (n--)
		if (*(--s1) != *(--s2))
			return (*s1 - *s2);
	return (0);
}

int	ft_isspace(char str)
{
	if (str == ' ' || str == '\t' || str == '\n' || str == '\r')
		return (1);
	return (0);
}

int	chk_all_spaces(char *str)
{
	while (*str)
		if (ft_isspace(*(str++)) == 0)
			return (0);
	return (1);
}
