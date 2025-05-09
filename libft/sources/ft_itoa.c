/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwangtip <kwangtip@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/18 13:47:33 by kwangtip          #+#    #+#             */
/*   Updated: 2023/11/28 15:48:53 by kwangtip         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_array(char *tmp, long num, int len)
{
	while (num > 0)
	{
		tmp[len--] = 48 + (num % 10);
		num = num / 10;
	}
	return (tmp);
}

static int	ft_len(long n)
{
	long	len;

	len = 0;
	if (n <= 0)
		len = 1;
	while (n != 0)
	{
		len++;
		n = n / 10;
	}
	return (len);
}

char	*ft_itoa(int n)
{
	char	*tmp;
	int		len;
	int		num;
	long	nn;

	nn = n;
	len = ft_len(nn);
	tmp = (char *)malloc(sizeof(char) * (len + 1));
	if (!tmp)
		return (NULL);
	if (nn == 0)
		tmp[0] = '0';
	tmp[len--] = '\0';
	if (nn < 0)
	{
		num = nn * -1;
		tmp[0] = '-';
	}
	else
		num = nn;
	tmp = ft_array(tmp, num, len);
	return (tmp);
}
/*
#include <stdio.h>

int	main(void)
{
	printf("%s\n", ft_itoa(-123456789));
}
*/
