/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   controls.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spook <spook@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 12:02:40 by lvon-war          #+#    #+#             */
/*   Updated: 2024/05/02 16:15:35 by spook            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

// invoked when the window is closed.
int	exit_hook(void)
{
	exit(EXIT_SUCCESS);
}

int	player_moves(int keycode, t_data *d)
{
	if (keycode == UP)
		player_movement(d, (t_point){0, 0, 1});
	else if (keycode == DOWN)
		player_movement(d, (t_point){0, 0, -1});
	else if (keycode == LEFT)
		player_movement(d, (t_point){-1, 0, 0});
	else if (keycode == RIGHT)
		player_movement(d, (t_point){1, 0, 0});
	else if (keycode == ARROW_LEFT)
		player_movement(d, (t_point){0, 1, 0});
	else if (keycode == ARROW_RIGHT)
		player_movement(d, (t_point){0, -1, 0});
	else if (keycode == MAP)
	{
		if (d->minimap.scale == d->scale)
			d->minimap.scale = d->scale / 10;
		else
			d->minimap.scale = d->scale;
	}
	else
		return (0);
	return (1);
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
	if (keycode == OPTION5)
		d->option.five = !d->option.five;
	if (keycode == OPTION6)
		d->option.six = !d->option.six;
	if (keycode == OPTION7)
		d->option.seven = !d->option.seven;
}

// basic keyborde hook
int	keyhook(int keycode, void *param)
{
	struct data	*d;

	d = (t_data *)param;
	if (player_moves(keycode, d))
	{
		clear_img(d, d->img);
		clear_buffer(d);
		raycast(d);
		display_world_object(d);
		displayimg(d);
	}
	world_effect(keycode, d);
	options_key(keycode, d);
	if (keycode == ESC || keycode == CLOSE_WINDOW_KEY)
		exit(EXIT_SUCCESS);
	return (0);
}
