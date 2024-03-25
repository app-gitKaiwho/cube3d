/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   object.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvon-war <lvonwar@gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 15:03:50 by lvon-war          #+#    #+#             */
/*   Updated: 2024/03/25 18:14:34 by lvon-war         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

t_object	object_create(t_point pos, t_point	size, t_RGB **textures)
{
	t_object	object;

	object.seen = 0;
	object.pos = pos;
	object.size = size;
	object.textures = textures;
	return (object);
}

/// @brief add an object to the world
/// @return id of the object
int	object_add(t_data *d, t_object o)
{
	t_object	*tmp;
	int			i;

	i = 0;
	tmp = malloc(sizeof(t_object) * (d->world.nb_obj + 1));
	if (!tmp)
		error_handler("Failed to add object", 1);
	if (d->world.nb_obj > 0)
	{
		while (i < d->world.nb_obj)
		{
			tmp[i] = d->world.c_obj[i];
			tmp[i].id = i;
			i++;
		}
		if (d->world.c_obj)
			free(d->world.c_obj);
	}
	tmp[i] = o;
	tmp[i].id = i;
	d->world.c_obj = tmp;
	d->world.nb_obj++;
	return (i);
}

/// @brief pop a chosen sprite. if it doesn't exist pop the first one
/// @param d data structure
/// @param index pos
void	object_pop(t_data *d, int index)
{
	t_object	*tmp;
	int			i;
	int			found;

	i = -1;
	tmp = NULL;
	found = 0;
	if (d->world.nb_obj <= 0)
		return ;
	if (index >= d->world.nb_obj || index < 0)
		index = 0;
	if (d->world.nb_obj > 1)
	{
		tmp = malloc(sizeof(t_object) * (d->world.nb_obj - 1));
		while (++i < d->world.nb_obj - 1)
		{
			if (i == index)
				found = 1;
			tmp[i] = d->world.c_obj[i + found];
		}
	}
	object_free_texture(d);
	free(d->world.c_obj);
	d->world.c_obj = tmp;
	d->world.nb_obj--;
}

void	object_put(t_data *d, t_object o)
{
	int		i;
	int		j;
	int		n;
	t_pixel	p;

	n = 0;
	j = 0;
	while (j < o.size.y)
	{
		i = 0;
		while (i < o.size.x)
		{
			p.x = o.pos.x - (o.size.x / 2) + i;
			p.y = o.pos.y - (o.size.y / 2) + j;
			p.color = o.textures[0][n];
			put_pixel(p, d);
			i++;
			n++;
		}
		j++;
	}
	put_pixel((t_pixel){o.pos.x, o.pos.y, o.pos.z, int_to_rgb(BLUE)}, d);
}

void	object_to_render(t_data *d)
{
	int	i;

	i = 0;
	while (i < d->world.nb_obj)
	{
		if (isobjectincast(d->player, d->world.c_obj[i]))
			d->world.c_obj[i].seen = 1;
		else
			d->world.c_obj[i].seen = 0;
		i++;
	}
}
