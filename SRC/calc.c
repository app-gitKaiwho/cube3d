/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calc.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvon-war <lvonwar@gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/15 11:14:25 by lvon-war          #+#    #+#             */
/*   Updated: 2024/03/24 23:07:28 by lvon-war         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

//unused function
double	calculate_slope(t_vector AB)
{
	double	dy;
	double	dx;
	double	slope;

	dy = AB.b.y - AB.a.y;
	dx = AB.b.x - AB.a.x;
	slope = dy / dx;
	return (slope);
}

t_point	vecdeltacalc(t_vector V)
{
	t_point	delta;
	double	steps;

	if (V.b.x > V.a.x)
		delta.x = V.b.x - V.a.x;
	else
		delta.x = V.a.x - V.b.x;
	if (V.b.y > V.a.y)
		delta.y = V.b.y - V.a.y;
	else
		delta.y = V.a.y - V.b.y;
	if (fabs(delta.x) > fabs(delta.y))
		steps = fabs(delta.x);
	else
		steps = fabs(delta.y);
	delta.x = delta.x / steps;
	delta.y = delta.y / steps;
	return (delta);
}

int	isPointInCast(float x1, float y1, float x2, float y2, float x3, float y3, float x, float y)
{
	float	denominator;
	float	a;
	float	b;
	float	c;

	denominator = ((y2 - y3)*(x1 - x3) + (x3 - x2)*(y1 - y3));
	a = ((y2 - y3)*(x - x3) + (x3 - x2)*(y - y3)) / denominator;
	b = ((y3 - y1)*(x - x3) + (x1 - x3)*(y - y3)) / denominator;
	c = 1 - a - b;
	if (a >= 0 && a <= 1 && b >= 0 && b <= 1 && c >= 0 && c <= 1)
		return (1);
	return (0);
}
