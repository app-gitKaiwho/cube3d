/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   object.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvon-war <lvon-war@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 15:29:59 by lvon-war          #+#    #+#             */
/*   Updated: 2024/03/22 13:25:33 by lvon-war         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OBJECT_H
# define OBJECT_H

# include "struct.h"

t_object	*create_object(t_point pos, t_point2d size, t_RGB **textures);

#endif /* OBJECT_H */