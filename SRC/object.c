/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   object.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvon-war <lvon-war@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 15:03:50 by lvon-war          #+#    #+#             */
/*   Updated: 2024/03/22 14:11:06 by lvon-war         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

t_object	object_create(t_point pos, t_point	size, t_RGB **textures)
{
	t_object	object;
	int			i;

	i = 0;
	object.pos = pos;
	object.size = size;
	object.textures = textures;
	return	(object);
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

void	object_free_texture(t_data *d)
{
	int	i;

	i = 0;
	while (d->world.c_obj->textures[i])
	{
		free(d->world.c_obj->textures[i]);
		i++;
	}
	if (d->world.c_obj->textures)
		free(d->world.c_obj->textures);
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
			p.x = o.pos.x + i;
			p.y = o.pos.y + j;
			p.color = o.textures[0][n];
			put_pixel(p, d);
			i++;
			n++;
		}
		j++;
	}
}
