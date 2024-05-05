/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calcbis.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spook <spook@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/03 14:23:39 by lvon-war          #+#    #+#             */
/*   Updated: 2024/05/05 10:01:09 by spook            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

void	setborder(t_vector mp[2], t_upl *n, t_point2d *mab, t_point2d *mac)
{
	if (n->x.ab <= n->x.ac)
	{
		mab->x = interpolator2d(mp[0].a.x, mp[0].b.x, n->y.ab);
		mab->y = interpolator2d(mp[0].a.y, mp[0].b.y, n->y.ab);
		mac->x = interpolator2d(mp[1].a.x, mp[1].b.x, n->y.ac);
		mac->y = interpolator2d(mp[1].a.y, mp[1].b.y, n->y.ac);
	}
	else
	{
		n->x.x = n->x.ab;
		n->x.ab = n->x.ac;
		n->x.ac = n->x.x;
		mac->x = interpolator2d(mp[0].a.x, mp[0].b.x, n->y.ab);
		mac->y = interpolator2d(mp[0].a.y, mp[0].b.y, n->y.ab);
		mab->x = interpolator2d(mp[1].a.x, mp[1].b.x, n->y.ac);
		mab->y = interpolator2d(mp[1].a.y, mp[1].b.y, n->y.ac);
	}
	n->x.x = n->x.ab - 1;
}

void	x_put(t_data *d, t_polygon p, t_upl n, t_vector mp[2])
{
	t_point2d	mab;
	t_point2d	mac;
	t_point2d	current;
	float		precent;

	setborder(mp, &n, &mab, &mac);
	while (++n.x.x <= n.x.ac)
	{
		precent = percent(n.x.x, n.x.ab, n.x.ac);
		current.x = interpolator2d(mab.x, mac.x, precent);
		current.y = interpolator2d(mab.y, mac.y, precent);
		if (break_point(*d, (t_vector2d){(t_point2d){n.x.ab, n.y.y},
			(t_point2d){n.x.ac, n.y.y}}, (t_point2d){n.x.x, n.y.y}))
			return ;
		put_point((t_point){n.x.x, n.y.y, 1}, d, d->img,
			sampler(p, current.x, current.y));
	}
}

// y : y start y, ab y pos on ab, ac y pos on ac
int	top(t_data *d, t_polygon p, t_yupl y, t_xupl x)
{
	float	tab;
	float	tac;
	t_vector	mp[2];

	tab = getstep(p.verti[0], p.verti[2]);
	tac = getstep(p.verti[0], p.verti[1]);
	while (y.y > p.verti[1].y)
	{
		y.ab = percent(y.y, p.verti[0].y, p.verti[2].y);
		y.ac = percent(y.y, p.verti[0].y, p.verti[1].y);
		if (break_point(*d, (t_vector2d){(t_point2d){x.ab, y.y},
			(t_point2d){x.ac, p.verti[0].y}}, (t_point2d){x.x, p.verti[2].y}))
			return (y.y);
		mp[0] = (t_vector){p.texturepos[0], p.texturepos[2]};
		mp[1] = (t_vector){p.texturepos[0], p.texturepos[1]};
		if (d->option.five)
			x_put(d, p, (t_upl){(t_xupl){y.y, x.ab, x.ac}, y}, mp);
		y.y--;
		x.ab -= tab;
		x.ac -= tac;
	}
	return (y.y);
}

void	bot(t_data *d, t_polygon p, t_yupl y, t_xupl x)
{
	float		tab;
	float		tac;
	t_vector	mp[2];

	tab = getstep((t_point){x.ab, p.verti[1].y, 0}, p.verti[2]);
	tac = getstep((t_point){x.ac, p.verti[1].y, 0}, p.verti[2]);
	while (y.y > p.verti[2].y)
	{
		y.ab = percent(y.y, p.verti[0].y, p.verti[2].y);
		y.ac = percent(y.y, p.verti[1].y, p.verti[2].y);
		if (break_point(*d, (t_vector2d){(t_point2d){x.ab, y.y}, (t_point2d){x.ac, p.verti[1].y}}, (t_point2d){x.x, p.verti[2].y}))
			return ;
		mp[0] = (t_vector){p.texturepos[0], p.texturepos[2]};
		mp[1] = (t_vector){p.texturepos[1], p.texturepos[2]};
		if (d->option.six)
			x_put(d, p, (t_upl){(t_xupl){y.y, x.ab, x.ac}, y}, mp);
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
