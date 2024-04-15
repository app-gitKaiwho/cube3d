/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_world.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvon-war <lvon-war@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 16:49:51 by lvon-war          #+#    #+#             */
/*   Updated: 2024/04/15 13:33:08 by lvon-war         ###   ########.fr       */
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
	int		i;

	i = -1;
	while (++i < 3)
		put_line(vec3cast(p.edges[i], *d), d, p.textaddr[0]);
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
