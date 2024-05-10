/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvon-war <lvon-war@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/08 14:54:39 by spook             #+#    #+#             */
/*   Updated: 2024/05/10 10:51:37 by lvon-war         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RAYCAST_H
# define RAYCAST_H

# include "struct.h"

typedef struct folder
{
	t_point		start;
	t_point		end;
	int			n;
	int			face;
}	t_folder;


//raycast.c

void	raycast(t_data *d);

#endif /*!RAYCAST_H */