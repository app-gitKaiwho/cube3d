/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvon-war <lvonwar42@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/08 11:07:56 by lvon-war          #+#    #+#             */
/*   Updated: 2023/05/25 16:45:01 by lvon-war         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_libft.h"

int	nbrsize(const char *str)
{
	int	len;
	int	i;

	len = 0;
	i = -1;
	while (str[++i])
		if (str[i] >= '0' && str[i] <= '9' || str[i] == '-' || str[i] == '+')
			len++;
	return (len);
}

int	ft_atoi(const char *str)
{
	int		signe;
	int		size;
	long	val;
	int		i;

	signe = 1;
	val = 0;
	i = 0;
	size = nbrsize(str);
	while (is_whitespace(str[i]))
		i++;
	if (str[i] == '-' || str[i] == '+')
		if (str[i] == '-')
			signe *= -1;
	if (str[i] == '-' || str[i] == '+')
		i++;
	while (str[i] >= '0' && str[i] <= '9')
	{
		val += (str[i] - '0') * ft_power((10), size - i - 1);
		i++;
	}
	if (size != i)
		val /= ft_power((10), size - i);
	return (val * signe);
}
