/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvon-war <lvon-war@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/10 11:12:51 by lvon-war          #+#    #+#             */
/*   Updated: 2024/05/10 11:12:57 by lvon-war         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DISPLAY_H
# define DISPLAY_H

# include "struct.h"

//display.c 

void	put_pixel(t_pixel p, t_img img);
void	put_line(t_vector V, t_color color, t_img img);
void	put_square(t_pixel cen, t_point size, t_img img);
void	clear_img(t_img img);


#endif /*!DISPLAY_H */