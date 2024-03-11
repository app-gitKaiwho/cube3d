/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvon-war <lvonwar42@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 16:48:19 by lvon-war          #+#    #+#             */
/*   Updated: 2023/05/25 16:48:19 by lvon-war         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_libft.h"

char	*ft_strchr(const char *str, int c)
{
	char			*ptr;
	unsigned char	cc;

	cc = c;
	ptr = (char *)str;
	while (*ptr)
	{
		if (*ptr == cc)
			return (ptr);
		ptr++;
	}
	if (cc == '\0')
		return (ptr);
	return (0);
}
