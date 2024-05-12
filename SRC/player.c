/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spook <spook@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/08 14:56:29 by spook             #+#    #+#             */
/*   Updated: 2024/05/12 04:31:35 by spook            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

void	player_movement(t_data *d, t_point newpos)
{
	if (newpos.x < 0 || newpos.x + (d->player.size.x) >= d->map.size.x \
	|| newpos.y < 0 || newpos.y + (d->player.size.y) >= d->map.size.y)
		return ;
	if (d->map.map[(int)newpos.y][(int)newpos.x] >= '1' && d->map.map[(int)newpos.y][(int)newpos.x] < '9')
		return ;
	if (d->map.map[(int)(newpos.y)][(int)(newpos.x + d->player.size.x)] >= '1' && d->map.map[(int)(newpos.y)][(int)(newpos.x + d->player.size.x)] < '9')
		return ;
	if (d->map.map[(int)(newpos.y + d->player.size.y)][(int)newpos.x] >= '1' && d->map.map[(int)(newpos.y + d->player.size.y)][(int)newpos.x] < '9')
		return ;
	if (d->map.map[(int)(newpos.y + d->player.size.y)][(int)(newpos.x + d->player.size.x)] >= '1' && d->map.map[(int)(newpos.y + d->player.size.y)][(int)(newpos.x + d->player.size.x)] < '9')
		return ;
	d->player.pos = newpos;
}
