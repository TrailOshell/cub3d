/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwangtip <kwangtip@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/07 14:54:15 by kwangtip          #+#    #+#             */
/*   Updated: 2023/11/28 15:48:53 by kwangtip         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*join;
	int		len;
	int		i;

	if (s1 == NULL || s2 == NULL)
		return (NULL);
	len = ft_strlen(s1) + ft_strlen(s2);
	join = malloc(sizeof(char) * (len + 1));
	if (!(join))
		return (NULL);
	len = 0;
	while (s1[len])
	{
		join[len] = s1[len];
		len++;
	}
	i = 0;
	while (s2[i])
	{
		join[len + i] = s2[i];
		i++;
	}
	join[len + i] = '\0';
	return (join);
}
/*
#include <stdio.h>

int	main(void)
{
	char	*x;

		x = ft_strjoin("\200", "ssss");
	printf("\n%s",x);
			free(x);
			return(0);
}
*/
