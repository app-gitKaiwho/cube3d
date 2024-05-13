/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvon-war <lvon-war@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/12 11:38:40 by spook             #+#    #+#             */
/*   Updated: 2024/05/13 13:22:00 by lvon-war         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

int	mouse_hook(int button, int x, int y, void *param)
{
	t_data	*d;

	d = (t_data *)param;
	if (d->minimap_scaled && button == 1)
	{
		d->map.map[(int)(d->map.size.y - (float)y / d->minimap.scale.y)] \
		[(int)((float)x / d->minimap.scale.x)] = '1';
	}
	if (d->minimap_scaled && button == 2)
	{
		d->map.map[(int)(d->map.size.y - (float)y / d->minimap.scale.y)] \
		[(int)((float)x / d->minimap.scale.x)] = '0';
	}
	if (d->minimap_scaled && button == 3)
	{
		d->map.map[(int)(d->map.size.y - (float)y / d->minimap.scale.y)] \
		[(int)((float)x / d->minimap.scale.x)] = '2';
	}
	return (0);
}

int	mouse_move(int x, int y, void *param)
{
	t_data			*d;
	static float	last_mouse_x;
	static float	camera_yaw;
	float			delta_x;

	(void)y;
	d = (t_data *)param;
	if (!d->minimap_scaled)
	{
		delta_x = x - last_mouse_x;
		camera_yaw -= delta_x / 2;
		d->player.dir = camera_yaw;
		last_mouse_x = x;
	}
	return (0);
}
