/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calc.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvon-war <lvon-war@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/15 11:14:25 by lvon-war          #+#    #+#             */
/*   Updated: 2024/03/29 17:33:01 by lvon-war         ###   ########.fr       */
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
			+ (p.x - B.x) * (tocheck.x - B.z)) / denominator;
	c = 1 - a - b;
	if (a >= 0 && a <= 1 && b >= 0 && b <= 1 && c >= 0 && c <= 1)
		return (1);
	//return (0);
	return (1);
}

int	isobjectincast(t_player p, t_object obj)
{
	int		i;
	t_point	tocheck;

	i = 0;
	while (i < 8)
	{
		tocheck = obj.verti[i];
		if (ispointincast(p.pos, p.cast[0], p.cast[1], tocheck))
			return (1);
		i++;
	}
	return (0);
}

t_point2d	pointcast(t_point point, t_data d)
{
	t_point2d	casted;
	double		deltaz;
	t_point		rot;

	rot.x = d.focal * sin(degtorad(d.player.angle.y - 90));
	rot.y = d.focal * cos(degtorad(d.player.angle.y - 90));
	deltaz = point.z - d.player.pos.z;
	if (deltaz == 0)
		deltaz = 0.0001;
	casted.x = ((point.x - d.player.pos.x) * (d.focal)) / deltaz;
	casted.y = ((point.y - d.player.pos.y - d.player.size.y)
			* (d.focal)) / deltaz;
	casted.x = casted.x + rot.x + (WL / 2);
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
