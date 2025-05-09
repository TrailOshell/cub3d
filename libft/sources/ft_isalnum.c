/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwangtip <kwangtip@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/30 13:38:25 by kwangtip          #+#    #+#             */
/*   Updated: 2023/09/18 18:04:32 by kwangtip         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isalnum(int c)

{
	if (((c <= 57) && (c >= 48)) || ((c >= 65) && (c <= 90))
		|| ((c >= 97) && (c <= 122)))
		return (1);
	return (0);
}
/*
#include <stdio.h>
int	main(void)
{
	printf("%d\n", ft_isalnum(48));
	printf("%d\n", ft_isalnum(122));
	printf("%d\n", ft_isalnum(90));
	printf("%d\n", ft_isalnum(12));
	printf("%d\n", ft_isalnum(0));
}
*/
