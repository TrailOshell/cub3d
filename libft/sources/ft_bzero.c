/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwangtip <kwangtip@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/31 15:14:40 by kwangtip          #+#    #+#             */
/*   Updated: 2023/11/28 15:48:53 by kwangtip         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *s, int n)
{
	int				i;
	unsigned char	*ptr;

	i = 0;
	ptr = (unsigned char *)s;
	while (i < n)
		ptr[i++] = 0;
}
/*
#include <stdio.h>

int	main(void)
{
	char	str[42] = "Happy Day";
	size_t	len;

	len = 3;
	ft_bzero(str, len);
	printf("%d %c\n",str[0], str[0]);
	printf("%d %c\n",str[1], str[1]);
	printf("%d %c\n",str[2], str[2]);
	printf("%d %c\n",str[3], str[3]);
	printf("%d %c\n",str[4], str[4]);
	return (0);
}
*/
