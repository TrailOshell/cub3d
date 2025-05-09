/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwangtip <kwangtip@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/04 18:54:14 by kwangtip          #+#    #+#             */
/*   Updated: 2023/11/28 15:48:53 by kwangtip         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strlcpy(char *dst, const char *src, int detsize)
{
	int	i;
	int	srclen;

	srclen = ft_strlen(src);
	if (detsize == 0)
		return (srclen);
	i = 0;
	while (i < (detsize - 1) && src[i] != '\0')
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (srclen);
}
/*
#include <stdio.h>
#include <string.h>
int main(void)
{
		char src[42] = "Happy day";
		char dst[42] = "123";
		size_t detsize = 23;
		ft_strlcpy(dst, src, detsize);
		printf("my :%s\n", src);
		printf("str : %lu\n", strlcpy(dst, src, detsize));
		return (0);
}
*/
