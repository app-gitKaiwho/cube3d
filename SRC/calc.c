/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calc.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spook <spook@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/15 11:14:25 by lvon-war          #+#    #+#             */
/*   Updated: 2024/04/28 13:36:12 by spook            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

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

int	ispolyseen(t_player p, t_polygon poly)
{
	int			i;
	t_vector	n;
	t_point		d;
	t_vector	tocheck;

	n.a = (t_point){poly.edges[1].a.x - poly.edges[0].a.x, poly.edges[1].a.y
		- poly.edges[0].a.y, poly.edges[1].a.z - poly.edges[0].a.z};
	n.b = (t_point){poly.edges[2].a.x - poly.edges[0].a.x, poly.edges[2].a.y
		- poly.edges[0].a.y, poly.edges[2].a.z - poly.edges[0].a.z};
	poly.normal = vectounivec((t_point){n.a.y * n.b.z - n.a.z * n.b.y,
			n.a.z * n.b.x - n.a.x * n.b.z, n.a.x * n.b.y - n.a.y * n.b.x});
	d = vectounivec((t_point){poly.edges[0].a.x - p.pos.x, poly.edges[0].a.y
			- (p.pos.y + p.size.y), poly.edges[0].a.z - p.pos.z});
	if (poly.normal.x * d.x + poly.normal.y * d.y + poly.normal.z * d.z > 0)
		return (0);
	i = -1;
	while (++i < 3)
	{
		tocheck = poly.edges[i];
		if (ispointincast(p.pos, p.cast[0], p.cast[1], tocheck.a)
			|| (ispointincast(p.pos, p.cast[0], p.cast[1], tocheck.b)))
			return (1);
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

t_point	pointcast(t_point point, t_data d)
{
	t_point	casted;
	t_point	delta;

	delta.x = point.x - d.player.pos.x;
	delta.y = point.y - d.player.pos.y - d.player.size.y;
	delta.z = point.z - d.player.pos.z;
	delta = rotation_y(delta, d);
	casted.x = (delta.x * d.focal) / delta.z;
	casted.y = (delta.y * d.focal) / delta.z;
	casted.x = casted.x + (d.width * 0.5);
	casted.y = casted.y + (d.height * 0.5);
	casted.z = point.z;
	return (casted);
}

void	swapdouble(double *a, double *b)
{
	double	tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}
