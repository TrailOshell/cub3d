/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwangtip <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/30 13:25:02 by kwangtip          #+#    #+#             */
/*   Updated: 2023/08/30 13:37:11 by kwangtip         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isdigit(int c)
{
	if (!(c >= 48 && c <= 57))
		return (0);
	return (1);
}
/*
#include <stdio.h>
int	main(void)
{
	printf("%d\n", ft_isdigit(122));
	printf("%d\n", ft_isdigit(48));
	printf("%d\n", ft_isdigit(0));
	printf("%d\n", ft_isdigit(57));
}
*/
