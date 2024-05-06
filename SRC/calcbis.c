/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calcbis.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvon-war <lvon-war@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/03 14:23:39 by lvon-war          #+#    #+#             */
/*   Updated: 2024/05/06 17:24:46 by lvon-war         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"
#include <stdio.h>

void	setborder(t_vector mp[2], t_upl *n, t_point *mab, t_point *mac)
{
	mab->x = interpolator2d(mp[0].a.x, mp[0].b.x, n->y.ab);
	mab->y = interpolator2d(mp[0].a.y, mp[0].b.y, n->y.ab);
	mab->z = interpolator2d(mp[0].a.z, mp[0].b.z, n->y.ab);
	mac->x = interpolator2d(mp[1].a.x, mp[1].b.x, n->y.ac);
	mac->y = interpolator2d(mp[1].a.y, mp[1].b.y, n->y.ac);
	mac->z = interpolator2d(mp[1].a.z, mp[1].b.z, n->y.ac);
	n->x.x = n->x.ab - 1;
}

void	x_put(t_data *d, t_polygon p, t_upl n, t_vector mp[2])
{
	t_point		mab;
	t_point		mac;
	t_point		current;
	float		valpercent;

	setborder(mp, &n, &mab, &mac);
	while (++n.x.x <= n.x.ac)
	{
		valpercent = percent(n.x.x, n.x.ab, n.x.ac);
		current.x = interpolator2d(mab.x, mac.x, valpercent);
		current.y = interpolator2d(mab.y, mac.y, valpercent);
		current.z = interpolator2d(mab.z, mac.z, valpercent);
		if (break_point(*d, (t_vector2d){(t_point2d){n.x.ab, n.y.y},
			(t_point2d){n.x.ac, n.y.y}}, (t_point2d){n.x.x, n.y.y}))
			return ;
		buffered_put((t_pixel){n.x.x, n.y.y, sampler(p, current.x
				* d->option.eight, current.y * d->option.eight)},
			d, d->img, current.z);
	}
	if (n.x.x > n.x.ac)
		n.x.x = n.x.ac;
	while (n.x.ab > n.x.ac && ++n.x.x <= n.x.ab)
	{
		valpercent = percent(n.x.x, n.x.ab, n.x.ac);
		current.x = interpolator2d(mab.x, mac.x, valpercent);
		current.y = interpolator2d(mab.y, mac.y, valpercent);
		current.z = interpolator2d(mab.z, mac.z, valpercent);
		if (break_point(*d, (t_vector2d){(t_point2d){n.x.ab, n.y.y},
			(t_point2d){n.x.ac, n.y.y}}, (t_point2d){n.x.x, n.y.y}))
			return ;
		buffered_put((t_pixel){n.x.x, n.y.y, sampler(p, current.x
				/ d->option.eight, current.y / d->option.eight)},
			d, d->img, current.z);
	}
}

// y : y start y, ab y pos on ab, ac y pos on ac
int	top(t_data *d, t_polygon p, t_yupl y, t_xupl x)
{
	float		tab;
	float		tac;
	t_vector	mp[2];

	tab = getstep(p.verti[0], p.verti[2]);
	tac = getstep(p.verti[0], p.verti[1]);
	while (y.y > p.verti[1].y)
	{
		y.ab = percent(y.y, p.verti[0].y, p.verti[2].y);
		y.ac = percent(y.y, p.verti[0].y, p.verti[1].y);
		x.x = interpolator(p.verti[0], p.verti[2], y.y);
		if (break_point(*d, (t_vector2d){(t_point2d){x.ab, y.y},
			(t_point2d){x.ac, p.verti[0].y}}, (t_point2d){x.x, p.verti[2].y}))
			return (y.y);
		mp[0] = (t_vector){p.texturepos[0], p.texturepos[2]};
		mp[1] = (t_vector){p.texturepos[0], p.texturepos[1]};
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
		x.x = interpolator(p.verti[0], p.verti[2], y.y);
		if (break_point(*d, (t_vector2d){(t_point2d){x.ab, y.y},
			(t_point2d){x.ac, p.verti[1].y}}, (t_point2d){x.x, p.verti[2].y}))
			return ;
		mp[0] = (t_vector){p.texturepos[0], p.texturepos[2]};
		mp[1] = (t_vector){p.texturepos[1], p.texturepos[2]};
		x_put(d, p, (t_upl){(t_xupl){y.y, x.ab, x.ac}, y}, mp);
		y.y--;
		x.ab -= tab;
		x.ac -= tac;
	}
}

void	rasterizer(t_data *d, t_polygon p)
{
	t_xupl		x;
	t_yupl		y;

	sortscanlines(&p);
	p.texturepos[0].z = p.verti[0].z / d->render_distance;
	p.texturepos[1].z = p.verti[1].z / d->render_distance;
	p.texturepos[2].z = p.verti[2].z / d->render_distance;
	y.y = round(p.verti[0].y);
	x.ab = p.verti[0].x;
	x.ac = p.verti[0].x;
	y.y = top(d, p, y, x);
	x.ab = interpolator(p.verti[0], p.verti[2], y.y);
	x.ac = interpolator(p.verti[1], p.verti[2], y.y);
	bot(d, p, y, x);
}
