/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsomchan <tsomchan@student.42bangkok.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 19:07:41 by tsomchan          #+#    #+#             */
/*   Updated: 2025/05/09 15:23:31 by tsomchan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

size_t	cub_strlen(char *s)
{
	size_t	len;

	len = 0;
	while (*(s++))
		len++;
	return (len);
}

char	*cub_strdup(char *s)
{
	char	*dup;
	int		i;

	dup = malloc(sizeof(char) * cub_strlen(s) + 1);
	i = 0;
	while (s[i])
	{
		dup[i] = s[i];
		i++;
	}
	dup[i] = '\0';
	return (dup);
}

int	cub_strrncmp(char *s1, char *s2, size_t n)
{
	while (*s1)
		s1++;
	while (*s2)
		s2++;
	while (n--)
		if (*(--s1) != *(--s2))
			return (*s1 - *s2);
	return (0);
}

char	*cub_strjoin(char *s1, char *s2)
{
	char	*ptr;
	size_t	size1;
	size_t	size2;
	int		i;

	if (!s1 || !s2)
		return (0);
	size1 = cub_strlen(s1);
	size2 = cub_strlen(s2);
	ptr = malloc(sizeof(char) * (size1 + size2 + 1));
	if (!ptr)
		return (0);
	i = 0;
	while (*s1)
		ptr[i++] = *(s1++);
	while (*s2)
		ptr[i++] = *(s2++);
	ptr[i] = '\0';
	return (ptr);
}
