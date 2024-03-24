/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvon-war <lvonwar@gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/24 15:15:19 by lvon-war          #+#    #+#             */
/*   Updated: 2024/03/25 00:18:26 by lvon-war         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

void	player_init(t_data *d)
{
	d->player.speed = 10;
	d->player.size = (t_point2d){d->minimap.scale, d->minimap.scale};
	d->player.pos = (t_point){WL / 2, WH / 2, 0};
	d->player.xangle = 90;
}

void	player_movement(t_data *data, t_point dir)
{
	data->player.pos.x += dir.x * data->player.speed;
	data->player.pos.y += dir.y * data->player.speed;
	data->player.xangle += dir.z * data->player.speed;
	clear_img(data);
}

//not used anymore
void	put_raycast(t_data *d)
{
	double	angle;
	t_point	pos;

	angle = (((d->player.xangle)) * M_PI) / 180;
	pos = d->player.pos;
	d->player.cast[0].x = (cos(angle - (d->fov / 2)) * d->render_distance) + pos.x;
	d->player.cast[0].y = (sin(angle - (d->fov / 2)) * d->render_distance) + pos.y;
	d->player.cast[1].x = (cos(angle + (d->fov / 2)) * d->render_distance) + pos.x;
	d->player.cast[1].y = (sin(angle + (d->fov / 2)) * d->render_distance) + pos.y;
	put_line((t_vector){pos, (t_point){d->player.cast[0].x, d->player.cast[0].y, 0}}, d);
	put_line((t_vector){pos, (t_point){d->player.cast[1].x, d->player.cast[1].y, 0}}, d);
	put_line((t_vector){(t_point){d->player.cast[0].x, d->player.cast[0].y, 0},
		(t_point){d->player.cast[1].x, d->player.cast[1].y, 0}}, d);
}
