/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwangtip <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/30 12:24:31 by kwangtip          #+#    #+#             */
/*   Updated: 2023/09/07 18:45:41 by kwangtip         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isalpha(int c)
{
	if (!((c >= 'A' && c <= 'Z')
			|| (c >= 'a' && c <= 'z')))
		return (0);
	return (1);
}
/*
#include <stdio.h>
int	main(void)
{
	printf("%d\n", ft_isalpha(48));
	printf("%d\n", ft_isalpha(90));
	printf("%d\n", ft_isalpha(13));
	printf("%d\n", ft_isalpha(73));
}
*/
