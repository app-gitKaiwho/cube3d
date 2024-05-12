/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   renderer.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spook <spook@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/11 17:49:51 by spook             #+#    #+#             */
/*   Updated: 2024/05/12 01:33:52 by spook            ###   ########.fr       */
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

#include <stdio.h>
void display(t_data *d, int dir, t_ray ray, int n)
{
	int i;
	t_color color;
	float v;
	float incy;
	const int wallheight = d->scsize.y / 4;
	int dot;

	dot = 0;
	n = d->scsize.x - n;
	ray.size = ray.size * cos(degtorad(dir - d->player.dir));
	incy = (float)d->map.wall[ray.face].sizey / (float)(d->scsize.y / 2 + (wallheight / ray.size) - (d->scsize.y / 2 - wallheight / ray.size));
	while (dot < 22)
	{
		i = (d->scsize.y / 2 - wallheight / ray.size);
		v = 0;
		while (i <= d->scsize.y / 2 + wallheight / ray.size)
		{
			color = pixel_plottin(d->map.wall[ray.face], n, floor(v));
			put_pixel((t_pixel){n, i, color}, d->img);
			i++;
			v += incy;
		}
		dot++;
		n++;
	}
}

void	castray(t_data *d)
{
	t_point		playerpos;
	t_ray		ray;
	int			dir;
	float		n;

	n = 0;
	playerpos = (t_point){d->player.pos.x + d->player.size.x / 2, d->player.pos.y + d->player.size.y / 2};
	dir = d->player.dir - d->fov / 2;
	while (dir < d->player.dir + d->fov / 2)
	{
		ray = raycast(d, playerpos, sqrt(pow(d->map.size.x, 2) + pow(d->map.size.y, 2)), dir);
		displayonminimap(d, playerpos, ray.end);
		display(d, dir, ray, floor(n));
		dir += 1;
		n += (d->scsize.x / (float)d->fov);
	}
}