/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_x.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwangtip <kwangtip@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 15:29:14 by kwangtip          #+#    #+#             */
/*   Updated: 2023/12/18 20:12:08 by kwangtip         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_base(unsigned int args, char str, int div)
{
	int		len;
	char	*base;

	len = 0;
	if (str == 'x')
		base = "0123456789abcdef";
	if (str == 'X')
		base = "0123456789ABCDEF";
	while (div > 0)
	{
		if (write (1, &base[args / div], 1) == -1)
			return (-1);
		len++;
		args = args % div;
		div = div / 16;
	}
	return (len);
}

int	ft_print_x(unsigned int args, char str)
{
	unsigned int	tmp;
	unsigned int	div;

	div = 1;
	tmp = args;
	while (tmp >= 16)
	{
		tmp = tmp / 16;
		div = div * 16;
	}
	return (ft_base(args, str, div));
}
/*
#include <stdio.h>
int	main(void)
{
	printf("%d", ft_print_x( 14010 ,'X'));
	printf("\n\n\n\n\n");
	printf("%d", printf("%X", 14010));


}
*/
