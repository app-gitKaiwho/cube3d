/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   renderer.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvon-war <lvon-war@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/11 17:49:51 by spook             #+#    #+#             */
/*   Updated: 2024/05/13 08:06:49 by lvon-war         ###   ########.fr       */
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

void	display(t_data *d, float dir, t_ray ray, int n)
{
	int			i;
	t_color		color;
	float		v;
	float		incy;
	const int	wallheight = d->scsize.y / 3;

	if (ray.face == 0 || ray.face == 2)
		ray.x = ray.start.y + ray.dir.y * ray.size;
	else
		ray.x = ray.start.x + ray.dir.x * ray.size;
	ray.x -= floor(ray.x);
	ray.x = 1 - ray.x;
	ray.x *= d->map.wall[ray.face].sizex;
	ray.size = ray.size * cos(degtorad(d->player.dir - dir));
	n = d->scsize.x - n;
	incy = (float)d->map.wall[ray.face].sizey / (float)(d->scsize.y / 2 \
	+ (wallheight / ray.size) - (d->scsize.y / 2 - wallheight / ray.size));
	v = 0;
	i = (d->scsize.y / 2 - wallheight / ray.size) - 1;
	while (++i <= d->scsize.y / 2 + wallheight / ray.size)
	{
		color = pixel_plottin(d->map.wall[ray.face], floor(ray.x), floor(v));
		put_pixel((t_pixel){n, i, color}, d->img);
		v += incy;
	}
}

void	castray(t_data *d)
{
	t_point		playerpos;
	t_ray		ray;
	float		dir;
	float		n;

	n = 0;
	playerpos = (t_point){d->player.pos.x + d->player.size.x / 2, \
	d->player.pos.y + d->player.size.y / 2};
	dir = d->player.dir - d->fov / 2;
	while (dir < d->player.dir + d->fov / 2)
	{
		ray = raycast(d, playerpos, sqrt(pow(d->map.size.x, 2) \
		+ pow(d->map.size.y, 2)), dir);
		displayonminimap(d, playerpos, ray.end);
		if (ray.walltype == '2' && ray.face != 0 && ray.face != 2)
			ray.face = 4;
		display(d, dir, ray, floor(n));
		dir += d->fov / (d->scsize.x - 1);
		n += 1;
	}
}
