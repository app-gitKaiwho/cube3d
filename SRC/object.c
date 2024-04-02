/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   object.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvon-war <lvonwar@gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 15:03:50 by lvon-war          #+#    #+#             */
/*   Updated: 2024/04/02 18:41:57 by lvon-war         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

void	objecttopoly(t_object *o)
{
	o->poly[0] = pointtopolygone(o->verti[0], o->verti[1], o->verti[2]);
	o->poly[1] = pointtopolygone(o->verti[0], o->verti[2], o->verti[3]);
	o->poly[2] = pointtopolygone(o->verti[3], o->verti[2], o->verti[6]);
	o->poly[3] = pointtopolygone(o->verti[3], o->verti[6], o->verti[7]);
	o->poly[4] = pointtopolygone(o->verti[7], o->verti[6], o->verti[5]);
	o->poly[5] = pointtopolygone(o->verti[7], o->verti[5], o->verti[4]);
	o->poly[6] = pointtopolygone(o->verti[4], o->verti[5], o->verti[1]);
	o->poly[7] = pointtopolygone(o->verti[4], o->verti[1], o->verti[0]);
	o->poly[8] = pointtopolygone(o->verti[1], o->verti[5], o->verti[6]);
	o->poly[9] = pointtopolygone(o->verti[1], o->verti[6], o->verti[2]);
	o->poly[10] = pointtopolygone(o->verti[0], o->verti[3], o->verti[7]);
	o->poly[11] = pointtopolygone(o->verti[0], o->verti[7], o->verti[4]);
}

t_object	object_create(t_point pos, t_point	si, t_RGB **textures)
{
	t_object	object;

	object.seen = 0;
	object.pos = pos;
	object.size = si;
	object.textures = textures;
	object.verti[0] = (t_point){pos.x - si.x / 2,
		pos.y - si.y / 2, pos.z - si.z / 2};
	object.verti[1] = (t_point){pos.x + si.x / 2,
		pos.y - si.y / 2, pos.z - si.z / 2};
	object.verti[2] = (t_point){pos.x + si.x / 2,
		pos.y + si.y / 2, pos.z - si.z / 2};
	object.verti[3] = (t_point){pos.x - si.x / 2,
		pos.y + si.y / 2, pos.z - si.z / 2};
	object.verti[4] = (t_point){pos.x - si.x / 2,
		pos.y - si.y / 2, pos.z + si.z / 2};
	object.verti[5] = (t_point){pos.x + si.x / 2,
		pos.y - si.y / 2, pos.z + si.z / 2};
	object.verti[6] = (t_point){pos.x + si.x / 2,
		pos.y + si.y / 2, pos.z + si.z / 2};
	object.verti[7] = (t_point){pos.x - si.x / 2,
		pos.y + si.y / 2, pos.z + si.z / 2};
	objecttopoly(&object);
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

void	object_to_render(t_data *d)
{
	int	i;
	int	j;

	i = 0;
	while (i < d->world.nb_obj)
	{
		j = 0;
		while (j < 12)
		{
			if (ispolyseen(d->player, d->world.c_obj[i].poly[j]))
				d->world.c_obj[i].poly[j].seen = 1;
			else
				d->world.c_obj[i].poly[j].seen = 0;
			j++;
		}
		i++;
	}
}
