/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvon-war <lvon-war@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/08 11:02:20 by spook             #+#    #+#             */
/*   Updated: 2024/05/13 13:24:54 by lvon-war         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

void	player(t_data *d)
{
	put_square((t_pixel){d->player.pos.x * d->minimap.scale.x, \
	d->player.pos.y * d->minimap.scale.y, d->minimap.player}, \
	(t_point){d->minimap.scale.x * d->player.size.x, d->minimap.scale.y \
	* d->player.size.y}, d->minimapimg);
}

void	wall_type(t_data *d, int j, int i)
{
	if (d->map.map[j][i] == '1')
		put_square((t_pixel){i * d->minimap.scale.x + 2, \
		j * d->minimap.scale.y, d->minimap.wall}, \
		(t_point){d->minimap.scale.x - 2, d->minimap.scale.y - 2}, \
		d->minimapimg);
	if (d->map.map[j][i] == '0')
		put_square((t_pixel){i * d->minimap.scale.x + 2, \
		j * d->minimap.scale.y, d->minimap.bg}, \
		(t_point){d->minimap.scale.x - 2, d->minimap.scale.y - 2}, \
		d->minimapimg);
	if (d->map.map[j][i] == '2')
		put_square((t_pixel){i * d->minimap.scale.x + 2, \
		j * d->minimap.scale.y, d->minimap.player}, \
		(t_point){d->minimap.scale.x - 2, d->minimap.scale.y - 2}, \
		d->minimapimg);
}

void	put_walls(t_data *d)
{
	int	i;
	int	j;

	j = 0;
	while (j < d->map.size.y)
	{
		i = 0;
		while (i < d->map.size.x)
		{
			wall_type(d, j, i);
			i++;
		}
		j++;
	}
}

void	minimap(t_data *d)
{
	put_square((t_pixel){0, 0, (t_color){0, 0, 0, (char)255}}, \
	(t_point){d->map.size.x * d->minimap.scale.x, \
	d->map.size.y * d->minimap.scale.y}, d->minimapimg);
	put_walls(d);
	player(d);
}	
