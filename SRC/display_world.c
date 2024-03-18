/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_world.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvon-war <lvonwar@gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 16:49:51 by lvon-war          #+#    #+#             */
/*   Updated: 2024/03/18 17:15:23 by lvon-war         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

void	display_sprite(t_data *d)
{
	int		i;

	i = 0;
	if (d->world.nb_sprite <= 0)
		return ;
	while (i < d->world.nb_sprite)
	{
		put_sprite(d, d->world.c_sprite[i]);
		i++;
	}
}

