/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwangtip <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/06 15:36:53 by kwangtip          #+#    #+#             */
/*   Updated: 2023/09/06 20:05:30 by kwangtip         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	long	k;

	k = n;
	if (k < 0)
	{
		ft_putchar_fd('-', fd);
		k = -k;
	}
	if (k > 9)
	{
		ft_putnbr_fd(k / 10, fd);
		ft_putchar_fd(k % 10 + 48, fd);
	}
	else
	{
		ft_putchar_fd(k + 48, fd);
	}
}
/*
int	main(void)
{
	ft_putnbr_fd(-123456678,1);
	ft_putchar_fd('\n',1);
	
	ft_putnbr_fd(-0,3);
	
	ft_putnbr_fd(1,1);
	ft_putnbr_fd(-0,1);
	ft_putnbr_fd(-2147283648,1);
	ft_putnbr_fd(2147283647,1);
	ft_putnbr_fd(42,1);
}
*/
