/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_world.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvon-war <lvonwar@gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 16:49:51 by lvon-war          #+#    #+#             */
/*   Updated: 2024/03/25 11:21:52 by lvon-war         ###   ########.fr       */
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

void	display_world_object(t_data *d)
{
	int		i;

	i = 0;
	if (d->world.nb_obj <= 0)
		return ;
	while (i < d->world.nb_obj)
	{
		if (d->world.c_obj[i].seen)
			object_put(d, d->world.c_obj[i]);
		i++;
	}
}

