/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spook <spook@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/08 14:54:39 by spook             #+#    #+#             */
/*   Updated: 2024/05/12 02:09:38 by spook            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RAYCAST_H
# define RAYCAST_H

# include "struct.h"

typedef struct int_point
{
    int x;
    int y;
}	t_int_point;

typedef struct movement
{
    t_point dir;
    t_point inc;
    t_point step;
    t_point dist;
    t_int_point mapcurr;
}	t_movement;

//raycast.c

t_ray raycast(t_data *d, t_point p, int max_length, int angle);

#endif /*!RAYCAST_H */