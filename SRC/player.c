/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spook <spook@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/08 14:56:29 by spook             #+#    #+#             */
/*   Updated: 2024/05/12 11:36:34 by spook            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

void	player_movement(t_data *d, int inc)
{
	t_ray	ray;
	t_point	player;

	player = (t_point){d->player.pos.x + d->player.size.x, d->player.pos.y + d->player.size.y};
	ray = raycast(d, player, d->player.speed, d->player.dir + inc);
	if (ray.walltype == '0' || ray.size > d->player.speed)
		d->player.pos = (t_point){d->player.pos.x + d->player.speed * cos(degtorad(d->player.dir + inc)), \
		d->player.pos.y + d->player.speed * sin(degtorad(d->player.dir + inc))};
}
