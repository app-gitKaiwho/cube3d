/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spook <spook@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/08 11:02:20 by spook             #+#    #+#             */
/*   Updated: 2024/05/12 13:53:05 by spook            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

void	player(t_data *d)
{
	put_square((t_pixel){d->player.pos.x * d->minimap.scale, \
	d->player.pos.y * d->minimap.scale, d->minimap.player}, \
	(t_point){d->minimap.scale * d->player.size.x, d->minimap.scale \
	* d->player.size.y}, d->minimapimg);
}

void	wall_type(t_data *d, int j, int i)
{
	if (d->map.map[j][i] == '1')
		put_square((t_pixel){i * d->minimap.scale + 1, \
		j * d->minimap.scale, d->minimap.wall}, \
		(t_point){d->minimap.scale - 1, d->minimap.scale - 1}, \
		d->minimapimg);
	if (d->map.map[j][i] == '0')
		put_square((t_pixel){i * d->minimap.scale + 1, \
		j * d->minimap.scale, d->minimap.bg}, \
		(t_point){d->minimap.scale - 1, d->minimap.scale - 1}, \
		d->minimapimg);
	if (d->map.map[j][i] == '2')
		put_square((t_pixel){i * d->minimap.scale + 1, \
		j * d->minimap.scale, d->minimap.player}, \
		(t_point){d->minimap.scale - 1, d->minimap.scale - 1}, \
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
	put_walls(d);
	player(d);
}
