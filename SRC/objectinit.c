/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   objectinit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spook <spook@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/15 13:05:38 by lvon-war          #+#    #+#             */
/*   Updated: 2024/04/18 13:15:38 by spook            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

void	polytexturemapping(t_object *o)
{
	int	i;

	i = 0;
	while (i < 12)
	{
		if ((i / 2) < 4)
			o->poly[i].textaddr = o->textures[i / 2];
		else
			o->poly[i].textaddr = o->textures[0];
		if (i % 2 == 0)
		{
			o->poly[i].texturepos[0] = (t_point2d){0, 0};
			o->poly[i].texturepos[1] = (t_point2d){0, 1};
			o->poly[i].texturepos[2] = (t_point2d){1, 1};
		}
		else
		{
			o->poly[i].texturepos[0] = (t_point2d){0, 0};
			o->poly[i].texturepos[1] = (t_point2d){1, 1};
			o->poly[i].texturepos[2] = (t_point2d){1, 0};
		}
		i++;
	}
}

//in order : front right back left top bottom
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
	polytexturemapping(o);
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
	object.verti[1] = (t_point){pos.x - si.x / 2,
		pos.y + si.y / 2, pos.z - si.z / 2};
	object.verti[2] = (t_point){pos.x + si.x / 2,
		pos.y + si.y / 2, pos.z - si.z / 2};
	object.verti[3] = (t_point){pos.x + si.x / 2,
		pos.y - si.y / 2, pos.z - si.z / 2};
	object.verti[4] = (t_point){pos.x - si.x / 2,
		pos.y - si.y / 2, pos.z + si.z / 2};
	object.verti[5] = (t_point){pos.x - si.x / 2,
		pos.y + si.y / 2, pos.z + si.z / 2};
	object.verti[6] = (t_point){pos.x + si.x / 2,
		pos.y + si.y / 2, pos.z + si.z / 2};
	object.verti[7] = (t_point){pos.x + si.x / 2,
		pos.y - si.y / 2, pos.z + si.z / 2};
	objecttopoly(&object);
	return (object);
}
