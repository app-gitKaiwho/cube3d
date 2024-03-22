/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_world.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvon-war <lvon-war@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 16:49:51 by lvon-war          #+#    #+#             */
/*   Updated: 2024/03/22 11:14:44 by lvon-war         ###   ########.fr       */
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
		put_sprite(d, d->world.c_sprite[i]);
		i++;
	}
}

