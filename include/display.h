/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvon-war <lvonwar@gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 15:05:58 by lvon-war          #+#    #+#             */
/*   Updated: 2024/03/11 18:40:34 by lvon-war         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DISPLAY_H
# define DISPLAY_H

# include "struct.h"

//display.c 

void	displayimg(t_data *d);
void	put_pixel(t_point p, t_data *d);

#endif /*!DISPLAY_H */