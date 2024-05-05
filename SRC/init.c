/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spook <spook@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/28 22:24:15 by lvon-war          #+#    #+#             */
/*   Updated: 2024/04/29 20:52:32 by spook            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

/// @brief should be initialised by input
void	minimap_init(t_data *d)
{
	d->minimapimg.img = mlx_new_image(d->win.mlx, WL, WH);
	d->minimapimg.addr = mlx_get_data_addr(d->minimapimg.img,
			&d->minimapimg.bpp, &d->minimapimg.line_size,
			&d->minimapimg.endian);
	clear_img(d, d->minimapimg);
	d->minimap.pos = (t_point2d){10, 10};
	d->minimap.scale = 1 * d->scale;
	d->minimap.color = (t_RGB){0, 0, 255, 0};
}

void	init_world(t_data *d)
{
	d->world.spawn = (t_point){0, 0, 0};
	d->world.size.x = 100 * d->scale;
	d->world.size.y = 100 * d->scale;
	d->world.earth = 0xbf9c6d;
	d->world.sky = 0x9deaed;
	d->world.nb_obj = 0;
	d->world.nb_sprite = 0;
	d->render_distance = (d->world.size.x + d->world.size.y) / 4;
}

void	initoption(t_data *d)
{
	d->option.minimap = 1;
	d->option.wireframe = 1;
	d->option.playerview = 0;
	d->option.raytoplayer = 0;
	d->option.five = 1;
	d->option.six = 1;
	d->option.seven = 0;
}

void	initscreenbuffer(t_data *d)
{
	int	i;
	int	j;

	d->buffer = malloc(sizeof(float) * d->height);
	if (!d->buffer)
		error_handler("Failed to init buffer", 1);
	j = 0;
	while (j < d->height)
	{
		d->buffer[j] = malloc(sizeof(float) * d->width);
		if (!d->buffer[j])
			error_handler("Failed to init buffer", 1);
		i = 0;
		while (i < d->width)
		{
			d->buffer[j][i] = -1;
			i++;
		}
		j++;
	}
}

t_data	*initdata(void)
{
	t_data	*data;

	data = malloc(sizeof(t_data));
	if (!data)
		error_handler("Failed to init data", 1);
	data->win.mlx = mlx_init();
	data->win.ptr = mlx_new_window(data->win.mlx, WL, WH, "My Window");
	mlx_hook(data->win.ptr, CLOSE_WINDOW_KEY, 0, &exit_hook, NULL);
	mlx_key_hook(data->win.ptr, &keyhook, NULL);
	data->width = WL;
	data->height = WH;
	data->fov = 90;
	data->scale = WL * 0.1;
	data->focal = data->width * 0.5 / tan(degtorad(data->fov * 0.5));
	init_world(data);
	minimap_init(data);
	player_init(data);
	initoption(data);
	init_img(data);
	initscreenbuffer(data);
	return (data);
}
