/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwangtip <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/30 17:29:48 by kwangtip          #+#    #+#             */
/*   Updated: 2023/08/30 18:35:06 by kwangtip         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_tolower(int c)
{
	{
		if (c >= 'A' && c <= 'Z')
			return (c + 32);
	}
	return (c);
}
/*
#include <stdio.h>
int	main(void)
{
	printf("%c\n", ft_tolower('A'));
	printf("%c\n", ft_tolower('c'));
	printf("%c\n", ft_tolower(12));
	printf("%c\n", ft_tolower('0'));
	printf("%c\n", ft_tolower('Z'));
}
*/
