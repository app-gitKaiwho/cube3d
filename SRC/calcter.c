/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calcter.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvon-war <lvon-war@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/19 10:14:06 by lvon-war          #+#    #+#             */
/*   Updated: 2024/04/19 10:45:32 by lvon-war         ###   ########.fr       */
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

double	slope(t_point a, t_point b)
{
	if (delta(a.x, b.x) == 0)
		return (0);
	return ((double)delta(a.y, b.y) / (double)delta(a.x, b.x));
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