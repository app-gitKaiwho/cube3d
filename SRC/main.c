/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvon-war <lvonwar@gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 11:48:49 by lvon-war          #+#    #+#             */
/*   Updated: 2024/03/18 20:50:27 by lvon-war         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

t_world	init_world(void)
{
	t_world	world;

	world.spawn = (t_point){0, 0, 0};
	world.nb_obj = 0;
	world.nb_sprite = 0;
	return (world);
}

t_data	*initdata(void)
{
	t_data	*data;

	data = malloc(sizeof(t_data));
	if (!data)
		error_handler("Failed to init data", 1);
	data->win.mlx = mlx_init();
	data->win.ptr = mlx_new_window(data->win.mlx, WL, WH, "My Window");
	data->img.img = mlx_new_image(data->win.mlx, WL, WH);
	data->img.addr = mlx_get_data_addr(data->img.img, &data->img.bpp,
			&data->img.line_size, &data->img.endian);
	clear_img(data);
	mlx_hook(data->win.ptr, CLOSE_WINDOW_KEY, 0, &exit_hook, NULL);
	mlx_key_hook(data->win.ptr, &keyhook, NULL);
	data->world = init_world();
	sprite_add(data, create_sprite((t_point2d){WL / 2, WH - (300 + 10)},
			(t_point2d){300, 300}, int_to_rgb(RED)));
	sprite_add(data, create_sprite((t_point2d){WL / 2, 10},
			(t_point2d){300, 300}, int_to_rgb(GREEN)));
	return (data);
}

//animation leak is normal it's a feature
//it'll be changed once a animation fonc is created
int	loopydyloop(void *param)
{
	struct data		*d;
	static int		frame;
	//static t_RGB	color;

	frame++;
	d = (t_data *)param;
	/*
	if (frame % 100 == 0)
		color = int_to_rgb(rand());
	put_sprite(d, create_sprite((t_point2d){20, WH - (300 + 10)},
			(t_point2d){300, 300}, color));
	*/
	display_sprite(d);
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
