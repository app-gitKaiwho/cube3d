/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_world.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvon-war <lvonwar@gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 16:49:51 by lvon-war          #+#    #+#             */
/*   Updated: 2024/03/26 14:51:49 by lvon-war         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

/// @brief displays every global sprite
void	display_world_sprite(t_data *d)
{
	int		i;

	i = 0;
	if (d->world.nb_sprite <= 0)
		return ;
	while (i < d->world.nb_sprite)
	{
		sprite_put(d, d->world.c_sprite[i]);
		i++;
	}
}

void	display_polygone(t_data *d, t_polygon p)
{
	int		i;

	i = 0;
	while (i < 3)
	{
		put_line(vec3cast(p.edges[i], *d), d);
		i++;
	}
}

void	display_world_object(t_data *d)
{
	int		i;
	int		j;

	i = 0;
	if (d->world.nb_obj <= 0)
		return ;
	while (i < d->world.nb_obj)
	{
		j = 0;
		if (d->world.c_obj[i].seen)
		{
			while (j < 12)
			{
				display_polygone(d, d->world.c_obj[i].poly[j]);
				j++;
			}
		}
		i++;
	}
}
