/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calcbis.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvon-war <lvon-war@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/03 14:23:39 by lvon-war          #+#    #+#             */
/*   Updated: 2024/04/26 14:59:13 by lvon-war         ###   ########.fr       */
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

void	put(t_data *d, t_polygon p, t_yupl y, t_xupl x)
{
	(void)y;
	while (x.ab < x.ac)
	{
		put_pixel((t_pixel){round(x.ab++), y.y, sampler(p, 0, 0)}, d);
	}
}
#include <stdio.h>
// y : y start y, ab y pos on ab, ac y pos on ac
void	top(t_data *d, t_polygon p, t_yupl *y, t_xupl x)
{
	float	tab;
	float	tac;

	tab = getstep(p.verti[0], p.verti[2]);
	tac = getstep(p.verti[0], p.verti[1]);
	while (y->y > p.verti[1].y)
	{
		if (d->option.five)
		{
			if (x.ab < x.ac)
				put(d, p, *y, ((t_xupl){y->y, x.ab, x.ac}));
			else
				put(d, p, *y, ((t_xupl){y->y, x.ac, x.ab}));
		}
		y->y--;
		x.ab -= tab;
		x.ac -= tac;
	}
}

void	bot(t_data *d, t_polygon p, t_yupl y, t_xupl x)
{
	float	tab;
	float	tac;


	tab = getstep((t_point){x.ab, p.verti[1].y, 0}, p.verti[2]);
	tac = getstep((t_point){x.ac, p.verti[1].y, 0}, p.verti[2]);
	while (y.y > p.verti[2].y + 1)
	{
		if (d->option.six)
		{
			if (x.ab < x.ac)
				put(d, p, y, ((t_xupl){y.y, round(x.ab), round(x.ac)}));
			else
				put(d, p, y, ((t_xupl){y.y, round(x.ac), round(x.ab)}));
		}
		y.y--;
		x.ab -= tab;
		x.ac -= tac;
	}
}

void	rasterizer(t_data *d, t_polygon p)
{
	t_polygon	a;
	t_xupl		x;
	t_yupl		y;

	a = p;
	sortscanlines(&a);
	y.y = round(a.verti[0].y);
	x.ab = a.verti[0].x;
	x.ac = a.verti[0].x;
	top(d, a, &y, x);
	x.ab = interpolator(a.verti[0], a.verti[2], y.y);
	x.ac = interpolator(a.verti[1], a.verti[2], y.y);
	bot(d, a, y, x);
}
