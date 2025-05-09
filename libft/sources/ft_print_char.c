/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_char.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwangtip <kwangtip@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 16:04:28 by kwangtip          #+#    #+#             */
/*   Updated: 2023/12/18 20:12:08 by kwangtip         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_print_char(int c)
{
	if (write(1, &c, 1) == -1)
		return (-1);
	return (1);
}
/*
 #include <stdio.h>
 #include <stdint.h>

int	main(viod)
 {
 	printf("%d", ft_print_char('w'));
	printf("\n\n\n\n%d", (SIZE_T_MAX));
 }
*/
