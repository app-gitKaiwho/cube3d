/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printu.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvon-war <lvonwar42@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 16:51:27 by lvon-war          #+#    #+#             */
/*   Updated: 2023/05/25 16:51:27 by lvon-war         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_libft.h"
#include "ft_printf.h"

int	printunbr(unsigned int n)
{
	int	i;

	i = 0;
	if (n >= 10)
	{
		i += printnbr(n / 10);
		i += printnbr(n % 10);
	}
	else
		i += printc(n + 48);
	return (i);
}

int	printsubone(double n, int msvp)
{
	int	lsvp;
	int	size;
	int	i;

	i = 0;
	lsvp = 0;
	size = 0;
	while (i++ < msvp)
		size += printc('0');
	size += printnbr(n * ft_power(10, 6));
	return (size);
}

int	printdouble(double n)
{
	int		i;
	int		j;
	int		size;
	int		over;
	double	under;

	i = 0;
	over = (int)n;
	size = printnbr(over);
	size += printc('.');
	under = n - over;
	while
	((int)(under * ft_power(10, i)) <= 0 && i++ < 20);
	if (i >= 10)
		size += printstr("00");
	else
		size += printsubone(under, i - 1);
	return (size);
}
