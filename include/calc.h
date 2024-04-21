/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calc.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spook <spook@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 14:02:44 by lvon-war          #+#    #+#             */
/*   Updated: 2024/04/21 03:44:09 by spook            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CALC_H
# define CALC_H

# include "struct.h"

//calc.c

t_point		pointcast(t_point point, t_data d);
int			ispointincast(t_point p, t_point A, t_point B, t_point tocheck);
int			ispolyseen(t_player p, t_polygon obj);

//calcbis.c

void		rasterizer(t_data *d, t_polygon p);
int	        interpolator(t_point start, t_point end, int y);
double      interpolator2d(t_point2d start, t_point2d end, double y);

//calcter.c

int			delta(int a, int b);
double		slope(t_point a, t_point b);
double		degtorad(double degree);
void		swappoints(t_point *a, t_point *b);
void	    swappoints2d(t_point2d *a, t_point2d *b);

//calcquater.c

#endif /*!CALC_H */