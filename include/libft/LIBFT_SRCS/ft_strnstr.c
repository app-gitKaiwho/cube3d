/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvon-war <lvonwar42@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 16:50:10 by lvon-war          #+#    #+#             */
/*   Updated: 2023/05/25 16:50:10 by lvon-war         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_libft.h"

char	*ft_strnstr(const char *str, const char *to_find, size_t n)
{
	size_t	i;
	int		len;

	if (!*to_find)
		return ((char *)str);
	if (!*str)
		return (0);
	i = 0;
	len = ft_strlen(to_find);
	while (str[i] && i + len - 1 < n)
	{
		if (!ft_memcmp(str + i, to_find, len))
			return ((char *) str + i);
		i++;
	}
	return (0);
}
