/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvon-war <lvonwar@gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 14:54:44 by lvon-war          #+#    #+#             */
/*   Updated: 2024/03/11 21:11:10 by lvon-war         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

void	displayimg(t_data *d)
{
	if (d->img.img)
		mlx_put_image_to_window(d->win.mlx, d->win.ptr, d->img.img, 0, 0);
}

void	put_pixel(t_point p, t_data *d)
{
	d->img.addr[(int)p.y * d->img.line_size + (int)p.x * d->img.bpp / 8] = p.color.blue;
	d->img.addr[(int)p.y * d->img.line_size + (int)p.x * d->img.bpp / 8 + 1] = p.color.green;
	d->img.addr[(int)p.y * d->img.line_size + (int)p.x * d->img.bpp / 8 + 2] = p.color.red;
}
