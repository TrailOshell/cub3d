/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_u.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwangtip <kwangtip@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 16:21:47 by kwangtip          #+#    #+#             */
/*   Updated: 2024/01/08 15:47:16 by kwangtip         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_print_u(unsigned int args)
{
	unsigned int	tmp;
	unsigned int	div;
	int				len;
	int				d;

	len = 0;
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
		if (write(1, &d, 1) == -1)
			return (-1);
		len++;
		args = args % div;
		div = div / 10;
	}
	return (len);
}
