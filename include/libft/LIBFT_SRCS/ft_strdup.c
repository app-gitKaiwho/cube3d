/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvon-war <lvonwar42@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 16:48:25 by lvon-war          #+#    #+#             */
/*   Updated: 2023/05/25 16:48:25 by lvon-war         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_libft.h"

char	*ft_strdup(const char *s1)
{
	char	*dest;
	size_t	len;

	len = 0;
	while (s1[len])
		len++;
	dest = (char *) malloc(len + 1);
	if (!dest)
		return (NULL);
	ft_memcpy(dest, s1, len + 1);
	return (dest);
}
