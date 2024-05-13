/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvon-war <lvon-war@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/08 14:56:29 by spook             #+#    #+#             */
/*   Updated: 2024/05/13 09:44:43 by lvon-war         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

void	player_movement(t_data *d, int inc)
{
	t_ray	ray;
	t_point	player;

	player = (t_point){d->player.pos.x + d->player.size.x, \
	d->player.pos.y + d->player.size.y};
	ray = raycast(d, player, d->player.speed, d->player.dir + inc);
	if (ray.size > d->player.speed)
		d->player.pos = (t_point){d->player.pos.x + d->player.speed \
		* cos(degtorad(d->player.dir + inc)), \
		d->player.pos.y + d->player.speed * sin(degtorad(d->player.dir + inc))};
}
