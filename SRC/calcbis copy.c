/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calcbis copy.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spook <spook@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/03 14:23:39 by lvon-war          #+#    #+#             */
/*   Updated: 2024/04/24 19:59:07 by spook            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

void	rightrender(t_data *d, t_polygon p, t_bornes	real, t_yupl y)
{
	while (real.r < real.l)
		put_pixel((t_pixel){round(real.r++), y.y, sampler(p, 0, 0)}, d);
}

void	leftrender(t_data *d, t_polygon p, t_bornes	real, t_yupl y)
{
	while (real.l < real.r)
		put_pixel((t_pixel){round(real.l++), y.y, sampler(p, 0, 0)}, d);
}

void	bottomtriangle(t_data *d, t_polygon p)
{
	t_bornes	real;
	t_yupl		y;

	y.y = p.verti[1].y;
	while (y.y >= p.verti[2].y)
	{
		real.l = interpolator(p.verti[0], p.verti[2], y.y);
		real.r = interpolator(p.verti[1], p.verti[2], y.y);
		if (real.l < real.r)
			leftrender(d, p, real, y);
		else
			rightrender(d, p, real, y);
		y.y--;
	}
}

void	toptriangle(t_data *d, t_polygon p)
{
	t_bornes	real;
	t_yupl		y;

	y.y = p.verti[0].y;
	while (--y.y >= p.verti[1].y)
	{
		real.l = interpolator(p.verti[0], p.verti[2], y.y);
		real.r = interpolator(p.verti[0], p.verti[1], y.y);
		if (real.l < real.r)
			leftrender(d, p, real, y);
		else
			rightrender(d, p, real, y);
	}
}

void	rasterizer(t_data *d, t_polygon p)
{
	t_polygon	a;

	a = p;
	sortscanlines(&a);
	if (d->option.five)
		toptriangle(d, a);
	if (d->option.six)
		bottomtriangle(d, a);
}

int	oldtriangle(t_data *d, t_polygon p)
{
	t_bornes	real;
	t_bornes	img;
	t_yupl		y;
	t_yupl		ty;
	double		x;
	double		tx;

	y.ly = (p.texturepos[0].y - p.texturepos[2].y) / (p.verti[0].y - p.verti[2].y);
	y.ry = (p.texturepos[0].y - p.texturepos[1].y) / (p.verti[0].y - p.verti[1].y);
	ty = (t_yupl){p.verti[0].y - 1, p.texturepos[0].y - y.ly, p.texturepos[0].y - y.ry};
	while (--ty.y > p.verti[1].y)
	{
		if (p.verti[2].x < p.verti[1].x)
		{
			if (p.verti[0].x == p.verti[1].x)
			{
				real.l = interpolator(p.verti[0], p.verti[2], ty.y);
				real.r = p.verti[1].x;
				img.l = interpolator(p.texturepos[0], p.texturepos[2], ty.ly);
				img.r = 1;
			}
			else
			{
				img.l = 0;
				img.r = interpolator(p.texturepos[0], p.texturepos[1], ty.ry);
				real.l = p.verti[0].x;
				real.r = interpolator(p.verti[0], p.verti[1], ty.y);
			}
			x = (img.r - img.l) / (real.r - real.l);
			tx = img.l + x;
			while (++real.l < real.r)
			{
				put_pixel((t_pixel){round(real.l), round(ty.y), sampler(p, tx, 0)}, d);
				tx += x;
			}
		}
		ty.ly -= y.ly;
		ty.ry -= y.ry;
	}
	return (ty.y);
}