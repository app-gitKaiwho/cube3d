/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   object.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spook <spook@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 15:03:50 by lvon-war          #+#    #+#             */
/*   Updated: 2024/04/21 04:26:56 by spook            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

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

	tmp = NULL;
	found = 0;
	if (d->world.nb_obj <= 0)
		return ;
	if (index >= d->world.nb_obj || index < 0)
		index = 0;
	if (d->world.nb_obj > 1)
	{
		tmp = malloc(sizeof(t_object) * (d->world.nb_obj - 1));
		i = -1;
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

	i = -1;
	while (++i < d->world.nb_obj)
	{
		j = -1;
		while (++j < 12)
		{
			if (ispolyseen(d->player, d->world.c_obj[i].poly[j]))
				d->world.c_obj[i].poly[j].seen = 1;
			else
				d->world.c_obj[i].poly[j].seen = 0;
		}
	}
}

#include <stdio.h>
t_RGB	polygon_get_color(t_polygon p, int j)
{
	double	inc;
	double	x;
	double	l;

	inc = p.texturepos[0].y / (p.verti[0].y - p.verti[2].y);
	x = inc * (j - p.verti[2].y);
	l = interpolator2d(p.texturepos[0], p.texturepos[2], x);
	printf("%d\t", (int)round(l));
	return (p.textaddr[(int)round(x)]);
}
