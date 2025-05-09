/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwangtip <kwangtip@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 13:54:54 by kwangtip          #+#    #+#             */
/*   Updated: 2023/11/28 15:48:53 by kwangtip         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*cpystring(char const *s, char *str, int start, int len)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (s[i])
	{
		if (i >= start && j < len)
		{
			str[j] = s[i];
			j++;
		}
		i++;
	}
	str[j] = 0;
	return (str);
}

char	*ft_substr(char const *s, int start, int len)
{
	char	*str;
	int		malsize;

	if (!s)
		return (NULL);
	if (ft_strlen(s) <= start)
		return (ft_strdup(""));
	malsize = len;
	if (len > ft_strlen(s) - start)
		malsize = ft_strlen(s) - start;
	str = (char *)malloc(sizeof(*s) * (malsize + 1));
	if (!str)
		return (NULL);
	str = cpystring(s, str, start, len);
	return (str);
}
/*
#include <stdio.h>

int	main(void)
{
	printf("%s\n", ft_substr("ABCDEDKJHih",2,4));
}
*/
