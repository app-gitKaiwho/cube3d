/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvon-war <lvonwar@gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 15:03:50 by lvon-war          #+#    #+#             */
/*   Updated: 2024/03/25 19:32:36 by lvon-war         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

// put a sprite to img
void	sprite_put(t_data *d, t_sprite s)
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
/// @brief avoid poping the 5 first sprite as they are needed
/// @param d data structure
/// @param index pos
void	sprite_pop(t_data *d, int index)
{
	t_sprite	*tmp;
	int			i;
	int			found;

	i = -1;
	tmp = NULL;
	found = 0;
	if (d->world.nb_sprite <= 0)
		return ;
	if (index >= d->world.nb_sprite || index < 0)
		index = 0;
	if (d->world.nb_sprite > 1)
	{
		tmp = malloc(sizeof(t_sprite) * (d->world.nb_sprite - 1));
		while (++i < d->world.nb_sprite - 1)
		{
			if (i == index)
				found = 1;
			tmp[i] = d->world.c_sprite[i + found];
		}
	}
	free(d->world.c_sprite[index].texture);
	free(d->world.c_sprite);
	d->world.c_sprite = tmp;
	d->world.nb_sprite--;
}

//works on id bases so work for protected or tracked one only
void	sprite_edit(t_data *d, int index, t_sprite s)
{
	if (index < 0 || index >= d->world.nb_sprite)
		return ;
	if (d->world.c_sprite[index].texture)
		free(d->world.c_sprite[index].texture);
	d->world.c_sprite[index] = s;
}

/// @brief add a sprite to the world
/// @return id of the sprite
int	sprite_add(t_data *d, t_sprite s)
{
	t_sprite	*tmp;
	int			i;

	i = 0;
	tmp = malloc(sizeof(t_sprite) * (d->world.nb_sprite + 1));
	if (!tmp)
		error_handler("Failed to add sprite", 1);
	if (d->world.nb_sprite > 0)
	{
		while (i < d->world.nb_sprite)
		{
			tmp[i] = d->world.c_sprite[i];
			tmp[i].id = i;
			i++;
		}
		if (d->world.c_sprite)
			free(d->world.c_sprite);
	}
	tmp[i] = s;
	tmp[i].id = i;
	d->world.c_sprite = tmp;
	d->world.nb_sprite++;
	return (i);
}

/// @brief color to be changed for texture + be sure to follow it's memory
/// @param pos left corner of the object
/// @param size self explanatory
/// @param color self explanatory
t_sprite	sprite_create(t_point2d pos, t_point2d size, t_RGB color)
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
