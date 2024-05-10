/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvon-war <lvon-war@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/08 10:08:33 by spook             #+#    #+#             */
/*   Updated: 2024/05/10 11:13:08 by lvon-war         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INIT_H
# define INIT_H

# include "struct.h"

//init.c 

t_data		*initdata(void);
t_minimap	initminimap(t_data *d, double scale);

#endif /*!INIT_H */