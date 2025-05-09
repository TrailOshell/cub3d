/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_di.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwangtip <kwangtip@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 18:26:47 by kwangtip          #+#    #+#             */
/*   Updated: 2023/12/18 20:12:08 by kwangtip         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_di(int args, int len)
{
	int	tmp;
	int	d;
	int	div;

	div = 1;
	tmp = args;
	while (tmp >= 10)
	{
		tmp = tmp / 10;
		div = div * 10;
	}
	while (div > 0)
	{
		d = args / div + '0';
		if (write (1, &d, 1) == -1)
			return (-1);
		len++;
		args = args % div;
		div = div / 10;
	}
	return (len);
}

int	ft_print_di(int args)
{
	int	len;

	len = 0;
	if (args == -2147483648)
	{
		if (write (1, "-2147483648", 11) == -1)
			return (-1);
		return (11);
	}
	if (args < 0)
	{
		if (write (1, "-", 1) == -1)
			return (-1);
		len++;
		args = args * -1;
	}
	return (ft_di(args, len));
}
/*
#include <stdio.h>
int	main (void)
{
	printf("%d", ft_print_di(-2));
}
*/
