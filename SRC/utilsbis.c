/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utilsbis.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvon-war <lvonwar@gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 09:31:48 by lvon-war          #+#    #+#             */
/*   Updated: 2024/04/02 18:37:59 by lvon-war         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

t_polygon	pointtopolygone(t_point a, t_point b, t_point c)
{
	t_polygon	poly;

	poly.edges[0] = (t_vector){a, b};
	poly.edges[1] = (t_vector){b, c};
	poly.edges[2] = (t_vector){c, a};
	return (poly);
}

double	degtorad(double degree)
{
	return (degree * M_PI / 180);
}

t_vector2d	vec3cast(t_vector v, t_data d)
{
	t_vector2d	casted;

	casted.a = pointcast(v.a, d);
	casted.b = pointcast(v.b, d);
	return (casted);
}

t_point	vectounivec(t_point v)
{
	if (v.x != 0)
		v.x /= fabs(v.x);
	if (v.y != 0)
		v.y /= fabs(v.y);
	if (v.z != 0)
		v.z /= fabs(v.z);
	return (v);
}
