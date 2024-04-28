/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calcquater.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spook <spook@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/28 09:40:07 by spook             #+#    #+#             */
/*   Updated: 2024/04/28 12:48:32 by spook            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

float	getstep(t_point a, t_point b)
{
	float	deltax;
	float	deltay;

	deltax = a.x - b.x;
	deltay = a.y - b.y;
	if ((deltax) == 0)
		deltax = 1;
	if ((deltay) == 0)
		deltay = 1;
	return (deltax / deltay);
}

///	@brief check if a point is out of the window. 
/// based on vector's direction unused
int	break_point(t_data d, t_vector2d AB, t_point2d current)
{
	int	is_out;

	is_out = 0;
	if (AB.a.x > AB.b.x && current.x < 0)
		is_out = 1;
	else if (current.x > d.width)
		is_out = 1;
	if (AB.a.y > AB.b.y && current.y < 0)
		is_out = 1;
	else if (current.y > d.height)
		is_out = 1;
	return (is_out);
}
