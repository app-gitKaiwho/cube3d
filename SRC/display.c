/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvon-war <lvonwar@gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 14:54:44 by lvon-war          #+#    #+#             */
/*   Updated: 2024/03/18 14:53:38 by lvon-war         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

void	displayimg(t_data *d)
{
	if (d->img.img)
		mlx_put_image_to_window(d->win.mlx, d->win.ptr, d->img.img, 0, 0);
}

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

void	put_line(t_vector V, t_data *d)
{
	t_point	delta;
	t_point	inc;
	double	steps;

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
	while ((int)(inc.x - V.b.x) < 1 && (int)(inc.y - V.b.y) < 1)
	{
		if (break_point(V, inc))
			break ;
		put_pixel((t_pixel){inc.x, inc.y, 0, (t_RGB){0, 0, 255}}, d);
		inc.x += delta.x;
		inc.y += delta.y;
	}
}

void	put_square(t_pixel cen, t_point2d size, t_data *d)
{
	int	i;
	int	j;

	j = 0;
	while (j < size.y)
	{
		i = 0;
		while (i < size.x)
		{
			put_pixel((t_pixel){cen.x + i, cen.y + j, 0, cen.color}, d);
			i++;
		}
		j++;
	}
}

/// @brief clear the image with a default bg (change color)
void	clear_img(t_data *d)
{
	put_square((t_pixel){0, WH / 2, 0, (t_RGB){102, 204, 255}},
		(t_point2d){WL, WH / 2}, d);
	put_square((t_pixel){0, 0, 0, (t_RGB){204, 204, 204}},
		(t_point2d){WL, WH / 2}, d);
}
