/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvon-war <lvonwar42@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 13:43:31 by lvon-war          #+#    #+#             */
/*   Updated: 2023/05/25 16:46:02 by lvon-war         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	int			i;
	char		*ptr;
	const char	*srcptr;

	i = -1;
	if (!dest && !src)
		return (ft_strdup(""));
	ptr = dest;
	srcptr = src;
	while ((size_t)++i < n)
		*ptr++ = srcptr[i];
	return (dest);
}
