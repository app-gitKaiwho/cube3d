/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvon-war <lvon-war@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 19:05:13 by lvon-war          #+#    #+#             */
/*   Updated: 2024/03/22 11:14:22 by lvon-war         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

//free a texture after checking if it's not NULL
void	free_texture(t_RGB *t)
{
	if (t)
	{
		free(t);
		t = NULL;
	}
}


//free win.mlx, world texture, world object and data itself
void	free_data(t_data *data)
{
	int	i;

	i = 0;
	free(data->win.mlx);
	while (data->world.nb_sprite > i)
	{
		free_texture(data->world.c_sprite[i].texture);
		i++;
	}
	if (data->world.c_sprite)
		free(data->world.c_sprite);
	if (data->world.c_obj)
		free(data->world.c_obj);
	free(data);
}
