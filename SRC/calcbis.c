/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calcbis.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spook <spook@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/03 14:23:39 by lvon-war          #+#    #+#             */
/*   Updated: 2024/05/05 09:24:46 by spook            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

void	topput(t_data *d, t_polygon p, t_upl n)
{
	t_point2d	mab;
	t_point2d	mac;
	t_point2d	current;
	float		precent;

	if (n.x.ab <= n.x.ac)
	{
		mab.x = interpolator2d(p.texturepos[0].x, p.texturepos[2].x, n.y.ab);
		mab.y = interpolator2d(p.texturepos[0].y, p.texturepos[2].y, n.y.ab);
		mac.x = interpolator2d(p.texturepos[0].x, p.texturepos[1].x, n.y.ac);
		mac.y = interpolator2d(p.texturepos[0].y, p.texturepos[1].y, n.y.ac);
	}
	else
	{
		n.x.x = n.x.ab;
		n.x.ab = n.x.ac;
		n.x.ac = n.x.x;
		mac.x = interpolator2d(p.texturepos[0].x, p.texturepos[2].x, n.y.ab);
		mac.y = interpolator2d(p.texturepos[0].y, p.texturepos[2].y, n.y.ab);
		mab.x = interpolator2d(p.texturepos[0].x, p.texturepos[1].x, n.y.ac);
		mab.y = interpolator2d(p.texturepos[0].y, p.texturepos[1].y, n.y.ac);
	}
	n.x.x = n.x.ab;
	while (n.x.x <= n.x.ac)
	{
		precent = percent(n.x.x, n.x.ab, n.x.ac);
		current.x = interpolator2d(mab.x, mac.x, precent);
		current.y = interpolator2d(mab.y, mac.y, precent);
		if (break_point(*d, (t_vector2d){(t_point2d){n.x.ab, n.y.y},
			(t_point2d){n.x.ac, n.y.y}}, (t_point2d){n.x.x, n.y.y}))
			return ;
		put_point((t_point){n.x.x, n.y.y, 1}, d, d->img,
			sampler(p, current.x, current.y));
		n.x.x++;
	}
}

void	botput(t_data *d, t_polygon p, t_upl n)
{
	t_point2d	mab;
	t_point2d	mac;
	t_point2d	current;
	float		precent;

	if (n.x.ab <= n.x.ac)
	{
		mab.x = interpolator2d(p.texturepos[0].x, p.texturepos[2].x, n.y.ab);
		mab.y = interpolator2d(p.texturepos[0].y, p.texturepos[2].y, n.y.ab);
		mac.x = interpolator2d(p.texturepos[1].x, p.texturepos[2].x, n.y.ac);
		mac.y = interpolator2d(p.texturepos[1].y, p.texturepos[2].y, n.y.ac);
	}
	else
	{
		n.x.x = n.x.ab;
		n.x.ab = n.x.ac;
		n.x.ac = n.x.x;
		mac.x = interpolator2d(p.texturepos[0].x, p.texturepos[2].x, n.y.ab);
		mac.y = interpolator2d(p.texturepos[0].y, p.texturepos[2].y, n.y.ab);
		mab.x = interpolator2d(p.texturepos[1].x, p.texturepos[2].x, n.y.ac);
		mab.y = interpolator2d(p.texturepos[1].y, p.texturepos[2].y, n.y.ac);
	}
	n.x.x = n.x.ab - 1;
	while (++n.x.x <= n.x.ac)
	{
		precent = percent(n.x.x, n.x.ab, n.x.ac);
		current.x = interpolator2d(mab.x, mac.x, precent);
		current.y = interpolator2d(mab.y, mac.y, precent);
		if (break_point(*d, (t_vector2d){(t_point2d){n.x.ab, n.y.y},
			(t_point2d){n.x.ac, n.y.y}}, (t_point2d){n.x.x, n.y.y}))
			return ;
		put_point((t_point){n.x.x, n.y.y, 0}, d, d->img,
			sampler(p, current.x, current.y));
	}
}

// y : y start y, ab y pos on ab, ac y pos on ac
int	top(t_data *d, t_polygon p, t_yupl y, t_xupl x)
{
	float	tab;
	float	tac;

	tab = getstep(p.verti[0], p.verti[2]);
	tac = getstep(p.verti[0], p.verti[1]);
	while (y.y > p.verti[1].y)
	{
		y.ab = percent(y.y, p.verti[0].y, p.verti[2].y);
		y.ac = percent(y.y, p.verti[0].y, p.verti[1].y);
		if (break_point(*d, (t_vector2d){(t_point2d){x.ab, y.y},
			(t_point2d){x.ac, p.verti[0].y}}, (t_point2d){x.x, p.verti[2].y}))
			return (y.y);
		if (d->option.five)
			topput(d, p, (t_upl){(t_xupl){y.y, x.ab, x.ac}, y});
		y.y--;
		x.ab -= tab;
		x.ac -= tac;
	}
	return (y.y);
}

void	bot(t_data *d, t_polygon p, t_yupl y, t_xupl x)
{
	float	tab;
	float	tac;

	tab = getstep((t_point){x.ab, p.verti[1].y, 0}, p.verti[2]);
	tac = getstep((t_point){x.ac, p.verti[1].y, 0}, p.verti[2]);
	while (y.y > p.verti[2].y)
	{
		y.ab = percent(y.y, p.verti[0].y, p.verti[2].y);
		y.ac = percent(y.y, p.verti[1].y, p.verti[2].y);
		if (break_point(*d, (t_vector2d){(t_point2d){x.ab, y.y}, (t_point2d){x.ac, p.verti[1].y}}, (t_point2d){x.x, p.verti[2].y}))
			return ;
		if (d->option.six)
			botput(d, p, (t_upl){(t_xupl){y.y, x.ab, x.ac}, y});
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
	y.y = top(d, a, y, x);
	x.ab = interpolator(a.verti[0], a.verti[2], y.y);
	x.ac = interpolator(a.verti[1], a.verti[2], y.y);
	bot(d, a, y, x);
}
