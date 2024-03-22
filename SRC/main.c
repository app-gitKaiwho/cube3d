/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvon-war <lvon-war@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 11:48:49 by lvon-war          #+#    #+#             */
/*   Updated: 2024/03/22 16:09:56 by lvon-war         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

t_world	init_world(void)
{
	t_world	world;

	world.spawn = (t_point){0, 0, 0};
	world.earth = 0xbf9c6d;
	world.sky = 0x9deaed;
	world.nb_obj = 0;
	world.nb_sprite = 0;
	return (world);
}

///textures to be removed only there for testing
t_data	*initdata(void)
{
	t_data	*data;
	t_RGB	**texture;

	texture = malloc(sizeof(t_RGB *) * 3);
	if (!texture)
		error_handler("Failed to init data", 1);
	texture[0] = texture_monchrome_create((t_point2d){100, 100}, int_to_rgb(RED));
	texture[1] = texture_monchrome_create((t_point2d){100, 100}, int_to_rgb(GREEN));
	texture[2] = texture_monchrome_create((t_point2d){100, 100}, int_to_rgb(BLUE));
	data = malloc(sizeof(t_data));
	if (!data)
		error_handler("Failed to init data", 1);
	data->win.mlx = mlx_init();
	data->win.ptr = mlx_new_window(data->win.mlx, WL, WH, "My Window");
	data->img.img = mlx_new_image(data->win.mlx, WL, WH);
	data->img.addr = mlx_get_data_addr(data->img.img, &data->img.bpp,
			&data->img.line_size, &data->img.endian);
	mlx_hook(data->win.ptr, CLOSE_WINDOW_KEY, 0, &exit_hook, NULL);
	mlx_key_hook(data->win.ptr, &keyhook, NULL);
	data->world = init_world();
	clear_img(data);
	sprite_add(data, sprite_create((t_point2d){10, WH - 210},
			(t_point2d){200, 200}, int_to_rgb(BLUE)));
	object_add(data, object_create((t_point){100, 100, 100}, (t_point){100, 100, 100}, texture));
	return (data);
}

//do thing every frame
int	animation(t_data *d, int frame)
{
	static t_RGB	color;

	if (frame == 100000)
		frame = 0;
	if (frame % 5 == 0)
	{
		color = int_to_rgb(rand());
		sprite_edit(d, 0, sprite_create((t_point2d){10, WH - 210},
				(t_point2d){200, 200}, color));
	}
	if (frame % 800 == 0)
		object_pop(d, 0);
	return (frame);
}

int	loopydyloop(void *param)
{
	struct data		*d;
	static int		frame;

	frame++;
	d = (t_data *)param;
	frame = animation(d, frame);
	display_world_object(d);
	display_world_sprite(d);
	displayimg(d);
	return (0);
}

int	main(void)
{
	t_data	*data;

	data = initdata();
	mlx_key_hook(data->win.ptr, &keyhook, data);
	mlx_loop_hook(data->win.mlx, loopydyloop, data);
	mlx_loop(data->win.mlx);
	free_data(data);
	error_handler("Failed to init data", 1);
	return (0);
}
