/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwangtip <kwangtip@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/30 19:19:07 by kwangtip          #+#    #+#             */
/*   Updated: 2023/09/25 14:27:07 by kwangtip         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_strrchr(const char *s, int c)
{
	int		i;
	char	t;

	t = (char) c;
	i = 0;
	while (s[i] != '\0')
		i++;
	while (i > 0)
	{
		if (s[i] == t)
			return ((char *) s + i);
		i--;
	}
	if (s[i] == t)
		return ((char *) s + i);
	return (NULL);
}
/*
#include <stdio.h>
int	main(void)
{
	printf("%s\n", ft_strrchr("Happy", 'p'));
	printf("%s\n", ft_strrchr("Happy", ' '));
	printf("%s\n", ft_strrchr("Happy", 'a'));
	printf("%s\n", ft_strrchr("Happy", '\0'));
	printf("%s\n", ft_strrchr("Happy", 'H'));
}
*/
