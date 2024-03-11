/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvon-war <lvonwar42@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 16:50:36 by lvon-war          #+#    #+#             */
/*   Updated: 2023/05/25 16:50:36 by lvon-war         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_libft.h"

char	*ft_substr(const char *s, unsigned int start, size_t len)
{
	char	*str;
	size_t	i;

	i = ft_strlen(s);
	if (!s)
		return (NULL);
	if (start > i)
		return (malloc(1));
	if (len > i + start)
		len = i + start;
	str = malloc((len + 1) * sizeof(char));
	if (!str)
		return (NULL);
	ft_memcpy(str, s + start, len);
	str[len] = '\0';
	return (str);
}
