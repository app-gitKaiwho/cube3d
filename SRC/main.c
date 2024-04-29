/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvon-war <lvon-war@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 11:48:49 by lvon-war          #+#    #+#             */
/*   Updated: 2024/04/29 13:54:39 by lvon-war         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

//do thing every frame
int	animation(t_data *d, int frame)
{
	static t_RGB	color;

	if (frame == 100000)
		frame = 0;
	if (frame % 200 == 0)
	{
		color = int_to_rgb(rand());
		if (d->world.nb_sprite > 0)
			sprite_edit(d, 0, sprite_create((t_point2d){10, d->height - 210},
					(t_point2d){200, 200}, color));
		display_world_sprite(d);
	}
	return (frame);
}

int	loopydyloop(void *param)
{
	struct data		*d;
	static int		frame;

	frame++;
	d = (t_data *)param;
	frame = animation(d, frame);
	return (0);
}

int	main(void)
{
	t_data	*data;

	data = initdata();
	init_world(data);
	minimap_init(data);
	player_init(data);
	initoption(data);
	init_bg(data);
	init_hudimg(data);
	test(data);
	displayimg(data);
	mlx_key_hook(data->win.ptr, &keyhook, data);
	mlx_loop_hook(data->win.mlx, loopydyloop, data);
	mlx_loop(data->win.mlx);
	free_data(data);
	error_handler("Failed to init data", 1);
	return (0);
}
