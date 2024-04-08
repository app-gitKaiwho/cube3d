/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvon-war <lvonwar@gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 14:54:44 by lvon-war          #+#    #+#             */
/*   Updated: 2024/04/05 14:03:50 by lvon-war         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

/// @brief display the image on the window.
void	displayimg(t_data *d)
{
	if (d->img.img)
		mlx_put_image_to_window(d->win.mlx, d->win.ptr, d->img.img, 0, 0);
}

//add a pixel to img only for 2d object
void	put_pixel(t_pixel p, t_data *d)
{
	int		index;

	if (p.x <= 0 || p.y <= 0 || p.x >= WL || p.y >= WH)
		return ;
	index = ((WH - (int)p.y) * d->img.line_size + (int)p.x * d->img.bpp / 8);
	d->img.addr[index] = p.color.blue;
	d->img.addr[index + 1] = p.color.green;
	d->img.addr[index + 2] = p.color.red;
}

//put a line to img
void	put_line(t_vector V, t_data *d, t_RGB color)
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
		put_pixel((t_pixel){inc.x, inc.y, color}, d);
		inc.x += delta.x;
		inc.y += delta.y;
	}
}

// put a square to img
void	put_square(t_pixel cen, t_point2d size, t_data *d)
{
	int	i;
	int	j;

	j = -1;
	while (++j < size.y)
	{
		i = -1;
		while (++i < size.x)
			put_pixel((t_pixel){cen.x + i, cen.y + j, cen.color}, d);
	}
}

/// @brief clear the image with a default bg (change color)
void	clear_img(t_data *d)
{
	put_square((t_pixel){0, WH / 2, int_to_rgb(d->world.sky)},
		(t_point2d){WL, WH / 2}, d);
	put_square((t_pixel){0, 0, int_to_rgb(d->world.earth)},
		(t_point2d){WL, WH / 2}, d);
}
