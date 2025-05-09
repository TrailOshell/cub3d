/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwangtip <kwangtip@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 13:29:07 by kwangtip          #+#    #+#             */
/*   Updated: 2023/11/28 15:48:53 by kwangtip         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, int n)
{
	int				i;
	unsigned char	*str1;
	unsigned char	*str2;

	if (n == 0)
		return (0);
	str1 = (unsigned char *)s1;
	str2 = (unsigned char *)s2;
	i = 0;
	while ((i < n - 1) && str1[i] == str2[i])
		i++;
	return (str1[i] - str2[i]);
}
/*
#include <stdio.h>
#include <string.h>

int	main(void)
{
	printf("my func : %d \n", ft_memcmp("Happy","Hapy", 5));
	printf("my func : %d \n", ft_memcmp(NULL,NULL, 0));
	printf("string : %d \n", memcmp(NULL, NULL, 0));
	printf("string : %d \n", memcmp("nnnn","nnn", 5));
}
*/
