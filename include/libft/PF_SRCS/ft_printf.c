/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvon-war <lvonwar42@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 16:51:22 by lvon-war          #+#    #+#             */
/*   Updated: 2023/05/25 16:51:22 by lvon-war         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_libft.h"
#include "ft_printf.h"

int	printfmain(char c, va_list args)
{
	int	val;

	val = 0;
	if (c == 'c')
		val = (printc(va_arg(args, int)));
	else if (c == 's')
		val = (printstr(va_arg(args, char *)));
	else if (c == 'i' || c == 'd')
		val = (printnbr(va_arg(args, int)));
	else if (c == 'u')
		val = (printunbr(va_arg(args, unsigned int)));
	else if (c == 'x')
		val = (printfx(va_arg(args, unsigned int), 'a'));
	else if (c == 'X')
		val = (printfx(va_arg(args, unsigned int), 'A'));
	else if (c == '%')
		val = (printc('%'));
	else if (c == 'p')
		val = (printptr(va_arg(args, void *)));
	else if (c == 'f')
		val = (printdouble(va_arg(args, double)));
	return (val);
}

int	ft_printf(const char *str, ...)
{
	size_t	i;
	int		size;
	va_list	args;

	va_start (args, str);
	i = 0;
	size = 0;
	while (str[i])
	{
		if (str[i] == '%')
		{
			if (((unsigned long)ft_strlen(str) > i + 1))
			{
				size += printfmain(str[i + 1], args);
				i++;
			}
		}
		else
		{
			write(1, &str[i], 1);
			size++;
		}
		i++;
	}
	return (size);
}
