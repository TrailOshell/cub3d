/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwangtip <kwangtip@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/30 18:49:03 by kwangtip          #+#    #+#             */
/*   Updated: 2023/11/28 15:48:53 by kwangtip         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	int		i;
	char	t;

	t = (char)c;
	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] == t)
			return ((char *)s + i);
		i++;
	}
	if (s[i] == t)
		return ((char *)s + i);
	return (NULL);
}

// #include <stdio.h>
// int	main(void)
// {
// 	char *s;
// 	s= "teste";
// 	printf("%s\n", ft_strchr(s, 'e' ));
// 	printf("%s\n", ft_strchr("Happy", ' '));
// 	printf("%s\n", ft_strchr("Happy", '\0'));
// 	printf("%s\n", ft_strchr("Happy", 'H'));
// }
