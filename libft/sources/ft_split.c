/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwangtip <kwangtip@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/20 17:38:09 by kwangtip          #+#    #+#             */
/*   Updated: 2023/11/28 15:48:53 by kwangtip         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_word(char const *s, char c)
{
	int	i;
	int	word;

	i = 0;
	word = 0;
	while (s[i] != '\0')
	{
		if (i == 0 && s[i] != c)
			word++;
		if (i > 0 && s[i] != c && s[i - 1] == c)
			word++;
		i++;
	}
	return (word);
}

static char	**ft_free_sp(char **result)
{
	int	i;

	i = 0;
	while (result[i])
	{
		free(result[i]);
		result[i] = NULL;
		i++;
	}
	free(result);
	return (NULL);
}

static char	**ft_malword(char const *s, char c, char **result)
{
	int	len;
	int	i;
	int	j;

	j = 0;
	i = 0;
	len = 0;
	while (s[i])
	{
		if (s[i] != c)
		{
			len++;
		}
		if ((s[i] == c && i > 0 && s[i - 1] != c)
			|| (s[i] != c && s[i + 1] == '\0'))
		{
			result[j] = malloc(sizeof(char) * (len + 1));
			if (!result[j])
				return (NULL);
			len = 0;
			j++;
		}
		i++;
	}
	return (result);
}

static char	**ft_cpy(char const *s, char **result, char c)
{
	int	x;
	int	y;
	int	i;

	i = 0;
	x = 0;
	y = 0;
	while (s[i])
	{
		if (s[i] != c)
			result[x][y++] = s[i];
		if ((s[i] != c) && (s[i + 1] == '\0'))
			result[x][y] = '\0';
		if ((s[i] == c && i > 0) && (s[i - 1] != c))
		{
			result[x][y] = '\0';
			x++;
			y = 0;
		}
		i++;
	}
	return (result);
}

char	**ft_split(char const *s, char c)
{
	int		word;
	char	**result;

	if (!s)
	{
		result = malloc(sizeof(char) * 1);
		if (!result)
			return (NULL);
		*result = NULL;
		return (result);
	}
	word = ft_word(s, c);
	result = malloc(sizeof(char *) * (word + 1));
	if (!result)
		return (NULL);
	if (ft_malword(s, c, result))
	{
		ft_cpy(s, result, c);
		result[word] = NULL;
	}
	else
		result = ft_free_sp(result);
	return (result);
}

// int	main(void)
// {

// 	char s[] = "jkhkhlf      ghjhkyfkhnnvshj";
// 	char **t;

// 	t = ft_split(s,' ');
// 	int i = 0 ;
// 	while (t[i] != 0)
// 	{
// 		printf("%s\n",t[i]);
// 		i++;
// 	}
// 		printf("%d\n",i);
//  }
