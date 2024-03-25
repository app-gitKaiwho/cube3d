/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calc.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvon-war <lvonwar@gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 14:02:44 by lvon-war          #+#    #+#             */
/*   Updated: 2024/03/25 18:13:36 by lvon-war         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CALC_H
# define CALC_H

# include "struct.h"

int     IsPointInCast(t_point p, t_point A, t_point B, t_point tocheck);
int     isobjectincast(t_player p, t_object obj);
double  calculate_slope(t_vector AB);
t_point vecdeltacalc(t_vector V);

#endif /*!CALC_H */