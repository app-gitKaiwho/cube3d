/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calcbis.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spook <spook@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/03 14:23:39 by lvon-war          #+#    #+#             */
/*   Updated: 2024/04/18 16:42:00 by spook            ###   ########.fr       */
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

//return is bend direction : 1 right 0 left
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

void	rasterizer(t_data *d, t_polygon p)
{
	t_point	vert[3];
	int		i;

	(void )d;
	i = -1;
	while (++i < 3)
		vert[i] = p.verti[i];
	ft_printf("right ? [%d]\n", sortscanlines(vert));
}
