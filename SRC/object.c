/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   object.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvon-war <lvonwar@gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 15:03:50 by lvon-war          #+#    #+#             */
/*   Updated: 2024/03/18 20:53:06 by lvon-war         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

void	put_sprite(t_data *d, t_sprite s)
{
	int		i;
	int		j;
	int		n;
	t_pixel	p;

	n = 0;
	j = 0;
	while (j < s.size.y)
	{
		i = 0;
		while (i < s.size.x)
		{
			p.x = s.pos.x + i;
			p.y = s.pos.y + j;
			p.color = s.texture[n];
			put_pixel(p, d);
			i++;
			n++;
		}
		j++;
	}
}

/// @brief pop a chosen sprite. if it doesn't exist pop the first one
/// @param d data structure
/// @param index pos
void	pop_sprite(t_data *d, int index)
{
	t_sprite	*tmp;
	int			i;
	int			found;

	i = 0;
	found = 0;
	if (d->world.nb_sprite <= 0)
		return ;
	if (index >= d->world.nb_sprite || index < 0)
		index = 0;
	if (d->world.nb_sprite > 1)
	{
		tmp = malloc(sizeof(t_sprite) * (d->world.nb_sprite - 1));
		while (i < d->world.nb_sprite - 1)
		{
			if (i == index)
				found = 1;
			tmp[i] = d->world.c_sprite[i + found];
			i++;
		}
	}
	free(d->world.c_sprite[index].texture);
	free(d->world.c_sprite);
	d->world.c_sprite = tmp;
	d->world.nb_sprite--;
}
