/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spook <spook@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/12 10:22:59 by lvon-war          #+#    #+#             */
/*   Updated: 2024/04/21 04:23:32 by spook            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"
#include <stdio.h>
//remove after testing
void	test(t_data *d)
{
	t_RGB	**texture;

	texture = malloc(sizeof(t_RGB *) * 4);
	if (!texture)
		error_handler("Failed to init data", 1);
	texture[0] = texture_monchrome_create((t_point2d){100, 100},
			int_to_rgb(RED));
	texture[1] = texture_pattern_create((t_point2d){100, 100},
			int_to_rgb(GREEN));
	texture[2] = texture_pattern_create((t_point2d){100, 100},
			int_to_rgb(BLUE));
	texture[3] = texture_pattern_create((t_point2d){100, 100},
			int_to_rgb(YELLOW));
	sprite_add(d, sprite_create((t_point2d){10, WH - 210},
			(t_point2d){200, 200}, int_to_rgb(BLUE)));
	/*object_add(d, object_create((t_point)
		{40 * d->scale, 0.5 * d->scale, 50 * d->scale},
			(t_point){1 * d->scale, 1 * d->scale, 1 * d->scale}, 100, texture));
	*/object_add(d, object_create((t_point)
		{50 * d->scale, 5 * d->scale, 50 * d->scale},
			(t_point){10 * d->scale, 10 * d->scale, 10 * d->scale}, 100, texture));
}
