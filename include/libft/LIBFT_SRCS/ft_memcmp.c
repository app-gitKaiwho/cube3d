/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvon-war <lvonwar42@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 16:47:28 by lvon-war          #+#    #+#             */
/*   Updated: 2023/05/25 16:47:28 by lvon-war         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t				i;
	const unsigned char	*ptr1;
	const unsigned char	*ptr2;

	ptr1 = s1;
	ptr2 = s2;
	i = 0;
	if (n == 0 || (!ptr1 && !ptr2))
		return (0);
	while (i + 1 < n)
	{
		if (ptr1[i] != ptr2[i])
			break ;
		i++;
	}
	return ((unsigned char)ptr1[i] - (unsigned char)ptr2[i]);
}
