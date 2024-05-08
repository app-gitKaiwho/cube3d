/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spook <spook@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/08 10:15:53 by spook             #+#    #+#             */
/*   Updated: 2024/05/08 16:02:25 by spook            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

void	put_pixel(t_pixel p, t_img img)
{
	int		index;

	if (p.x <= 0 || p.y <= 0 || p.x >= img.size.x || p.y >= img.size.y)
		return ;
	index = ((img.size.y - (int)p.y) * img.line_size + (int)p.x * img.bpp / 8);
	img.addr[index] = p.color.blue;
	img.addr[index + 1] = p.color.green;
	img.addr[index + 2] = p.color.red;
}

void	put_line(t_vector V, t_color color, t_img img)
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
		put_pixel((t_pixel){inc.x, inc.y, color}, img);
		inc.x += delta.x;
		inc.y += delta.y;
	}
}

void	put_square(t_pixel cen, t_point size, t_img img)
{
	int	i;
	int	j;

	j = -1;
	while (++j < size.y)
	{
		i = -1;
		while (++i < size.x)
			put_pixel((t_pixel){cen.x + i, cen.y + j, cen.color}, img);
	}
}

void	clear_img(t_img img)
{
	int		index;
	int		i;
	int		j;

	j = 0;
	while (++j < img.size.y)
	{
		i = 0;
		while (++i < img.size.x)
		{
			index = ((img.size.y - j) * img.line_size + (int)i * img.bpp / 8);
			img.addr[index] = 0;
			img.addr[index + 1] = 0;
			img.addr[index + 2] = 0;
		}
	}
}
