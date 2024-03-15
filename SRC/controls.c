/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   controls.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvon-war <lvon-war@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 12:02:40 by lvon-war          #+#    #+#             */
/*   Updated: 2024/03/15 12:40:27 by lvon-war         ###   ########.fr       */
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
		put_line((t_vector){(t_point){0, 0, 0, (t_RGB){255, 255, 255}},
			(t_point){WL , WH / 2, 0, (t_RGB){255, 255, 255}}}, d);
	return (0);
}
