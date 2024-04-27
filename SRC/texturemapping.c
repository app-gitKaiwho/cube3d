/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texturemapping.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spook <spook@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/21 14:18:46 by spook             #+#    #+#             */
/*   Updated: 2024/04/28 00:11:29 by spook            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

float	interpolator(t_point start, t_point end, float y)
{
	float	percent;
	float	deltax;
	float	deltay;

	deltax = start.x - end.x;
	deltay = start.y - end.y;
	if (deltay == 0)
		return (end.x);
	percent = (y - start.y) / (deltay);
	return (start.x + (deltax * percent));
}

//take u v value from 0 to 1
t_RGB	sampler(t_polygon p, float u, float v)
{
	int	i;
	int	j;

	i = round(u * (p.textsize - 1));
	j = round(v * (p.textsize - 1));
	if (i < 0)
		i = 0;
	if (j < 0)
		j = 0;
	if (i > (p.textsize - 1))
		i = p.textsize - 1;
	if (j > (p.textsize - 1))
		j = p.textsize - 1;
	return (p.textaddr[(i + (j * (p.textsize)))]);
}

//return is bend direction : right 1, left 0
int	sortscanlines(t_polygon *p)
{
	if (p->verti[1].y > p->verti[0].y)
	{
		swappoints(&p->verti[0], &p->verti[1]);
		swappoints(&p->texturepos[0], &p->texturepos[1]);
	}
	if (p->verti[2].y > p->verti[1].y)
	{
		swappoints(&p->verti[1], &p->verti[2]);
		swappoints(&p->texturepos[1], &p->texturepos[2]);
		if (p->verti[1].y > p->verti[0].y)
		{
			swappoints(&p->verti[1], &p->verti[0]);
			swappoints(&p->texturepos[1], &p->texturepos[0]);
		}
	}
	return (0);
}
