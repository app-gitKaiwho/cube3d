/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvon-war <lvonwar@gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 19:05:13 by lvon-war          #+#    #+#             */
/*   Updated: 2024/04/05 14:02:41 by lvon-war         ###   ########.fr       */
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

void	object_free_texture(t_data *d)
{
	int	i;

	i = -1;
	while (++i < 4)
		free_texture(d->world.c_obj->textures[i]);
	if (d->world.c_obj->textures)
		free(d->world.c_obj->textures);
}

//free win.mlx, world texture, world object and data itself
void	free_data(t_data *data)
{
	int	i;

	i = -1;
	free(data->win.mlx);
	while (++i < data->world.nb_sprite)
		free_texture(data->world.c_sprite[i].texture);
	object_free_texture(data);
	if (data->world.c_sprite)
		free(data->world.c_sprite);
	if (data->world.c_obj)
		free(data->world.c_obj);
	free(data);
}
