/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvon-war <lvonwar@gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/24 19:38:03 by lvon-war          #+#    #+#             */
/*   Updated: 2024/04/03 14:53:28 by lvon-war         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

void	cast_object_on_minimap(t_data	*d)
{
	int			i;
	t_pixel		p;
	t_point2d	size;

	i = 0;
	p.color = int_to_rgb(RED);
	while (i < d->world.nb_obj)
	{
		size.x = d->world.c_obj[i].size.x / d->minimap.scale;
		size.y = d->world.c_obj[i].size.y / d->minimap.scale;
		p.x = d->minimap.pos.x + (d->world.c_obj[i].pos.x / d->minimap.scale)
			- (size.x / 2);
		p.y = d->minimap.pos.y + (d->world.c_obj[i].pos.z / d->minimap.scale)
			- (size.y / 2);
		put_square(p, size, d);
		i++;
	}
}

void	cast_player_on_minimap(t_data *d)
{
	t_pixel		p;
	t_point2d	pscaledsize;

	pscaledsize.x = d->player.size.x / d->minimap.scale;
	pscaledsize.y = d->player.size.z / d->minimap.scale;
	p.color = int_to_rgb(GREEN);
	p.x = d->minimap.pos.x + (d->player.pos.x / d->minimap.scale)
		- (pscaledsize.x / 2);
	p.y = d->minimap.pos.y + (d->player.pos.z / d->minimap.scale)
		- (pscaledsize.y / 2);
	put_square(p, pscaledsize, d);
}

void	cast_player_view(t_data *d)
{
	t_point		a;
	t_point		b;
	t_point		o;

	a = (t_point){d->minimap.pos.x + (d->player.cast[0].x / d->minimap.scale),
		d->minimap.pos.y + (d->player.cast[0].z / d->minimap.scale), 0};
	b = (t_point){d->minimap.pos.x + (d->player.cast[1].x / d->minimap.scale),
		d->minimap.pos.y + (d->player.cast[1].z / d->minimap.scale), 0};
	o = (t_point){d->minimap.pos.x + (d->player.pos.x / d->minimap.scale),
		d->minimap.pos.y + (d->player.pos.z / d->minimap.scale), 0};
	put_line((t_vector){a, o}, d, int_to_rgb(YELLOW));
	put_line((t_vector){b, o}, d, int_to_rgb(YELLOW));
	put_line((t_vector){a, b}, d, int_to_rgb(YELLOW));
}

void	displayraytoplayer(t_data *d)
{
	int			i;
	int			j;
	t_point		a;
	t_point		o;

	i = 0;
	while (i < d->world.nb_obj)
	{
		j = 0;
		while (j < 6)
		{
			a = (t_point){d->minimap.pos.x + (d->world.c_obj[i].verti[j].x
					/ d->minimap.scale), d->minimap.pos.y
				+ (d->world.c_obj[i].verti[j].z / d->minimap.scale), 0};
			o = (t_point){d->minimap.pos.x + (d->player.pos.x
					/ d->minimap.scale), d->minimap.pos.y
				+ (d->player.pos.z / d->minimap.scale), 0};
			put_line((t_vector){a, o}, d, int_to_rgb(RED));
			j++;
		}
		i++;
	}
}

void	display_minimap(t_data *d)
{
	t_pixel	p;

	d->minimap.size = (t_point2d){d->world.size.x / d->minimap.scale,
		d->world.size.y / d->minimap.scale};
	p = (t_pixel){d->minimap.pos.x, d->minimap.pos.y,
		d->minimap.color};
	put_square(p, d->minimap.size, d);
	cast_player_on_minimap(d);
	if (d->option.raytoplayer)
		displayraytoplayer(d);
	if (d->option.playerview)
		cast_player_view(d);
	cast_object_on_minimap(d);
}
