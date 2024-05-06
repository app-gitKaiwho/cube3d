/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_world.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvon-war <lvon-war@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 16:49:51 by lvon-war          #+#    #+#             */
/*   Updated: 2024/05/06 16:52:17 by lvon-war         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

/// @brief displays every global sprite
void	display_world_sprite(t_data *d)
{
	int		i;

	clear_img(d, d->hud);
	i = -1;
	if (d->world.nb_sprite <= 0)
		return ;
	while (++i < d->world.nb_sprite)
		sprite_put(d, d->world.c_sprite[i]);
	mlx_put_image_to_window(d->win.mlx, d->win.ptr, d->hud.img, 0, 0);
}

void	display_polygone(t_data *d, t_polygon p)
{
	int			i;
	t_polygon	poly;

	poly = p;
	i = -1;
	while (++i < 3)
		poly.verti[i] = pointcast(p.verti[i], *d);
	rasterizer(d, poly);
	i = -1;
	while (!d->option.wireframe && ++i < 3)
	{
		poly.edges[i] = vec3cast(p.edges[i], *d);
		put_line(poly.edges[i], d, int_to_rgb(RED), d->img);
	}
}

void	display_world_object(t_data *d)
{
	int		i;
	int		j;

	i = -1;
	if (d->world.nb_obj <= 0)
		return ;
	while (++i < d->world.nb_obj)
	{
		j = -1;
		while (++j < 12)
		{
			if (d->world.c_obj[i].poly[j].seen)
				display_polygone(d, d->world.c_obj[i].poly[j]);
		}
	}
}
