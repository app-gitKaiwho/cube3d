/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utilsbis.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvon-war <lvon-war@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 09:31:48 by lvon-war          #+#    #+#             */
/*   Updated: 2024/03/29 16:28:37 by lvon-war         ###   ########.fr       */
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

