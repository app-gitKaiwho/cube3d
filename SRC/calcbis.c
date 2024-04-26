/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calcbis.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvon-war <lvon-war@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/03 14:23:39 by lvon-war          #+#    #+#             */
/*   Updated: 2024/04/26 11:33:03 by lvon-war         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

float	getstep(t_point a, t_point b)
{
	if ((a.x - b.x) == 0)
		return (0);
	if ((a.y - b.y) == 0)
		return (1);
	return ((a.x - b.x) / (a.y - b.y));
}

void	put(t_data *d, t_polygon p, t_upl a, t_xupl x)
{
	(void)a;
	while (x.ab < x.ac)
	{
		put_pixel((t_pixel){round(x.ab++), x.x, sampler(p, 0, 0)}, d);
	}
}

void	top(t_data *d, t_polygon p, t_upl *y, t_xupl *x)
{
	float	tab;
	float	tac;

	tac = getstep(p.verti[0], p.verti[2]);
	tab = getstep(p.verti[0], p.verti[1]);
	y->ac = 1 / deltadouble(p.verti[0].y, p.verti[2].y);
	y->ab = 1;
	while (n->n > p.verti[1].y)
	{
			if (x->ab < x->ac)
				put(d, p, *n, ((t_xupl){n->n, x->ab, x->ac}));
			else
				put(d, p, *n, ((t_xupl){n->n, x->ac, x->ab}));
		n->n--;
		x->ab -= tab;
		x->ac -= tac;
	}
}
/*
void	bot(t_data *d, t_polygon p, t_upl *y, t_xupl *x)
{
	float	tab;
	float	tac;

	tac = getstep(p.verti[0], p.verti[2]);
	tab = getstep(p.verti[1], p.verti[2]);
	while (y->n > p.verti[2].y)
	{
		if (d->option.six)
		{
			if (x->ab < x->ac)
				put(d, p, (t_upl){y->n, x->ab, x->ac});
			else
				put(d, p, (t_upl){y->n, x->ac, x->ab});
		}
		x->ab -= tab;
		x->ac -= tac;
		(y->n)--;
	}
}*/

void	rasterizer(t_data *d, t_polygon p)
{
	t_polygon	a;
	t_xupl		x;
	t_upl		y;

	a = p;
	sortscanlines(&a);
	a.verti[0].x--;
	x.ab = a.verti[1].x;
	y.n = round(a.verti[1].y);
	if (a.verti[0].y > a.verti[1].y)
	{
		y.n = round(a.verti[0].y);
		x.ab = a.verti[0].x;
	}
	x.ac = a.verti[0].x;
	top(d, a, &y, &x);
	//bot(d, a, &y, &x);
}
