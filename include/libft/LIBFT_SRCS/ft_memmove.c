/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvon-war <lvonwar42@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 15:10:08 by lvon-war          #+#    #+#             */
/*   Updated: 2023/05/25 16:46:03 by lvon-war         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	if (!dest && !src)
		return (NULL);
	else if (dest > src)
		while (n--)
			((char *)dest)[n] = ((char *)src)[n];
	else
		ft_memcpy(dest, src, n);
	return (dest);
}
