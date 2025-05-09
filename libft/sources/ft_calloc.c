/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwangtip <kwangtip@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/06 21:07:56 by kwangtip          #+#    #+#             */
/*   Updated: 2023/11/28 15:48:53 by kwangtip         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(int count, int size)
{
	void	*dup;
	int		bytes;

	bytes = size * count;
	if (bytes > 0 && size > 0 && bytes / size != count)
		return (NULL);
	dup = malloc(bytes);
	if (!(dup))
		return (NULL);
	ft_bzero(dup, bytes);
	return (dup);
}
/*
int	main(void)
{
		ft_calloc(10, 1);
		calloc(10, 1);
		return (0);
}
*/
