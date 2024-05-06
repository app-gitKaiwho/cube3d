/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   controls.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvon-war <lvon-war@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 12:02:40 by lvon-war          #+#    #+#             */
/*   Updated: 2024/05/06 12:14:08 by lvon-war         ###   ########.fr       */
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
		player_movement(d, (t_point){0, 0, 0.5});
	else if (keycode == DOWN)
		player_movement(d, (t_point){0, 0, -0.5});
	else if (keycode == LEFT)
		player_movement(d, (t_point){-0.5, 0, 0});
	else if (keycode == RIGHT)
		player_movement(d, (t_point){0.5, 0, 0});
	else if (keycode == ARROW_LEFT)
		player_movement(d, (t_point){0, 0.5, 0});
	else if (keycode == ARROW_RIGHT)
		player_movement(d, (t_point){0, -0.5, 0});
	else if (keycode == MAP)
	{
		clear_img(d, d->minimapimg);
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

int	options_key(int keycode, t_data *d)
{
	if (keycode == OPTION1)
		d->option.minimap = !d->option.minimap;
	else if (keycode == OPTION2)
		d->option.raytoplayer = !d->option.raytoplayer;
	else if (keycode == OPTION3)
		d->option.playerview = !d->option.playerview;
	else if (keycode == OPTION4)
		d->option.wireframe = !d->option.wireframe;
	else if (keycode == OPTION5)
		d->option.five = !d->option.five;
	else if (keycode == OPTION6)
		d->option.six = !d->option.six;
	else if (keycode == OPTION7)
		d->option.seven = !d->option.seven;
	else
		return (0);
	return (1);
}

// basic keyborde hook
int	keyhook(int keycode, void *param)
{
	struct data	*d;

	d = (t_data *)param;
	if(player_moves(keycode, d) || 	options_key(keycode, d))
	{
		clear_img(d, d->img);
		clear_buffer(d);
		display_minimap(d);
		raycast(d);
		display_world_object(d);
		displayimg(d);
	}
	world_effect(keycode, d);
	if (keycode == ESC || keycode == CLOSE_WINDOW_KEY)
		exit(EXIT_SUCCESS);
	return (0);
}
