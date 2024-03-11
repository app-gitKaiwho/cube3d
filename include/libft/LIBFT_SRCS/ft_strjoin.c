/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvon-war <lvonwar42@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 16:48:57 by lvon-war          #+#    #+#             */
/*   Updated: 2023/05/25 16:48:57 by lvon-war         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_libft.h"
#include "ft_printf.h"
#include <stdarg.h>

char	*ft_strjoin(const char *s1, const char *s2)
{
	char	*res;
	size_t	leni;
	size_t	lenj;	

	leni = ft_strlen(s1);
	lenj = ft_strlen(s2);
	res = (char *) malloc((leni + lenj + 1) * sizeof(char));
	if (!res)
		return (NULL);
	ft_memcpy(res, s1, leni);
	ft_memcpy(res + leni, s2, lenj);
	res[leni + lenj] = '\0';
	return (res);
}

/// @brief join as many string as you want.
/// @param count number of strings to join.
/// @param strings to join only, behavior is undefined for anything else.
/// @return  null if less than 2 strings are given, fused string otherwise.
/// but if a null is passed, the function will stop and return the fused string,
/// up to the null.
char	*ft_strjoinmore(int count, ...)
{
	va_list	args;
	char	*flip;
	char	*flop;
	char	*tmp;
	int		i;

	flip = NULL;
	va_start (args, count);
	i = 2;
	if (count >= 2)
		flip = ft_strjoin(va_arg(args, char *), va_arg(args, char *));
	while (i < count)
	{
		tmp = va_arg(args, char *);
		if (!tmp)
			break ;
		flop = ft_strjoin(flip, tmp);
		if (flip)
		{
			free(flip);
			flip = flop;
		}
		i++;
	}
	return (flip);
}
