# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: paradari <paradari@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/04 13:51:44 by kwangtip          #+#    #+#              #
#    Updated: 2025/06/26 10:52:51 by paradari         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SOURCES = sources/ft_print_char.c sources/ft_print_str.c sources/ft_printf.c\
          sources/ft_print_di.c sources/ft_print_u.c\
		  sources/ft_print_p.c sources/ft_print_x.c

SOURCES += sources/get_next_line.c sources/get_next_line_utils.c

SOURCES += sources/ft_isalpha.c sources/ft_isdigit.c sources/ft_isalnum.c\
			sources/ft_isascii.c sources/ft_isprint.c sources/ft_strlen.c\
			sources/ft_memset.c  sources/ft_bzero.c  sources/ft_memcpy.c\
			sources/ft_memmove.c sources/ft_toupper.c sources/ft_tolower.c\
			sources/ft_strchr.c sources/ft_strrchr.c sources/ft_strlcpy.c\
			sources/ft_strncmp.c sources/ft_memchr.c sources/ft_memcmp.c\
			sources/ft_putchar_fd.c  sources/ft_putendl_fd.c \
			sources/ft_putnbr_fd.c  sources/ft_putstr_fd.c\
			sources/ft_strdup.c sources/ft_strnstr.c sources/ft_strjoin.c\
			sources/ft_striteri.c sources/ft_calloc.c sources/ft_strlcat.c\
			sources/ft_itoa.c  sources/ft_atoi.c \
			sources/ft_strtrim.c sources/ft_split.c sources/ft_strmapi.c
  
OBJS = ${SOURCES:%.c=%.o}
NAME = libft.a
LIBC = ar -rcs
CC = cc
RM = rm -f
CFLAGS = -Wall -Wextra -Werror

HEADER = -Iincludes

all : ${NAME}

${NAME} : ${OBJS} sources/libft.h 
	${LIBC} ${NAME} ${OBJS}

$(OBJS): sources/%.o: sources/%.c sources/libft.h Makefile
	$(CC) $(CFLAGS) $(HEADER) -c $< -o $@

clean :
	${RM} ${OBJS}
fclean : clean
	${RM} ${NAME}

re : fclean all

.PHONY : all clean fclean re
