/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvon-war <lvonwar42@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 16:49:54 by lvon-war          #+#    #+#             */
/*   Updated: 2023/05/25 16:49:54 by lvon-war         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	size_t	i;
	char	*ptr;

	i = 0;
	if (s == NULL || f == NULL)
		return (NULL);
	ptr = (char *) malloc((sizeof(char) * (ft_strlen(s) + 1)));
	if (ptr == NULL)
		return (NULL);
	ft_strlcpy(ptr, s, (ft_strlen(s) + 1));
	while (ptr[i])
	{
		ptr[i] = (*f)(i, ptr[i]);
		i++;
	}
	return (ptr);
}
