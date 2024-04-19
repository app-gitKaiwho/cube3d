/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utilsbis.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvon-war <lvon-war@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 09:31:48 by lvon-war          #+#    #+#             */
/*   Updated: 2024/04/19 15:22:52 by lvon-war         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

t_polygon	pointtopolygone(t_point a, t_point b, t_point c)
{
	t_polygon	poly;

	poly.verti[0] = a;
	poly.verti[1] = b;
	poly.verti[2] = c;
	poly.edges[0] = (t_vector){a, b};
	poly.edges[1] = (t_vector){b, c};
	poly.edges[2] = (t_vector){c, a};
	return (poly);
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
