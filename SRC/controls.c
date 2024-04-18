/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   controls.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spook <spook@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 12:02:40 by lvon-war          #+#    #+#             */
/*   Updated: 2024/04/15 20:24:05 by spook            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

// invoked when the window is closed.
int	exit_hook(void)
{
	exit(EXIT_SUCCESS);
}

void	player_moves(int keycode, t_data *d)
{
	if (keycode == UP)
		player_movement(d, (t_point){0, 0, 1});
	if (keycode == DOWN)
		player_movement(d, (t_point){0, 0, -1});
	if (keycode == LEFT)
		player_movement(d, (t_point){-1, 0, 0});
	if (keycode == RIGHT)
		player_movement(d, (t_point){1, 0, 0});
	if (keycode == ARROW_LEFT)
		player_movement(d, (t_point){0, 1, 0});
	if (keycode == ARROW_RIGHT)
		player_movement(d, (t_point){0, -1, 0});
	if (keycode == MAP)
	{
		if (d->minimap.scale == d->scale)
			d->minimap.scale = d->scale / 10;
		else
			d->minimap.scale = d->scale;
	}
}

void	world_effect(int keycode, t_data *d)
{
	if (keycode == PLUS)
		d->focal += 10;
	if (keycode == MINUS)
		d->focal -= 10;
}

void	options_key(int keycode, t_data *d)
{
	if (keycode == OPTION1)
		d->option.minimap = !d->option.minimap;
	if (keycode == OPTION2)
		d->option.raytoplayer = !d->option.raytoplayer;
	if (keycode == OPTION3)
		d->option.playerview = !d->option.playerview;
	if (keycode == OPTION4)
		d->option.wireframe = !d->option.wireframe;
}

// basic keyborde hook
int	keyhook(int keycode, void *param)
{
	struct data	*d;

	d = (t_data *)param;
	player_moves(keycode, d);
	world_effect(keycode, d);
	options_key(keycode, d);
	if (keycode == ESC || keycode == CLOSE_WINDOW_KEY)
		exit(EXIT_SUCCESS);
	if (keycode == RESET)
		clear_img(d);
	return (0);
}
