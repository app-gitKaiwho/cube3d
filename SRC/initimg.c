/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initimg.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvon-war <lvon-war@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 10:32:02 by lvon-war          #+#    #+#             */
/*   Updated: 2024/04/29 11:59:34 by lvon-war         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

void	init_bg(t_data *d)
{
	int		index;
	t_RGB	color;
	int		i;
	int		j;

	j = 0;
	d->bg.img = mlx_new_image(d->win.mlx, WL, WH);
	d->bg.addr = mlx_get_data_addr(d->bg.img, &d->bg.bpp,
		&d->bg.line_size, &d->bg.endian);
	color = int_to_rgb(d->world.earth);
	while (++j < WH)
	{
		i = 0;
		if (j > WH / 2)
			color = int_to_rgb(d->world.sky);	
		while (++i < WL)
		{
			index = ((WH - j) * d->bg.line_size + (int)i * d->bg.bpp / 8);
			d->bg.addr[index] = color.blue;
			d->bg.addr[index + 1] = color.green;
			d->bg.addr[index + 2] = color.red;
			d->bg.addr[index + 3] = 0;
		}
	}
}

void	init_objectimg(t_data *d)
{
	int		i;
	int		j;
	int		index;

	d->img.img = mlx_new_image(d->win.mlx, WL, WH);
	d->img.addr = mlx_get_data_addr(d->img.img, &d->img.bpp,
		&d->img.line_size, &d->img.endian);
	j = 0;
	while (++j < WH)
	{
		i = 0;
		while (++i < WL)
		{
			index = ((WH - j) * d->img.line_size + (int)i * d->img.bpp / 8);
			d->img.addr[index + 3] = (unsigned char)255;
		}
	}
}
