/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   object.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvon-war <lvonwar@gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 15:03:50 by lvon-war          #+#    #+#             */
/*   Updated: 2024/03/18 15:51:10 by lvon-war         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

//remove free when map is implemented
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
	if (s.texture)
		free(s.texture);
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
	{
		sprite.texture[i] = color;
		i++;
	}
	return (sprite);
}

t_object	*create_object(t_point pos, t_point2d size, t_RGB color)
{
	(void)pos;
	(void)size;
	(void)color;
	return (NULL);
}
