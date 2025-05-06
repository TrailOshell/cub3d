/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug_pathfinding.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsomchan <tsomchan@student.42bangkok.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/04 21:26:59 by tsomchan          #+#    #+#             */
/*   Updated: 2025/05/06 16:49:56 by tsomchan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	debug_facing_step(int up, int down, int left, int right)
{
	int	c;

	(void)up;
	(void)down;
	(void)left;
	(void)right;
	//c = set_next_step(up, down, left, right);
	write(1, &c, 1);
}

void	debug_pathfinding(int up, int down, int left, int right)
{
	write_value("up =", up);
	write(1, "\n", 1);
	write_value("down =", down);
	write(1, "\n", 1);
	write_value("left =", left);
	write(1, "\n", 1);
	write_value("right =", right);
	write(1, "\n", 1);
	write_color("facing ", GREEN);
	debug_facing_step(up, down, left, right);
	write(1, "\n", 1);
}
