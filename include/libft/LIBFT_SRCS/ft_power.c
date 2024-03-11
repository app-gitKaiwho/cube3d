/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_power.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvon-war <lvonwar42@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/12 17:20:01 by lvon-war          #+#    #+#             */
/*   Updated: 2023/05/25 16:46:06 by lvon-war         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_libft.h"

int	ft_power(int nb, int power)
{
	int	val;

	val = 1;
	if (power < 0)
		return (0);
	if (power > 0)
		val = nb * ft_power(nb, power - 1);
	return (val);
}
