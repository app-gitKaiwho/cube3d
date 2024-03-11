/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_basicprint.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvon-war <lvonwar42@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 16:51:15 by lvon-war          #+#    #+#             */
/*   Updated: 2023/05/25 16:51:15 by lvon-war         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_libft.h"

int	printc(char c)
{
	write(1, &c, 1);
	return (1);
}

int	printstr(char *str)
{
	if (!str)
	{
		write(1, "(null)", 6);
		return (6);
	}
	write(1, str, ft_strlen(str));
	return (ft_strlen(str));
}

int	printnbr(int nbr)
{
	int		len;
	char	*str;

	str = ft_itoa(nbr);
	len = ft_strlen(str);
	write(1, str, len);
	if (str)
		free(str);
	return (len);
}
