/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_libft.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvon-war <lvon-war@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 13:50:06 by lvon-war          #+#    #+#             */
/*   Updated: 2024/03/11 10:06:15 by lvon-war         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LIBFT_H
# define FT_LIBFT_H

# include <unistd.h>
# include <stdlib.h>
# include <limits.h>
# include <fcntl.h>

typedef struct words
{
	int				wsize;
	int				pos;
	char			*mot;
	struct words	*last;
}words,	*t_list;

t_list	freelist(t_list li, int mode);
t_list	push_front(t_list li, int size, char *nw);
t_list	conevertlisttotab(t_list mots, char ***ptr);

char	*ft_itoa(int n);
int		ft_abs(int value);
int		ft_isalnum(int c);
int		ft_isalpha(int c);
int		ft_isdigit(int c);
int		ft_isascii(int c);
int		ft_isprint(int c);
int		ft_tolower(int c);
int		ft_toupper(int c);
void	swap(int *a, int *b);
int		ft_atoi(const char *str);
int		ft_strlen(const char *str);
int		is_whitespace(const char c);
void	ft_putnbr_fd(int n, int fd);
char	*ft_strdup(const char *str);
int		ft_power(int nb, int power);
void	*ft_bzero(void *s, size_t n);
void	ft_putchar_fd(char c, int fd);
void	ft_putstr_fd(char *s, int fd);
void	ft_putendl_fd(char *s, int fd);
char	*ft_strjoinmore(int count, ...);
int		ft_strstartw(char *str, char c);
char	**ft_split(char const *s, char c);
void	*ft_calloc(size_t n, size_t size);
void	ft_rev_int_tab(int *tab, int size);
char	*ft_strchr(const char *str, int c);
char	*ft_strrchr(const char *str, int c);
void	*ft_memset(void *s, int c, size_t n);
void	*ft_memchr(const void *s, int c, size_t n);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_strtrim(const char *s1, const char *set);
size_t	ft_strlcat(char *dest, char *src, size_t size);
void	*ft_memcpy(void *dest, const void *src, size_t n);
size_t	ft_strlcpy(char *dest, const char *src, size_t n);
void	*ft_memmove(void *dest, const void *src, size_t n);
int		ft_memcmp(const void *s1, const void *s2, size_t n);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
void	ft_striteri(char *s, void (*f)(unsigned int, char *));
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	*ft_strmapi(char const *s, char (*f)(unsigned int, char));
char	*ft_strnstr(const char *str, const char *to_find, size_t n);

#endif /* !FT_LIBFT_H */