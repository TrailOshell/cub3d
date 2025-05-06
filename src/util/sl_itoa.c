/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsomchan <tsomchan@student.42bangkok.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/19 20:55:59 by tsomchan          #+#    #+#             */
/*   Updated: 2025/05/06 16:19:55 by tsomchan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int	count_value(int n)
{
	int	count;

	if (n == 0)
		return (1);
	count = 0;
	if (n < 0)
	{
		n *= -1;
		count++;
	}
	while (n > 0)
	{
		count++;
		n /= 10;
	}
	return (count);
}

void	recur_itoa(int n, char *ptr, int i)
{
	char	c;

	if (n < 0)
	{
		n *= -1;
		ptr[0] = '-';
		recur_itoa(n, ptr, i);
	}
	else if (n > 0)
	{
		c = n % 10;
		if (n / 10 > 0)
			recur_itoa(n / 10, ptr, i - 1);
		ptr[i] = '0' + c;
	}
	else if (n == 0)
		ptr[i] = '0';
}

char	*sl_itoa(int n)
{
	char	*ptr;
	size_t	count;

	if (n == -2147483648)
		return (sl_strdup("-2147483648"));
	count = count_value(n);
	ptr = malloc(sizeof(char) * (count + 1));
	if (!ptr)
		return (0);
	recur_itoa(n, ptr, count - 1);
	ptr[count] = 0;
	return (ptr);
}
