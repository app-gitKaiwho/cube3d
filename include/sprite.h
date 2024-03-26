/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvon-war <lvonwar@gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/22 11:01:25 by lvon-war          #+#    #+#             */
/*   Updated: 2024/03/25 19:39:09 by lvon-war         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPRITE_H
# define SPRITE_H

# include "struct.h"

void		sprite_pop(t_data *d, int index);
void		sprite_put(t_data *d, t_sprite s);
int			sprite_add(t_data *d, t_sprite s);
void		sprite_edit(t_data *d, int index, t_sprite s);
t_sprite	sprite_create(t_point2d pos, t_point2d size, t_RGB color);

#endif /* SPRITE_H */