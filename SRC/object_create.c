/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   object_create.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvon-war <lvonwar@gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 17:16:23 by lvon-war          #+#    #+#             */
/*   Updated: 2024/03/18 20:32:01 by lvon-war         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

void	sprite_add(t_data *d, t_sprite s)
{
	t_sprite	*tmp;
	int			i;

	i = 0;
	tmp = malloc(sizeof(t_sprite) * (d->world.nb_sprite + 1));
	if (d->world.nb_sprite > 0)
	{
		while (i < d->world.nb_sprite)
		{
			tmp[i] = d->world.c_sprite[i];
			i++;
		}
		if (d->world.c_sprite)
			free(d->world.c_sprite);
	}
	tmp[i] = s;
	d->world.c_sprite = tmp;
	d->world.nb_sprite++;
}

void	object_add(t_data *d, t_object o)
{
	(void)d;
	(void)o;
}

/// @brief color to be changed for texture + be sure to follow it's memory
/// @param pos left corner of the object
/// @param size self explanatory
/// @param color self explanatory
t_sprite	create_sprite(t_point2d pos, t_point2d size, t_RGB color)
{
	t_sprite	sprite;
	int			i;

	i = 0;
	sprite.pos = pos;
	sprite.size = size;
	sprite.texture = malloc(sizeof(t_RGB) * size.x * size.y);
	while (i < size.x * size.y)
		sprite.texture[i++] = color;
	return (sprite);
}

t_object	*create_object(t_point pos, t_point2d size, t_RGB color)
{
	(void)pos;
	(void)size;
	(void)color;
	return (NULL);
}
