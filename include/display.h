/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvon-war <lvon-war@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 15:05:58 by lvon-war          #+#    #+#             */
/*   Updated: 2024/04/19 15:30:34 by lvon-war         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DISPLAY_H
# define DISPLAY_H

# include "struct.h"

//display.c 

void	clear_img(t_data *d);
void	displayimg(t_data *d);
void	display_world_sprite(t_data *d);
void	display_world_object(t_data *d);
void	put_pixel(t_pixel p, t_data *d);
void	put_line(t_vector AB, t_data *d, t_RGB color);
void	put_square(t_pixel center, t_point2d size, t_data *d);

#endif /*!DISPLAY_H */