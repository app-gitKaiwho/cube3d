/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvon-war <lvonwar@gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 11:48:49 by lvon-war          #+#    #+#             */
/*   Updated: 2024/03/12 10:53:46 by lvon-war         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

t_data	*initdata(void)
{
	t_data	*data;

	data = malloc(sizeof(t_data));
	data->pixel = initpixels();
	if (!data)
		error_handler("Failed to init data", 1);
	data->win.mlx = mlx_init();
	data->win.ptr = mlx_new_window(data->win.mlx, WL, WH, "My Window");
	data->img.img = mlx_new_image(data->win.mlx, WL, WH);
	data->img.addr = mlx_get_data_addr(data->img.img, &data->img.bpp,
			&data->img.line_size, &data->img.endian);
	mlx_hook(data->win.ptr, CLOSE_WINDOW_KEY, 0, &exit_hook, NULL);
	mlx_key_hook(data->win.ptr, &keyhook, NULL);
	return (data);
}

int	loopydyloop(void *param)
{
	struct data	*d;

	d = (t_data *)param;
	displayimg(d);
	return (0);
}

int	main(void)
{
	t_data	*data;

	data = initdata();
	put_pixel((t_point){WH / 2, WL / 2, 0, (t_RGB){0, 0, 255}}, data);
	mlx_loop_hook(data->win.mlx, loopydyloop, data);
	mlx_loop(data->win.mlx);
	free_data(data);
	return (0);
}
