/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvon-war <lvon-war@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/08 14:53:46 by spook             #+#    #+#             */
/*   Updated: 2024/05/10 15:04:32 by lvon-war         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

void	displayonminimap(t_data *d, t_point start, t_point end)
{
	start.x *= d->minimap.scale;
	start.y *= d->minimap.scale;
	end.x *= d->minimap.scale;
	end.y *= d->minimap.scale;
	put_line((t_vector){start, end}, (t_color){255, 0, 255, 0}, d->minimapimg);
}

void	draw_wall(t_data *d, t_folder f, int pixelperray)
{
	float	dist;
	t_color	color;
	int		y;
	float	v;
	t_point	inc;

	f.n = d->scsize.x - f.n;
	dist = sqrt(pow(f.end.x - f.start.x, 2) + pow(f.end.y - f.start.y, 2));
	dist = dist * cos(d->player.dir - \
	atan2(f.end.y - f.start.y, f.end.x - f.start.x));
	inc = (t_point){0, (float)d->map.wall[f.face].sizey \
	/ (float)((d->scsize.y / 2 + (d->scsize.y / 4 / dist)) \
	- (int)(d->scsize.y / 2 - (d->scsize.y / 4 / dist)))};
	while (pixelperray >= 0)
	{
		y = (int)(d->scsize.y / 2 - (d->scsize.y / 4 / dist));
		v = 0;
		while (y < (int)(d->scsize.y / 2 + (d->scsize.y / 4 / dist)))
		{
			color = pixel_plottin(d->map.wall[f.face], floor(f.n), floor(v));
			if (y >= 0 && y < d->scsize.y)
				put_pixel((t_pixel){floor(f.n), floor(y), color}, d->img);
			y++;
			v += inc.y;
		}
		f.n++;
		pixelperray--;
	}
}

int	dirtester(t_data *d, t_folder *f, t_point dir)
{
	if ((f->end.x - (int)f->end.x) < 0.001)
	{
		if (d->map.map[(int)floor((f->end.y + dir.y))] \
		[(int)floor((f->end.x + dir.x))] == '1')
		{
			f->face = 0;
			if (dir.x < 0)
				f->face = 1;
			return (1);
		}
	}
	if ((f->end.y - (int)f->end.y) < 0.001)
	{
		if (d->map.map[(int)floor((f->end.y + dir.y))] \
		[(int)floor((f->end.x + dir.x))] == '1')
		{
			f->face = 2;
			if (dir.y < 0)
				f->face = 3;
			return (1);
		}
	}
	f->end.x += dir.x;
	f->end.y += dir.y;
	return (0);
}

void	raycast(t_data *d)
{
	t_folder	f;
	t_point		dir;
	int			rayperpixel;
	float		angle;

	f.n = 0;
	f.face = 0;
	rayperpixel = 2;
	angle = d->player.dir - d->fov / 2;
	while (angle < d->player.dir + d->fov / 2)
	{
		dir.y = sin(angle) * 0.001;
		dir.x = cos(angle) * 0.001;
		f.start = (t_point){(d->player.pos.x + d->player.size.x / 2), \
		(d->player.pos.y + d->player.size.y / 2)};
		f.end = (t_point){f.start.x, f.start.y};
		while (f.end.x >= 0 && f.end.x < (d->map.size.x) && \
		f.end.y >= 0 && f.end.y < (d->map.size.y))
		{
			if (dirtester(d, &f, dir))
				break ;
		}
		displayonminimap(d, f.start, f.end);
		draw_wall(d, f, rayperpixel * 2);
		angle += M_PI * rayperpixel / (d->scsize.x);
		f.n += 2 * rayperpixel;
	}
}
