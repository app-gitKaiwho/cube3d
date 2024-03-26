/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvon-war <lvonwar@gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/24 19:38:03 by lvon-war          #+#    #+#             */
/*   Updated: 2024/03/26 14:06:36 by lvon-war         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

/// @brief should be initialised by input
void	minimap_init(t_data *d)
{
	d->minimap.pos = (t_point2d){10, 10};
	d->minimap.scale = 10;
	d->minimap.color = int_to_rgb(BLUE);
	d->minimap.size = (t_point2d){d->world.size.x / d->minimap.scale,
		d->world.size.y / d->minimap.scale};
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
	pscaledsize.y = d->player.size.y / d->minimap.scale;
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
	put_line((t_vector2d){a, o}, d);
	put_line((t_vector2d){b, o}, d);
	put_line((t_vector2d){a, b}, d);
}

void	display_minimap(t_data *data)
{
	t_pixel	p;

	p = (t_pixel){data->minimap.pos.x, data->minimap.pos.y,
		data->minimap.color};
	put_square(p, data->minimap.size, data);
	cast_player_on_minimap(data);
	cast_player_view(data);
	cast_object_on_minimap(data);
}
