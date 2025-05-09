/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwangtip <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/30 16:57:27 by kwangtip          #+#    #+#             */
/*   Updated: 2023/08/30 17:28:15 by kwangtip         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_toupper(int c)
{
	if (c >= 'a' && c <= 'z')
		return (c - 32);
	return (c);
}
/*
#include <stdio.h>
int	main(void)
{
	printf("%c\n", ft_toupper(97));
	printf("%c\n", ft_toupper('b'));
	printf("%c\n", ft_toupper('D'));
	printf("%c\n", ft_toupper(48));
	printf("%c\n", ft_toupper('c'));
}
*/
