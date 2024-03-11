/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvon-war <lvonwar42@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 16:45:29 by lvon-war          #+#    #+#             */
/*   Updated: 2023/05/25 16:45:29 by lvon-war         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_libft.h"

void	*ft_calloc(size_t n, size_t size)
{
	void	*ptr;

	ptr = malloc(size * n);
	if (!ptr)
		return (NULL);
	return (ft_bzero(ptr, size * n));
}
