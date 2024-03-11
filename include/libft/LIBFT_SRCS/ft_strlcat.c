/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvon-war <lvonwar42@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 16:49:17 by lvon-war          #+#    #+#             */
/*   Updated: 2023/05/25 16:49:17 by lvon-war         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_libft.h"

size_t	ft_strlcat(char *dest, char *src, size_t size)
{
	size_t	dstlen;
	size_t	srclen;
	size_t	i;

	i = 0;
	dstlen = ft_strlen(dest);
	srclen = ft_strlen(src);
	while (src[i] && dstlen + i + 1 < size)
	{
		dest[dstlen + i] = src[i];
		i++;
	}
	dest[i + dstlen] = '\0';
	if (dstlen >= size)
		dstlen = size;
	return (dstlen + srclen);
}
