/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_str.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwangtip <kwangtip@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 18:34:57 by kwangtip          #+#    #+#             */
/*   Updated: 2023/12/18 20:12:08 by kwangtip         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_print_str(char *c)
{
	int	len;

	len = 0;
	if (!c)
	{
		if (write(1, "(null)", 6) == -1)
			return (-1);
		return (6);
	}
	while (c[len])
	{
		if (write (1, &c[len], 1) == -1)
			return (-1);
		len++;
	}
	return (len);
}
