/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   control.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spook <spook@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/08 13:49:29 by spook             #+#    #+#             */
/*   Updated: 2024/05/11 17:42:46 by spook            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

int	exit_hook(void)
{
	exit(EXIT_SUCCESS);
}

void	playerctrl(int keycode, t_data *d)
{
	t_point	dir;

	if (keycode == ARROW_UP)
	{
		dir.x = d->player.pos.x + cos(degtorad(d->player.dir)) * d->player.height;
		dir.y = d->player.pos.y + sin(degtorad(d->player.dir)) * d->player.height;
		player_movement(d, dir);
	}
	if (keycode == ARROW_DOWN)
	{
		dir.x = d->player.pos.x - cos(degtorad(d->player.dir)) * d->player.height;
		dir.y = d->player.pos.y - sin(degtorad(d->player.dir)) * d->player.height;
		player_movement(d, dir);
	}
	if (keycode == ARROW_LEFT)
	{
		d->player.dir += 15;
		if (d->player.dir >= 360)
			d->player.dir -= 360;
	}
	if (keycode == ARROW_RIGHT)
	{
		d->player.dir -= 15;
		if (d->player.dir < 0)
			d->player.dir += 360;
	}
	else
		return ;
}

void	hudctrl(int keycode, t_data *d)
{
	if (keycode == MAP)
	{

		mlx_destroy_image(d->win.mlx, d->minimapimg.img);
		if (d->minimap_scaled == 0)
		{
			d->minimap_scaled = 1;
			d->minimap = initminimap(d, 1);
		}
		else if (d->minimap_scaled == 1)
		{
			d->minimap_scaled = 0;
			d->minimap = initminimap(d, DEFAULMINI);
		}
	}
}

int	keyhook(int keycode, void *param)
{
	t_data	*d;

	d = (t_data *)param;
	if (keycode == ESC || keycode == CLOSE_WINDOW_KEY)
		exit(EXIT_SUCCESS);
	playerctrl(keycode, d);
	hudctrl(keycode, d);
	return (0);
}
