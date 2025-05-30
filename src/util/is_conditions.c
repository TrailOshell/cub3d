/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_conditions.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsomchan <tsomchan@student.42bangkok.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/19 19:23:55 by tsomchan          #+#    #+#             */
/*   Updated: 2025/05/14 16:05:37 by tsomchan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int	isplayerchar(char c)
{
	if (c == 'N' || c == 'S' || c == 'E' || c == 'W')
		return (1);
	return (0);
}

int	isvalidchar(char c)
{
	if (c == '0' || c == '1' || isplayerchar(c) || ft_isspace(c))
		return (1);
	return (0);
}

int	iswalkable(char c)
{
	if (c == '0' || isplayerchar(c))
		return (1);
	return (0);
}
