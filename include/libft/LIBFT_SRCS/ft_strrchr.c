/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvon-war <lvonwar42@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 16:50:16 by lvon-war          #+#    #+#             */
/*   Updated: 2023/05/25 16:50:16 by lvon-war         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_libft.h"

char	*ft_strrchr(const char *str, int c)
{
	char			*ptr;
	unsigned char	cc;
	int				size;

	size = ft_strlen(str);
	cc = c;
	ptr = (char *)str;
	ptr += size;
	while (0 <= size)
	{
		if (*ptr == cc)
			return (ptr);
		ptr--;
		size--;
	}
	if (cc == '\0')
		return (ptr);
	return (0);
}
