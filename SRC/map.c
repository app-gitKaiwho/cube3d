/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvon-war <lvon-war@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/24 19:38:03 by lvon-war          #+#    #+#             */
/*   Updated: 2024/03/29 16:39:14 by lvon-war         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

/// @brief should be initialised by input
void	minimap_init(t_data *d)
{
	d->minimap.pos = (t_point2d){10, 10};
	d->minimap.scale = 1 * d->scale;
	d->minimap.color = int_to_rgb(BLUE);
}

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
	t_point2d		a;
	t_point2d		b;
	t_point2d		o;

	a.x = d->minimap.pos.x + (d->player.cast[0].x / d->minimap.scale);
	a.y = d->minimap.pos.y + (d->player.cast[0].z / d->minimap.scale);
	b.x = d->minimap.pos.x + (d->player.cast[1].x / d->minimap.scale);
	b.y = d->minimap.pos.y + (d->player.cast[1].z / d->minimap.scale);
	o.x = d->minimap.pos.x + (d->player.pos.x / d->minimap.scale);
	o.y = d->minimap.pos.y + (d->player.pos.z / d->minimap.scale);
	put_line((t_vector2d){a, o}, d, int_to_rgb(YELLOW));
	put_line((t_vector2d){b, o}, d, int_to_rgb(YELLOW));
	put_line((t_vector2d){a, b}, d, int_to_rgb(YELLOW));
}

void	raytest(t_data *d)
{
	t_point2d	r;
	t_point2d	o;
	t_point2d	s;
	double		ang;

	ang = d->player.angle.y * M_PI / 180;
	o.x = d->minimap.pos.x + (d->player.pos.x / d->minimap.scale);
	o.y = d->minimap.pos.y + (d->player.pos.z / d->minimap.scale);
	r.x = o.x + (d->render_distance / d->minimap.scale * cos(ang));
	r.y = o.y + (d->render_distance / d->minimap.scale * sin(ang));
	s.x = o.x + (d->focal / d->minimap.scale * cos(ang));
	s.y = o.y + (d->focal / d->minimap.scale * sin(ang));
	put_line((t_vector2d){o, r}, d, int_to_rgb(YELLOW));
	put_line((t_vector2d){o, s}, d, int_to_rgb(GREEN));
}

void	displayraytoplayer(t_data *d)
{
	int			i;
	int			j;
	t_point2d	a;
	t_point2d	o;

	i = 0;
	while (i < d->world.nb_obj)
	{
		j = 0;
		while (j < 6)
		{
			a.x = d->minimap.pos.x + (d->world.c_obj[i].verti[j].x
					/ d->minimap.scale);
			a.y = d->minimap.pos.y + (d->world.c_obj[i].verti[j].z
					/ d->minimap.scale);
			o.x = d->minimap.pos.x + (d->player.pos.x / d->minimap.scale);
			o.y = d->minimap.pos.y + (d->player.pos.z / d->minimap.scale);
			put_line((t_vector2d){a, o}, d, int_to_rgb(RED));
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
	displayraytoplayer(d);
	raytest(d);
	cast_player_view(d);
	cast_object_on_minimap(d);
}
