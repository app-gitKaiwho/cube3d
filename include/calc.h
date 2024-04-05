/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calc.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvon-war <lvonwar@gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 14:02:44 by lvon-war          #+#    #+#             */
/*   Updated: 2024/04/03 14:42:16 by lvon-war         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CALC_H
# define CALC_H

# include "struct.h"

t_point     pointcast(t_point point, t_data d);
int			ispointincast(t_point p, t_point A, t_point B, t_point tocheck);
int			ispolyseen(t_player p, t_polygon obj);
t_point		vecdeltacalc(t_vector V);

#endif /*!CALC_H */