/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvon-war <lvonwar42@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 16:48:00 by lvon-war          #+#    #+#             */
/*   Updated: 2023/05/25 16:48:00 by lvon-war         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	long	ln;

	ln = n;
	if (ln < 0)
	{
		ft_putchar_fd('-', fd);
			ln = ln * -1;
	}
	if (ln > 9)
		ft_putnbr_fd(ln / 10, fd);
	ft_putchar_fd((ln % 10) + '0', fd);
}
