/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwangtip <kwangtip@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/30 16:23:53 by kwangtip          #+#    #+#             */
/*   Updated: 2023/11/28 15:48:53 by kwangtip         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, int len)
{
	int				i;
	unsigned char	*ptr;

	i = 0;
	ptr = (unsigned char *)b;
	while (i < len)
		ptr[i++] = c;
	return (b);
}
/*
#include <stdio.h>

int	main(void)
{
	char	str[42] = "Happy Day";
	int		c;
	size_t	len;

	c = '&';
	len = 3;
	ft_memset(str, c, len);
	printf("%s", str);
	return(0);
}
*/
