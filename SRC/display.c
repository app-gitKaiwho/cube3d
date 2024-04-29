/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvon-war <lvon-war@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 14:54:44 by lvon-war          #+#    #+#             */
/*   Updated: 2024/04/29 15:02:54 by lvon-war         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

/// @brief display the image on the window.
void	displayimg(t_data *d)
{
	if (d->bg.img)
		mlx_put_image_to_window(d->win.mlx, d->win.ptr, d->bg.img, 0, 0);
	if (d->img.img)
		mlx_put_image_to_window(d->win.mlx, d->win.ptr, d->img.img, 0, 0);
	if (d->hud.img)
		mlx_put_image_to_window(d->win.mlx, d->win.ptr, d->hud.img, 0, 0);
	if (d->option.minimap && d->minimapimg.img)
		mlx_put_image_to_window(d->win.mlx, d->win.ptr,
			d->minimapimg.img, 0, 0);
}

//add a pixel to img only for 2d object
void	put_pixel(t_pixel p, t_data *d, t_img img)
{
	int				index;

	if (p.x <= 0 || p.y <= 0 || p.x >= d->width || p.y >= d->height)
		return ;
	index = ((d->height - (int)p.y) * img.line_size + (int)p.x * img.bpp / 8);
	img.addr[index] = p.color.blue;
	img.addr[index + 1] = p.color.green;
	img.addr[index + 2] = p.color.red;
	img.addr[index + 3] = p.color.alpha;
}

#include <stdio.h>
void	put_point(t_point p, t_data *d, t_img img, t_RGB color)
{
	if (p.x <= 0 || p.y <= 0 || p.x >= d->width || p.y >= d->height)
		return ;
	if (d->buffer[(int)p.y][(int)p.x] < p.z)
	{
		d->buffer[(int)p.y][(int)p.x] = p.z;
		printf("put point\n");
	}
	put_pixel((t_pixel){p.x, p.y, color}, d, img);
}

//put a line to img
void	put_line(t_vector V, t_data *d, t_RGB color, t_img img)
{
	t_point	delta;
	t_point	inc;
	int		steps;
	int		i;

	delta.x = V.b.x - V.a.x;
	delta.y = V.b.y - V.a.y;
	if (fabs(delta.x) > fabs(delta.y))
		steps = fabs(delta.x);
	else
		steps = fabs(delta.y);
	delta.x = delta.x / steps;
	delta.y = delta.y / steps;
	inc.x = V.a.x;
	inc.y = V.a.y;
	i = -1;
	while (++i <= steps)
	{
		put_pixel((t_pixel){inc.x, inc.y, color}, d, img);
		inc.x += delta.x;
		inc.y += delta.y;
	}
}

// put a square to img
void	put_square(t_pixel cen, t_point2d size, t_data *d, t_img img)
{
	int	i;
	int	j;

	j = -1;
	while (++j < size.y)
	{
		i = -1;
		while (++i < size.x)
			put_pixel((t_pixel){cen.x + i, cen.y + j, cen.color}, d, img);
	}
}
