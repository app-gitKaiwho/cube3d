/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvon-war <lvon-war@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 12:14:25 by lvon-war          #+#    #+#             */
/*   Updated: 2024/04/29 14:24:55 by lvon-war         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

# include "struct.h"

//utils.c 

t_RGB		*texture_pattern_create(t_point2d size, t_RGB color);
void		error_handler(char *txt, int code);
t_RGB		int_to_rgb(int color);

//data_utils.c
void		object_free_texture(t_data *d);
void		free_data(t_data *data);
void		free_texture(t_RGB *t);

//utilsbis.c
t_polygon	pointtopolygone(t_point a, t_point b, t_point c);
void		clear_img(t_data *d, t_img img);
t_point		vectounivec(t_point v);

#endif /*!UTILS_H */