/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvon-war <lvon-war@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 14:54:44 by lvon-war          #+#    #+#             */
/*   Updated: 2024/03/15 12:37:24 by lvon-war         ###   ########.fr       */
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
	int		index;

	index = ((WH - (int)p.y) * d->img.line_size + (int)p.x * d->img.bpp / 8);
	d->img.addr[index] = p.color.blue;
	d->img.addr[index + 1] = p.color.green;
	d->img.addr[index + 2] = p.color.red;
}

void	put_line(t_vector AB, t_data *d)
{
	t_point	p;
	double	slope;
	double	inc;

	inc = 0.1;
	slope = calculate_slope(AB);
	p = (t_point){AB.a.x, AB.a.y, 0, (t_RGB){255, 255, 255}};
	while (p.x / AB.b.x < 1 && p.y / AB.b.y < 1)
	{
		p.x = p.x + (slope * inc);
		p.y = p.y + (slope * inc);
		if (p.x < 0)
			p.x = 0;
		if (p.y < 0)
			p.y = 0;
		if (p.x > WL)
			p.x = WL;
		if (p.y > WH)
			p.y = WH;
		p.color = (t_RGB){255, 255, 255};
		put_pixel(p, d);
	}
}

void	clear_img(t_data *d)
{
	int		i;
	int		j;

	i = 0;
	while (i < WH)
	{
		j = 0;
		while (j < WL)
		{
			put_pixel((t_point){i, j, 0, (t_RGB){0, 0, 0}}, d);
			j++;
		}
		i++;
	}
}
