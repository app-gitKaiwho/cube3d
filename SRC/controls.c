/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   controls.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvon-war <lvonwar@gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 12:02:40 by lvon-war          #+#    #+#             */
/*   Updated: 2024/03/29 00:26:52 by lvon-war         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

// invoked when the window is closed.
int	exit_hook(void)
{
	exit(EXIT_SUCCESS);
}

void	player_keys(int keycode, t_data *d)
{
	if (keycode == UP)
		player_movement(d, (t_point){0, 1, 0});
	if (keycode == DOWN)
		player_movement(d, (t_point){0, -1, 0});
	if (keycode == LEFT)
		player_movement(d, (t_point){-1, 0, 0});
	if (keycode == RIGHT)
		player_movement(d, (t_point){1, 0, 0});
	if (keycode == ARROW_LEFT)
		player_movement(d, (t_point){0, 0, 1});
	if (keycode == ARROW_RIGHT)
		player_movement(d, (t_point){0, 0, -1});
	if (keycode == PLUS)
		d->focal += 10;
	if (keycode == MINUS)
		d->focal -= 10;
	if (keycode == LEAN_LEFT)
		d->fov -= 5;
	if (keycode == LEAN_RIGHT)
		d->fov += 5;
}

// basic keyborde hook
int	keyhook(int keycode, void *param)
{
	struct data	*d;

	d = (t_data *)param;
	player_keys(keycode, d);
	if (keycode == ESC || keycode == CLOSE_WINDOW_KEY)
		exit(EXIT_SUCCESS);
	if (keycode == RESET)
		clear_img(d);
	return (0);
}
