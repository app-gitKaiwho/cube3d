/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printx.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvon-war <lvonwar42@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 16:51:32 by lvon-war          #+#    #+#             */
/*   Updated: 2023/05/25 16:51:32 by lvon-war         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_libft.h"
#include "ft_printf.h"

int	printfx(unsigned long nbr, char mode)
{
	int	val;

	val = 0;
	if (nbr <= 0)
		return (printc('0'));
	if ((nbr / 16) > 0)
		val += printfx(nbr / 16, mode);
	if ((nbr % 16) >= 10)
		val += printc(((nbr % 16) - 10) + mode);
	else
		val += printnbr(nbr % 16);
	return (val);
}

int	printptr(void *ptr)
{
	int	val;

	val = 0;
	val += printstr("0x");
	val += printfx((unsigned long)ptr, 'a');
	return (val);
}
