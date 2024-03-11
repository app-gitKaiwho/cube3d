/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvon-war <lvonwar42@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 16:49:24 by lvon-war          #+#    #+#             */
/*   Updated: 2023/05/25 16:49:24 by lvon-war         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_libft.h"

size_t	ft_strlcpy(char *dest, const char *src, size_t n)
{	
	size_t	i;
	size_t	lensize;

	i = 0;
	lensize = ft_strlen(src);
	if (!dest || !src)
		return (0);
	while (i < lensize && i + 1 < n)
	{	
		dest[i] = src[i];
		i++;
	}
	if (i < n)
		dest[i] = '\0';
	return (lensize);
}
