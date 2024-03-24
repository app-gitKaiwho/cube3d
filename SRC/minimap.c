/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvon-war <lvonwar@gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/24 19:38:03 by lvon-war          #+#    #+#             */
/*   Updated: 2024/03/24 22:29:39 by lvon-war         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

/// @brief should be initialised by input
t_minimap	minimap_init(void)
{
	t_minimap	minimap;

	minimap.size = (t_point2d){100, 100};
	minimap.pos = (t_point2d){WL - minimap.size.x - 10,
		WH - minimap.size.y - 10};
	minimap.scale = 10;
	minimap.color = int_to_rgb(BLUE);
	return (minimap);
}

void	display_minimap(t_data *data)
{
	t_pixel	p;

	p = (t_pixel){data->minimap.pos.x, data->minimap.pos.y,
		0, data->minimap.color};
	put_square(p, data->minimap.size, data);
}
