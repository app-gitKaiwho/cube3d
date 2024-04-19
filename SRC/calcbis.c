/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calcbis.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvon-war <lvon-war@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/03 14:23:39 by lvon-war          #+#    #+#             */
/*   Updated: 2024/04/19 09:37:15 by lvon-war         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

int	delta(int a, int b)
{
	if (a > b)
		return (a - b);
	else
		return (b - a);
}

void	swappoints(t_point *a, t_point *b)
{
	t_point	tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

//return is bend direction : right 1, left 0
int	sortscanlines(t_point	vert[3])
{
	if (vert[1].y > vert[0].y)
		swappoints(&vert[0], &vert[1]);
	if (vert[2].y > vert[1].y)
	{
		swappoints(&vert[1], &vert[2]);
		if (vert[1].y > vert[0].y)
			swappoints(&vert[1], &vert[0]);
	}
	if (vert[1].x > vert[2].x)
		return (1);
	return (0);
}

#include <stdio.h>
void	rasterizer(t_data *d, t_polygon p)
{
	t_point	vert[3];
	int		i;

	(void )d;
	i = -1;
	while (++i < 3)
		vert[i] = p.verti[i];
	printf("p.vert0: %f %f %f\t", p.verti[0].x, p.verti[0].y, p.verti[0].z);
	printf("p.vert1: %f %f %f\t", p.verti[1].x, p.verti[1].y, p.verti[1].z);
	printf("p.vert2: %f %f %f\n", p.verti[2].x, p.verti[2].y, p.verti[2].z);
	sortscanlines(vert);
	printf("vert0: %f %f %f\t", vert[0].x, vert[0].y, vert[0].z);
	printf("vert1: %f %f %f\t", vert[1].x, vert[1].y, vert[1].z);
	printf("vert2: %f %f %f\n\n", vert[2].x, vert[2].y, vert[2].z);
}
