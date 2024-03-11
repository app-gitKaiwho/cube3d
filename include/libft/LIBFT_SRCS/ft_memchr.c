/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvon-war <lvonwar42@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 16:47:20 by lvon-war          #+#    #+#             */
/*   Updated: 2023/05/25 16:47:20 by lvon-war         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	*ptr;
	unsigned char	cc;

	i = 0;
	cc = c;
	ptr = (unsigned char *)s;
	while (i < n)
	{
		if (*ptr == cc)
			return (ptr);
		ptr++;
		i++;
	}
	if (cc == '\0' && n != 0)
		return (NULL);
	return (NULL);
}
