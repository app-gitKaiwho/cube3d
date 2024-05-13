/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angela <angela@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 11:48:49 by lvon-war          #+#    #+#             */
/*   Updated: 2024/05/13 10:37:43 by angela           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

int	animation(t_data *d, int frame)
{
	if (frame == 100000)
		frame = 0;
	clear_img(d->minimapimg);
	clear_img(d->img);
	minimap(d);
	put_bg(d->img, *d);
	castray(d);
	mlx_put_image_to_window(d->win.mlx, d->win.ptr, d->img.img, 0, 0);
	mlx_put_image_to_window(d->win.mlx, d->win.ptr, d->minimapimg.img, 0, 0);
	return (frame);
}

int	loopydyloop(void *param)
{
	t_data		*d;
	static int	frame;

	frame++;
	d = (t_data *)param;
	frame = animation(d, frame);
	return (0);
}

int	main(int argc, char **argv)
{
	t_data	*data;

	data = initdata(argc,argv);
	ft_printf("fooop\n");
	minimap(data);
	ft_printf("fooop1\n");
	castray(data);
	ft_printf("fooop2\n");
	mlx_mouse_hook(data->win.ptr, &mouse_hook, data);
	ft_printf("fooop3\n");
	mlx_hook(data->win.ptr, 6, 64, &mouse_move, data);
	mlx_hook(data->win.ptr, PRESS, PRESSMASK, &keyhook, data);
	mlx_hook(data->win.ptr, 17, 0, &exit_hook, data);
	mlx_loop_hook(data->win.mlx, loopydyloop, data);
	mlx_loop(data->win.mlx);
	free(data);
	return (0);
}
