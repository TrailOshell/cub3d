/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwangtip <kwangtip@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 16:05:50 by kwangtip          #+#    #+#             */
/*   Updated: 2023/12/18 20:12:08 by kwangtip         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_type(const char *str, va_list *args)
{
	int	len;

	len = 0;
	if (*str == 'c')
		len += ft_print_char(va_arg(*args, int ));
	else if (*str == 's')
		len += ft_print_str(va_arg(*args, char *));
	else if (*str == 'd' || *str == 'i')
		len += ft_print_di(va_arg(*args, int ));
	else if (*str == 'u')
		len += ft_print_u(va_arg(*args, unsigned int ));
	else if (*str == 'x' || *str == 'X')
		len += ft_print_x((va_arg(*args, unsigned int)), *str);
	else if (*str == 'p')
		len += ft_print_p(va_arg(*args, unsigned long long));
	else if (*str == '%')
		len += ft_print_char('%');
	else
		len += ft_print_char(*str);
	return (len);
}

int	ft_printf(const char *str, ...)
{
	va_list	args;
	int		len;
	int		tmp;

	len = 0;
	va_start(args, str);
	if (!str)
		return (0);
	while (*str != '\0')
	{
		if (*str == '%')
			tmp = ft_type(++str, &args);
		else
			tmp = ft_print_char(*str);
		if (tmp == -1)
			return (-1);
		len += tmp;
		str++;
	}
	va_end(args);
	return (len);
}
