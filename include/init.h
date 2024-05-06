/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvon-war <lvon-war@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 10:34:58 by lvon-war          #+#    #+#             */
/*   Updated: 2024/04/29 13:31:26 by lvon-war         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spook <spook@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 12:14:25 by lvon-war          #+#    #+#             */
/*   Updated: 2024/04/28 17:07:56 by spook            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INIT_H
# define INIT_H

# include "struct.h"

//init.c

t_data		*initdata(void);
void		initoption(t_data *d);
void		init_world(t_data *d);
void		minimap_init(t_data *d);
void		init_bg(t_data *d);

//initimg.c

void		init_bg(t_data *d);
void		init_objectimg(t_data *d);
void		init_hudimg(t_data *d);

#endif /*!INIT_H */