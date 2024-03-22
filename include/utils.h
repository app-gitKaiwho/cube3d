/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvon-war <lvon-war@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 12:14:25 by lvon-war          #+#    #+#             */
/*   Updated: 2024/03/22 14:09:06 by lvon-war         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

# include "struct.h"

//utils.c 

t_RGB	*texture_monchrome_create(t_point2d size, t_RGB color);
int			break_point(t_vector AB, t_point current);
void		error_handler(char *txt, int code);
t_sprite	*file_to_sprite(char *path);
int			rgb_to_int(t_RGB color);
void		free_sprite(t_sprite *s);
void		free_data(t_data *data);
t_RGB		int_to_rgb(int color);

#endif /*!CUBE_H */