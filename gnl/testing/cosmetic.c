/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cosmetic.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsomchan <tsomchan@student.42bangkok.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/31 14:57:55 by tsomchan          #+#    #+#             */
/*   Updated: 2025/05/09 15:24:20 by tsomchan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <libc.h>
#include "../testing/myft.h"

void	banner_border(int len)
{
	int	i;

	ft_color("blue");
	printf("o");
	i = len + 2;
	while (--i >= 0)
		printf("-");
	printf("o\n");
	ft_color("reset");
}

void	banner(char *str, char *desc)
{
	int	len;
	int	i;

	i = -1;
	if (*desc == 0)
		len = cub_strlen(str);
	else
		len =cub_strlen(str) +cub_strlen(desc) + 3;
	banner_border(len);
	printcolor("|", "blue");
	ft_color("white");
	printf(" %s ", str);
	printcolor("| ", "blue");
	if (*desc != 0)
	{
		printcolor(desc, "black");
		printcolor(" |", "blue");
	}
	printf("\n");
	banner_border(len);
}

void	divider_start(void)
{
	printf("");
}

void	divider_end(void)
{
	ft_color("blue");
	printf("o-------------------------------------- --- -- -\n");
	ft_color("reset");
}

void	program_header(void)
{
	ft_color("purple");
	printf("o-------------------------------------- --- -- -\n");
	printf("o------------------------------- -- --- -\n");
	printf("o------------------------ --- -- -\n");
	printf("o----------------- -- -- -- -\n");
	ft_color("reset");
}
