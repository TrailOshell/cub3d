/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isascii.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwangtip <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/30 15:46:45 by kwangtip          #+#    #+#             */
/*   Updated: 2023/08/30 16:02:12 by kwangtip         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isascii(int c)
{
	if (c >= 0 && c <= 127)
		return (1);
	return (0);
}
/*
#include <stdio.h>
int	main(void)
{
	printf("%d\n", ft_isascii(0));
	printf("%d\n", ft_isascii(48));
	printf("%d\n", ft_isascii(57));
	printf("%d\n", ft_isascii(127));
	printf("%d\n", ft_isascii(128));
}
*/
