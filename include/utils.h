/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spook <spook@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 12:14:25 by lvon-war          #+#    #+#             */
/*   Updated: 2024/04/21 00:57:16 by spook            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

# include "struct.h"

//init.c
t_data		*initdata(void);
void		initoption(t_data *d);
void		init_world(t_data *d);
void		minimap_init(t_data *d);

//utils.c 
t_RGB		*texture_monchrome_create(t_point2d size, t_RGB color);
t_RGB		*texture_pattern_create(t_point2d size, t_RGB color);
int			break_point(t_vector2d AB, t_point current);
void		error_handler(char *txt, int code);
int			rgb_to_int(t_RGB color);
t_RGB		int_to_rgb(int color);

//data_utils.c
void		object_free_texture(t_data *d);
void		free_data(t_data *data);
void		free_texture(t_RGB *t);

//utilsbis.c
t_polygon	pointtopolygone(t_point a, t_point b, t_point c);
t_point		vectounivec(t_point v);

#endif /*!CUBE_H */