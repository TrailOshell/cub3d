/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwangtip <kwangtip@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/07 16:14:43 by kwangtip          #+#    #+#             */
/*   Updated: 2023/11/28 15:48:53 by kwangtip         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, int len)
{
	int	i;
	int	len_need;

	i = 0;
	len_need = ft_strlen(needle);
	if (len_need == 0)
		return ((char *)haystack);
	while (haystack[i] != '\0' && (i + len_need) <= len)
	{
		if (ft_strncmp(haystack + i, needle, len_need) == 0)
			return ((char *)haystack + i);
		i++;
	}
	return (NULL);
}
/*
#include <stdio.h>
int	main(void)
{
	printf("%s\n",ft_strnstr("", "pp", 0));
	printf("%s\n",ft_strnstr("lorem ipsum dolor sit amet", "",10));
}
*/
