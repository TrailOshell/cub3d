/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwangtip <kwangtip@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 15:05:24 by kwangtip          #+#    #+#             */
/*   Updated: 2024/01/08 14:18:26 by kwangtip         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*read_to_str(int fd, char *str)
{
	char	*buffer;
	int		bytes;

	if (find_newline(str) >= 0)
		return (str);
	buffer = (char *)malloc(BUFFER_SIZE + 1);
	if (!buffer)
		return (free(str), NULL);
	bytes = 1;
	while (bytes != 0)
	{
		bytes = read(fd, buffer, BUFFER_SIZE);
		if (bytes == -1)
			return (free(buffer), free(str), NULL);
		buffer[bytes] = '\0';
		str = concat_str(str, buffer);
		if (!str || find_newline(buffer) >= 0)
			break ;
	}
	free(buffer);
	return (str);
}

static char	*get_line(char *str, int n)
{
	char	*line;

	if (!str || !*str)
		return (NULL);
	if (n == -1)
		n = ft_gnl_strlen(str) - 1;
	line = ft_substr(str, 0, n + 1);
	return (line);
}

static char	*get_remainder(char	*str, int n)
{
	char	*remainder;
	int		len;

	if (n < 0)
		return (free(str), NULL);
	len = ft_gnl_strlen(str) - n - 1;
	if (len == 0)
		return (free(str), NULL);
	remainder = ft_substr(str, n + 1, len);
	free(str);
	return (remainder);
}

char	*get_next_line(int fd)
{
	char		*line;
	static char	*str;
	int			newline;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	str = read_to_str(fd, str);
	newline = find_newline(str);
	line = get_line(str, newline);
	if (!line)
	{
		free(str);
		str = NULL;
		return (NULL);
	}
	str = get_remainder(str, newline);
	return (line);
}

/*#include<fcntl.h>
#include<stdio.h>

int	main(void)
{
	int		fd;
	int		i;
	char	*line;
	char	*path;

	path = "example.txt";
	fd = open(path, O_RDONLY);
	i = 0;
	while (1)
	{
		line = get_next_line(fd);
		printf("%i %s\n", i, line);
		i++;
		if (!line)
			break ;
		free(line);
	}
	close(fd);
}*/
