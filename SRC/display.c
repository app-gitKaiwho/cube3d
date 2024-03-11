/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvon-war <lvon-war@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 14:54:44 by lvon-war          #+#    #+#             */
/*   Updated: 2024/03/11 15:15:44 by lvon-war         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

void	displayimg(t_data *d)
{
	if (d->img.img)
	{
		mlx_put_image_to_window(d->win.mlx, d->win.ptr, d->img.img, 0, 0);
		mlx_destroy_image(d->win.mlx, d->img.img);
		d->img.img = mlx_new_image(d->win.mlx, WL, WH);
		d->img.data = mlx_get_data_addr(d->img.img, &d->img.bpp,
				&d->img.line_size, &d->img.endian);
	}
}

void	fillimg(t_data *d)
{
	mlx_pixel_put(d->win.mlx, d->win.ptr, WL / 2, WH / 2,
		rgb_to_int((t_RGB){255, 255, 255}));
}
