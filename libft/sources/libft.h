/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwangtip <kwangtip@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/04 19:47:41 by kwangtip          #+#    #+#             */
/*   Updated: 2023/11/28 15:48:53 by kwangtip         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

// get_next_line

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif

# include <fcntl.h>
# include <limits.h>
# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>

// Libft

int		ft_isalnum(int c);
int		ft_isalpha(int c);
int		ft_isascii(int c);
int		ft_isdigit(int c);
int		ft_isprint(int c);

void	*ft_memchr(const void *s, int c, int n);
int		ft_memcmp(const void *s1, const void *s2, int n);
void	*ft_memcpy(void *dst, void const *src, int n);
void	*ft_memmove(void *dst, const void *src, int len);
void	*ft_memset(void *b, int c, int len);

int		ft_tolower(int c);
int		ft_toupper(int c);

char	*ft_strchr(const char *s, int c);
int		ft_strlcpy(char *dst, const char *src, int detsize);
int		ft_strlen(const char *str);
int		ft_strncmp(const char *s1, const char *s2, int n);
char	*ft_strrchr(const char *s, int c);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_strdup(const char *s1);
void	ft_striteri(char *s, void (*f)(unsigned int, char *));
char	*ft_strnstr(const char *haystack, const char *needle, int len);

void	ft_bzero(void *s, int n);
void	ft_putchar_fd(char c, int fd);
void	ft_putendl_fd(char *s, int fd);
void	ft_putstr_fd(char *s, int fd);
void	ft_putnbr_fd(int n, int fd);

void	*ft_calloc(int count, int size);
int		ft_strlcat(char *dst, const char *src, int dstsize);
char	*ft_itoa(int n);
int		ft_atoi(const char *str);
// char		*ft_substr(char const *s, int start, int len);
char	*ft_strtrim(char const *s1, char const *set);
char	**ft_split(char const *s, char c);
char	*ft_strmapi(char const *s, char (*f)(unsigned int, char));

// printf

int		ft_printf(const char *str, ...);
int		ft_print_char(int c);
int		ft_print_str(char *c);
int		ft_print_di(int args);
int		ft_print_u(unsigned int args);
int		ft_print_p(unsigned long long int args);
int		ft_print_x(unsigned int args, char str);

// grt_next_line

char	*get_next_line(int fd);
size_t	ft_gnl_strlen(const char *s);
int		find_newline(const char *str);
char	*concat_str(char *s1, char *s2);
char	*ft_substr(char const *s, unsigned int start, size_t len);

#endif
