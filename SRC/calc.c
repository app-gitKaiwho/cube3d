/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calc.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvon-war <lvonwar@gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/15 11:14:25 by lvon-war          #+#    #+#             */
/*   Updated: 2024/03/25 18:25:01 by lvon-war         ###   ########.fr       */
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

/// @brief check is a pos is in player view
/// @param p player pos 
/// @param tocheck pos of the point
/// @return 1 for yes 0 for no
int	IsPointInCast(t_point p, t_point A, t_point B, t_point tocheck)
{
	double	denominator;
	double	a;
	double	b;
	double	c;

	denominator = ((A.z - B.z) * (p.x - B.x) + (B.x - A.x) * (p.z - B.z));
	a = ((A.z - B.z) * (tocheck.x - B.x)
			+ (B.x - A.x) * (tocheck.z - B.z)) / denominator;
	b = ((B.z - p.z) * (tocheck.x - B.x)
			+ (p.x - B.x) * (tocheck.x - B.z)) / denominator;
	c = 1 - a - b;
	if (a >= 0 && a <= 1 && b >= 0 && b <= 1 && c >= 0 && c <= 1)
		return (1);
	return (0);
}

int	isobjectincast(t_player p, t_object obj)
{
	t_point	a;
	t_point	b;
	t_point	offset;
	t_point	tocheck;
	int		it_is;

	it_is = 0;
	offset.x = obj.size.x / 2;
	offset.z = obj.size.z / 2;
	a = (t_point){p.cast[0].x, p.cast[0].y, p.cast[0].z};
	b = (t_point){p.cast[1].x, p.cast[1].y, p.cast[1].z};
	tocheck = (t_point){obj.pos.x - offset.x, obj.pos.y, obj.pos.z - offset.z};
	it_is |= IsPointInCast(p.pos, a, b, tocheck);
	tocheck = (t_point){obj.pos.x - offset.x, obj.pos.y, obj.pos.z + offset.z};
	it_is |= IsPointInCast(p.pos, a, b, tocheck);
	tocheck = (t_point){obj.pos.x + offset.x, obj.pos.y, obj.pos.z - offset.z};
	it_is |= IsPointInCast(p.pos, a, b, tocheck);
	tocheck = (t_point){obj.pos.x + offset.x, obj.pos.y, obj.pos.z + offset.z};
	it_is |= IsPointInCast(p.pos, a, b, tocheck);
	tocheck = (t_point){obj.pos.x, obj.pos.y, obj.pos.z};
	it_is |= IsPointInCast(p.pos, a, b, tocheck);
	return (it_is);
}
