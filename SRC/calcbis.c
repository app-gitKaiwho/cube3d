/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calcbis.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spook <spook@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/03 14:23:39 by lvon-war          #+#    #+#             */
/*   Updated: 2024/04/21 04:08:47 by spook            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

int	interpolator(t_point start, t_point end, int y)
{
	double	percent;
	double	deltax;
	double	deltay;

	if (start.y == end.y)
		return (start.x);
	deltax = (double)(start.x - end.x);
	deltay = (double)(start.y - end.y);
	percent = (double)(y - start.y) / (deltay);
	return (round(start.x + (deltax * percent)));
}

double	interpolator2d(t_point2d start, t_point2d end, double y)
{
	double	percent;
	double	deltax;
	double	deltay;

	if (start.y == end.y)
		return (start.x);
	deltax = start.x - end.x;
	deltay = start.y - end.y;
	percent = (y - start.y) / deltay;
	return (start.x + (deltax * percent));
}

//return is bend direction : right 1, left 0
int	sortscanlines(t_polygon *p)
{
	if (p->verti[1].y > p->verti[0].y)
	{
		swappoints(&p->verti[0], &p->verti[1]);
		swappoints2d(&p->texturepos[0], &p->texturepos[1]);
	}
	if (p->verti[2].y > p->verti[1].y)
	{
		swappoints(&p->verti[1], &p->verti[2]);
		swappoints2d(&p->texturepos[1], &p->texturepos[2]);
		if (p->verti[1].y >= p->verti[0].y)
		{
			swappoints(&p->verti[1], &p->verti[0]);
			swappoints2d(&p->texturepos[1], &p->texturepos[0]);
		}
	}
	return (0);
}

void	lineinterpolation(t_data *d, t_iterator it, t_polygon p)
{
	int	inc;

	if (it.i > it.j)
		inc = -1;
	if (it.i < it.j)
		inc = 1;
	while (it.i != it.j)
	{
		put_pixel((t_pixel){it.i, it.k, polygon_get_color(p, it.k)}, d);
		it.i += inc;
	}
}

void	pixelinterpolation(t_data *d, t_polygon p)
{
	int	i;
	int	l;
	int	r;

	i = p.verti[0].y;
	while (i > p.verti[2].y)
	{
		if (i >= p.verti[1].y)
			l = interpolator(p.verti[0], p.verti[1], i);
		else
			l = interpolator(p.verti[1], p.verti[2], i);
		r = interpolator(p.verti[2], p.verti[0], i);
		lineinterpolation(d, (t_iterator){l, r, i}, p);
		i--;
	}
}

void	rasterizer(t_data *d, t_polygon p)
{
	t_polygon	a;

	a = p;
	sortscanlines(&a);
	pixelinterpolation(d, a);
}
