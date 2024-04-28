/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   object.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spook <spook@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 15:29:59 by lvon-war          #+#    #+#             */
/*   Updated: 2024/04/28 09:35:56 by spook            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OBJECT_H
# define OBJECT_H

# include "struct.h"

typedef struct yupl
{
	int		y;
	double	ab;
	double	ac;
}	t_yupl;

typedef struct xupl
{
	int		x;
	double	ab;
	double	ac;
}	t_xupl;

typedef struct upl
{
	t_xupl	x;
	t_yupl	y;
}	t_upl;

//objectinit.c

t_object	object_create(t_point p, t_point s, int t, t_RGB **te);
int			object_add(t_data *d, t_object o);

//object.c

void		object_to_render(t_data *d);
void		object_pop(t_data *d, int index);

//texture mapping

int			sortscanlines(t_polygon *p);
t_RGB		sampler(t_polygon p, float u, float v);
float		percent(float n, float start, float end);
float		interpolator(t_point start, t_point end, float y);
float		interpolator2d(float start, float end, float percent);

#endif /* OBJECT_H */