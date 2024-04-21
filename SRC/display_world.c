/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_world.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spook <spook@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 16:49:51 by lvon-war          #+#    #+#             */
/*   Updated: 2024/04/21 03:13:38 by spook            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

/// @brief displays every global sprite
void	display_world_sprite(t_data *d)
{
	int		i;

	i = -1;
	if (d->world.nb_sprite <= 0)
		return ;
	while (++i < d->world.nb_sprite)
		sprite_put(d, d->world.c_sprite[i]);
}

void	display_polygone(t_data *d, t_polygon p)
{
	int			i;
	t_polygon	poly;

	poly = p;
	i = -1;

	if (d->option.wireframe)
	{
		while (++i < 3)
			poly.verti[i] = pointcast(p.verti[i], *d);
		rasterizer(d, poly);
	}
	i = -1;
	while (++i < 3)
	{
		poly.edges[i] = vec3cast(p.edges[i], *d);
		//put_line(poly.edges[i], d, p.textaddr[0]);
		put_line(poly.edges[i], d, int_to_rgb(RED));
	}
}

void	display_world_object(t_data *d)
{
	int		i;
	int		j;

	i = -1;
	if (d->world.nb_obj <= 0)
		return ;
	while (++i < d->world.nb_obj)
	{
		j = -1;
		while (++j < 12)
		{
			if (d->world.c_obj[i].poly[j].seen)
				display_polygone(d, d->world.c_obj[i].poly[j]);
		}
	}
}
