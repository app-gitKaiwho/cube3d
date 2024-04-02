/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvon-war <lvonwar@gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/24 15:15:19 by lvon-war          #+#    #+#             */
/*   Updated: 2024/04/02 14:31:11 by lvon-war         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

void	player_init(t_data *d)
{
	d->player.speed = 5 * d->scale;
	d->player.size = (t_point){0.5 * d->scale, 1.8 * d->scale, 0.5 * d->scale};
	d->player.pos = (t_point){d->world.size.x / 2, 0, 100};
	d->player.angle = (t_point){0, 0, 0};
}

//temporary doble raycast to show lines
void	player_movement(t_data *data, t_point dir)
{
	data->player.pos.x += dir.x * data->player.speed
		* cos(data->player.angle.y * M_PI / 180)
		- dir.z * data->player.speed * sin(data->player.angle.y * M_PI / 180);
	data->player.pos.z += dir.z * data->player.speed
		* cos(data->player.angle.y * M_PI / 180)
		+ dir.x * data->player.speed * sin(data->player.angle.y * M_PI / 180);
	data->player.angle.y += dir.y * 10 ;
	if (data->player.pos.x >= data->world.size.x)
		data->player.pos.x = data->world.size.x;
	else if (data->player.pos.x <= 0)
		data->player.pos.x = 0;
	if (data->player.pos.z >= data->world.size.y)
		data->player.pos.z = data->world.size.y;
	else if (data->player.pos.z <= 0)
		data->player.pos.z = 0;
}

//rework to cast on z and not y
void	raycast(t_data *d)
	{
	double	a;
	double	fov;
	t_point	pos;

	a = (((d->player.angle.y + 90)) * M_PI) / 180;
	pos = d->player.pos;
	fov = (((d->fov)) * M_PI) / 180;
	d->player.cast[0].x = pos.x
		+ (d->render_distance * cos(a + fov / 2)) / cos(fov / 2);
	d->player.cast[0].z = pos.z
		+ (d->render_distance * sin(a + fov / 2)) / cos(fov / 2);
	d->player.cast[1].x = pos.x
		+ (d->render_distance * cos(a - fov / 2)) / cos(fov / 2);
	d->player.cast[1].z = pos.z
		+ (d->render_distance * sin(a - fov / 2)) / cos(fov / 2);
	object_to_render(d);
}
