/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utilsbis.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvon-war <lvon-war@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 09:31:48 by lvon-war          #+#    #+#             */
/*   Updated: 2024/04/29 14:24:23 by lvon-war         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

t_polygon	pointtopolygone(t_point a, t_point b, t_point c)
{
	t_polygon	poly;

	poly.verti[0] = a;
	poly.verti[1] = b;
	poly.verti[2] = c;
	poly.edges[0] = (t_vector){a, b};
	poly.edges[1] = (t_vector){b, c};
	poly.edges[2] = (t_vector){c, a};
	return (poly);
}

t_point	vectounivec(t_point v)
{
	if (v.x != 0)
		v.x /= fabs(v.x);
	if (v.y != 0)
		v.y /= fabs(v.y);
	if (v.z != 0)
		v.z /= fabs(v.z);
	return (v);
}

void	clear_img(t_data *d, t_img img)
{
	int		index;
	int		i;
	int		j;

	j = 0;
	while (++j < d->height)
	{
		i = 0;
		while (++i < d->width)
		{
			index = ((d->height - j) * img.line_size + (int)i * img.bpp / 8);
			img.addr[index] = 0;
			img.addr[index + 1] = 0;
			img.addr[index + 2] = 0;
			img.addr[index + 3] = (unsigned char)255;
		}
	}
}
