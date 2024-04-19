/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calcbis.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvon-war <lvon-war@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/03 14:23:39 by lvon-war          #+#    #+#             */
/*   Updated: 2024/04/19 16:11:44 by lvon-war         ###   ########.fr       */
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

//return is bend direction : right 1, left 0
int	sortscanlines(t_point	vert[3])
{
	if (vert[1].y > vert[0].y)
		swappoints(&vert[0], &vert[1]);
	if (vert[2].y > vert[1].y)
	{
		swappoints(&vert[1], &vert[2]);
		if (vert[1].y > vert[0].y)
			swappoints(&vert[1], &vert[0]);
	}
	if (vert[1].x > vert[2].x)
		return (1);
	return (0);
}

void	lineinterpolation(t_data *d, t_iterator it, t_polygon p)
{
	if (it.i > it.j)
	{
		while (it.i > it.j)
			put_pixel((t_pixel){it.i--, it.k, polygon_get_color(p)}, d);
	}
	else
	{
		while (it.i <= it.j)
			put_pixel((t_pixel){it.i++, it.k, polygon_get_color(p)}, d);
	}
}

void	pixelinterpolation(t_data *d, t_point	vert[3], t_polygon p)
{
	int	i;
	int	l;
	int	r;

	if (p.texturepos[1].x == 0)
		return ;
	i = vert[0].y;
	while (i > vert[2].y)
	{
		if (i >= vert[1].y)
			l = interpolator(vert[0], vert[1], i);
		else
			l = interpolator(vert[1], vert[2], i);
		r = interpolator(vert[0], vert[2], i);
		lineinterpolation(d, (t_iterator){l, r, i}, p);
		i--;
	}
}

void	rasterizer(t_data *d, t_polygon p)
{
	t_point	vert[3];
	int		i;

	i = -1;
	while (++i < 3)
		vert[i] = p.verti[i];
	sortscanlines(vert);
	pixelinterpolation(d, vert, p);
}
