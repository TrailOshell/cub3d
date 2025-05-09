/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwangtip <kwangtip@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/18 20:15:03 by kwangtip          #+#    #+#             */
/*   Updated: 2023/10/02 09:57:58 by kwangtip         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_checkovf(long sign)
{
	if (sign > 0)
		return ((int) LONG_MAX);
	else
		return ((int) LONG_MIN);
}

int	ft_atoi(const char *str)
{
	long	sign;
	long	nb;
	long	i;

	nb = 0;
	sign = 1;
	i = 0;
	while ((str[i] == '\t' || str[i] == '\n' || str[i] == '\v'
			|| str[i] == '\f' || str[i] == '\r' || str[i] == ' '))
		i++;
	if (str[i] == '-')
		sign = -1;
	if (str[i] == '-' || str[i] == '+')
		i++;
	while (str[i] >= '0' && str[i] <= '9')
	{
		nb = (nb * 10) + (str[i] - 48);
		i++;
		if (nb < 0)
			return (ft_checkovf(sign));
	}
	return (nb * sign);
}
/*
#include <stdio.h>
#include <stdlib.h>

int	main(void)
{
	printf("%d \n",ft_atoi("-922073433720368547758"));
	printf("%d \n",atoi("-922073433720368547758"));
	return (0);
}
*/