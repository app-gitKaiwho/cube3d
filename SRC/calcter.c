/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calcter.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spook <spook@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/19 10:14:06 by lvon-war          #+#    #+#             */
/*   Updated: 2024/04/28 12:37:57 by spook            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

int	delta(int a, int b)
{
	if (a > b)
		return (a - b);
	else
		return (b - a);
}

double	deltadouble(double a, double b)
{
	if (a > b)
		return (a - b);
	return (b - a);
}

double	degtorad(double degree)
{
	return (degree * M_PI / 180);
}

void	swappoints(t_point *a, t_point *b)
{
	t_point	tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

void	swappoints2d(t_point2d *a, t_point2d *b)
{
	t_point2d	tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}
