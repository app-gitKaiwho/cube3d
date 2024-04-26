/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   object.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spook <spook@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 15:29:59 by lvon-war          #+#    #+#             */
/*   Updated: 2024/04/24 22:53:37 by spook            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OBJECT_H
# define OBJECT_H

# include "struct.h"

typedef struct bornes
{
	double	l;
	double	r;
}	t_bornes;

typedef struct upl
{
	int		n;
	double	ab;
	double	ac;
}	t_upl;

typedef struct xupl
{
	int		x;
	double	ab;
	double	ac;
}	t_xupl;

//objectinit.c

t_object	object_create(t_point p, t_point s, int t, t_RGB **te);
int			object_add(t_data *d, t_object o);

//object.c

void		object_to_render(t_data *d);
void		object_pop(t_data *d, int index);

//texture mapping

int			sortscanlines(t_polygon *p);
t_RGB		sampler(t_polygon p, double u, double v);
double		interpolator(t_point start, t_point end, double y);

#endif /* OBJECT_H */