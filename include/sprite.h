/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvon-war <lvon-war@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/22 11:01:25 by lvon-war          #+#    #+#             */
/*   Updated: 2024/03/22 11:02:14 by lvon-war         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPRITE_H
# define SPRITE_H

# include "struct.h"

void		pop_sprite(t_data *d, int index);
void		put_sprite(t_data *d, t_sprite s);
int			sprite_add(t_data *d, t_sprite s);
void		edit_sprite(t_data *d, int index, t_sprite s);
t_sprite	create_sprite(t_point2d pos, t_point2d size, t_RGB color);


#endif /* SPRITE_H */