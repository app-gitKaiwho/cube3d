/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvon-war <lvonwar@gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 12:14:25 by lvon-war          #+#    #+#             */
/*   Updated: 2024/03/18 19:47:19 by lvon-war         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

# include "struct.h"

//utils.c 

int		break_point(t_vector AB, t_point current);
void	error_handler(char *txt, int code);
int		rgb_to_int(t_RGB color);
void	free_sprite(t_sprite *s);
void	free_data(t_data *data);
t_RGB	int_to_rgb(int color);

#endif /*!CUBE_H */