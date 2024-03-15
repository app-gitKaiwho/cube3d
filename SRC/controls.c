/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   controls.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvon-war <lvonwar@gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 12:02:40 by lvon-war          #+#    #+#             */
/*   Updated: 2024/03/15 19:24:18 by lvon-war         ###   ########.fr       */
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
		put_square((t_point){WL / 2, WH / 2, 0, (t_RGB){0, 0, 255}}, 100, 100, d);
	if (keycode == MINUS)
		put_line((t_vector){(t_point){100, WH / 2, 0, (t_RGB){0, 0, 255}},
			(t_point){WL + 1, WH / 2, 0, (t_RGB){0, 0, 255}}}, d);
	return (0);
}
