/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_p.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwangtip <kwangtip@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 20:45:13 by kwangtip          #+#    #+#             */
/*   Updated: 2023/12/18 20:12:08 by kwangtip         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_print_p(unsigned long long int args)
{
	unsigned long long int	tmp;
	unsigned long long int	div;
	int						len;
	char					*base;

	base = "0123456789abcdef";
	len = 2;
	div = 1;
	tmp = args;
	while (tmp >= 16)
	{
		tmp = tmp / 16;
		div = div * 16;
	}
	if (write(1, "0x", 2) == -1)
		return (-1);
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
/*
#include <stdio.h>
int main(viod)
{
	int a;
	a = -321;

	printf("%d", ft_print_p(a));
	printf("\n\n\n\n\n\n");
	printf("%d", printf("%p", a));
}
*/
