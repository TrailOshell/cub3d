/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwangtip <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/30 16:05:04 by kwangtip          #+#    #+#             */
/*   Updated: 2023/08/30 16:18:04 by kwangtip         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isprint(int c)
{
	if (c >= 32 && c <= 126)
		return (1);
	return (0);
}
/*
#include <stdio.h>
int	main(void)
{
	printf("%d\n", ft_isprint(0));
	printf("%d\n", ft_isprint(32));
	printf("%d\n", ft_isprint(123));
	printf("%d\n", ft_isprint(126));
	printf("%d\n", ft_isprint(127));
}
*/
