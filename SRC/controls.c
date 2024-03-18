/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   controls.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvon-war <lvonwar@gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 12:02:40 by lvon-war          #+#    #+#             */
/*   Updated: 2024/03/18 16:19:51 by lvon-war         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

// invoked when the window is closed.
int	exit_hook(void)
{
	exit(EXIT_SUCCESS);
}

// basic keyborde hook
int	keyhook(int keycode, void *param)
{
	struct data	*d;

	d = (t_data *)param;
	if (keycode == ESC || keycode == CLOSE_WINDOW_KEY || keycode == LEAN_LEFT)
		exit(EXIT_SUCCESS);
	if (keycode == RESET)
		clear_img(d);
	if (keycode == PLUS)
		return (0);
	if (keycode == MINUS)
	{
		put_sprite(d, create_sprite((t_point2d){-500, 200},
				(t_point2d){1000, 100}, int_to_rgb(RED)));
	}
	return (0);
}
