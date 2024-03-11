/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvon-war <lvonwar42@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 16:47:11 by lvon-war          #+#    #+#             */
/*   Updated: 2023/05/25 16:47:11 by lvon-war         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_libft.h"

int	nbsize(long ln)
{
	int	size;

	size = 0;
	if (ln == 0)
		return (1);
	else if (ln < 0)
	{
		ln = ln * -1;
		size++;
	}
	while (ln > 0)
	{
		ln = ln / 10;
		size++;
	}
	return (size);
}

char	*ft_itoa(int n)
{
	char	*str;
	long	ln;
	size_t	i;

	ln = n;
	i = nbsize(ln);
	str = (char *) malloc(sizeof(char) * (i + 1));
	if (!str)
		return (NULL);
	str[i] = '\0';
	if (!ln)
		str[0] = '0';
	if (!ln)
		return (str);
	if (ln < 0)
		str[0] = '-';
	if (ln < 0)
		ln = ln * -1;
	while (ln > 0)
	{
		str[--i] = '0' + (ln % 10);
		ln = ln / 10;
	}
	return (str);
}
