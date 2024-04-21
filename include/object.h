/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   object.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spook <spook@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 15:29:59 by lvon-war          #+#    #+#             */
/*   Updated: 2024/04/21 00:47:10 by spook            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OBJECT_H
# define OBJECT_H

# include "struct.h"

//objectinit.c
t_object	object_create(t_point pos, t_point size,int textsize, t_RGB **textures);
int			object_add(t_data *d, t_object o);

//object.c
void		object_to_render(t_data *d);
void		object_pop(t_data *d, int index);
t_RGB		polygon_get_color(t_polygon p, int i);
#endif /* OBJECT_H */