/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvon-war <lvon-war@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/08 14:56:29 by spook             #+#    #+#             */
/*   Updated: 2024/05/10 09:21:13 by lvon-war         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

void	player_movement(t_data *d, t_point newpos)
{
	if (newpos.x < 0 || newpos.x + (d->player.size.x) >= d->map.size.x \
	|| newpos.y < 0 || newpos.y + (d->player.size.y) >= d->map.size.y)
		return ;
	if (d->map.map[(int)newpos.y][(int)newpos.x] == '1')
		return ;
	if (d->map.map[(int)(newpos.y)][(int)(newpos.x + d->player.size.x)] == '1')
		return ;
	if (d->map.map[(int)(newpos.y + d->player.size.y)][(int)newpos.x] == '1')
		return ;
	if (d->map.map[(int)(newpos.y + d->player.size.y)] \
	[(int)(newpos.x + d->player.size.x)] == '1')
		return ;
	d->player.pos = newpos;
}
