/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calc.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvon-war <lvon-war@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/15 11:14:25 by lvon-war          #+#    #+#             */
/*   Updated: 2024/04/01 13:52:36 by lvon-war         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

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
	if (steps == 0)
		steps = 0.0001;
	delta.x = delta.x / steps;
	delta.y = delta.y / steps;
	return (delta);
}

/// @brief check is a pos is in player view
/// @param p player pos 
/// @param tocheck pos of the point
/// @return 1 for yes 0 for no
int	ispointincast(t_point p, t_point A, t_point B, t_point tocheck)
{
	double	denominator;
	double	a;
	double	b;
	double	c;

	denominator = ((A.z - B.z) * (p.x - B.x) + (B.x - A.x) * (p.z - B.z));
	if (denominator == 0)
		return (0);
	a = ((A.z - B.z) * (tocheck.x - B.x)
			+ (B.x - A.x) * (tocheck.z - B.z)) / denominator;
	b = ((B.z - p.z) * (tocheck.x - B.x)
			+ (p.x - B.x) * (tocheck.z - B.z)) / denominator;
	c = 1 - a - b;
	if (a >= 0 && a <= 1 && b >= 0 && b <= 1 && c >= 0 && c <= 1)
		return (1);
	return (0);
}

int	ispolyincast(t_player p, t_polygon poly)
{
	int		i;
	t_point	tocheck;

	i = 0;
	while (i < 3)
	{
		tocheck = poly.edges[i].a;
		if (ispointincast(p.pos, p.cast[0], p.cast[1], tocheck))
			return (1);
		tocheck = poly.edges[i].b;
		if (ispointincast(p.pos, p.cast[0], p.cast[1], tocheck))
			return (1);
		i++;
	}
	return (0);
}

t_point	rotation_y(t_point point, t_data d)
{
	t_point	rotated;
	t_point	angle;

	angle.y = (((d.player.angle.y) * M_PI) / 180);
	rotated.x = point.x * cos(angle.y) + point.z * sin(angle.y);
	rotated.y = point.y;
	rotated.z = -point.x * sin(angle.y) + point.z * cos(angle.y);
	return (rotated);
}

t_point2d	pointcast(t_point point, t_data d)
{
	t_point2d	casted;
	t_point		delta;

	delta.x = point.x - d.player.pos.x;
	delta.y = point.y - d.player.pos.y - d.player.size.y;
	delta.z = point.z - d.player.pos.z;
	delta = rotation_y(delta, d);
	casted.x = (delta.x * d.focal) / delta.z;
	casted.y = (delta.y * d.focal) / delta.z;
	casted.x = casted.x + (WL / 2);
	casted.y = casted.y + (WH / 2);
	return (casted);
}

t_vector2d	vec3cast(t_vector v, t_data d)
{
	t_vector2d	casted;

	casted.a = pointcast(v.a, d);
	casted.b = pointcast(v.b, d);
	return (casted);
}
