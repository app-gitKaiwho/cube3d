/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvon-war <lvonwar@gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/24 19:50:35 by lvon-war          #+#    #+#             */
/*   Updated: 2024/03/24 20:09:35 by lvon-war         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "struct.h"

#ifndef MAP_H
# define MAP_H

t_minimap	minimap_init(void);
void		display_minimap(t_data *data);
#endif /*!MAP_H */