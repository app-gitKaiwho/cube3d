/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   object.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvon-war <lvon-war@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 15:29:59 by lvon-war          #+#    #+#             */
/*   Updated: 2024/04/19 15:31:08 by lvon-war         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OBJECT_H
# define OBJECT_H

# include "struct.h"

//objectinit.c
t_object	object_create(t_point pos, t_point size, t_RGB **textures);
int			object_add(t_data *d, t_object o);

//object.c
void		object_pop(t_data *d, int index);
void		object_to_render(t_data *d);
t_RGB		polygon_get_color(t_polygon p);

#endif /* OBJECT_H */