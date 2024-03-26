/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calc.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvon-war <lvonwar@gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 14:02:44 by lvon-war          #+#    #+#             */
/*   Updated: 2024/03/26 10:39:36 by lvon-war         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CALC_H
# define CALC_H

# include "struct.h"

t_point2d	pointcast(t_point point, t_data d);
t_vector2d	vec3cast(t_vector V, t_data d);
int			ispointincast(t_point p, t_point A, t_point B, t_point tocheck);
int			isobjectincast(t_player p, t_object obj);
t_point		vecdeltacalc(t_vector V);

#endif /*!CALC_H */