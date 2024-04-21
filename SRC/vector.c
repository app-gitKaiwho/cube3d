/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spook <spook@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/19 10:20:33 by lvon-war          #+#    #+#             */
/*   Updated: 2024/04/21 00:16:33 by spook            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

t_vector2d	rmdepth(t_vector v)
{
	t_vector2d	v2d;

	v2d.a = (t_point2d){v.a.x, v.a.y};
	v2d.b = (t_point2d){v.b.x, v.b.y};
	return (v2d);
}

t_vector	vec3cast(t_vector v, t_data d)
{
	t_vector	casted;

	casted.a = pointcast(v.a, d);
	casted.b = pointcast(v.b, d);
	return (casted);
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
	if (steps == 0)
		steps = 0.0001;
	delta.x = delta.x / steps;
	delta.y = delta.y / steps;
	return (delta);
}
