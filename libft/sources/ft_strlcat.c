/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwangtip <kwangtip@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/15 19:10:21 by kwangtip          #+#    #+#             */
/*   Updated: 2023/11/28 15:48:53 by kwangtip         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strlcat(char *dst, const char *src, int dstsize)
{
	int		i;
	int		j;
	int		dst_size;
	int		src_size;

	dst_size = ft_strlen(dst);
	src_size = ft_strlen(src);
	if (dstsize <= dst_size)
		return (dstsize + src_size);
	i = dst_size;
	j = 0;
	while ((i + j) < (dstsize -1) && src[j] != '\0')
	{
		dst [i + j] = src [j];
		j++;
	}
	dst [i + j] = '\0';
	return (dst_size + src_size);
}
/*
#include <stdio.h>
#include <string.h>
int	main(void)
{
printf("test 1 \n");
char dst[] = "";
char src[] = "Me";

printf("%zu\n",  ft_strlcat(dst, src, 0));
printf("%zu\n",  strlcat(dst, src, 0));


printf("test 2 \n");
char dst1[] = "123456789012345";
char src1[] = "lololololo";

printf("%zu\n",  ft_strlcat(dst1, src1, 6));
printf("%zu\n",  strlcat(dst1, src1, 6));

printf("test 3 \n");

char src2[20] = "lololo";
char dst2[20] = "1234567890";
printf("%zu\n",  ft_strlcat(dst2, src2, 20));
printf("%zu\n",  strlcat(dst2, src2, 20));
}
*/
