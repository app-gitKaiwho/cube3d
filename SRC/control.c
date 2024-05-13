/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   control.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spook <spook@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/08 13:49:29 by spook             #+#    #+#             */
/*   Updated: 2024/05/13 21:53:41 by spook            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

int	exit_hook(t_data *d)
{
	int	j;

	j = 0;
	while (j < d->map.size.y)
	{
		free(d->map.map[j]);
		j++;
	}
	free(d->map.map);
	exit(EXIT_SUCCESS);
}

void	playerctrl(int keycode, t_data *d)
{
	if (keycode == ARROW_UP || keycode == UP)
		player_movement(d, 0);
	if (keycode == LEFT)
		player_movement(d, 90);
	if (keycode == ARROW_DOWN || keycode == DOWN)
		player_movement(d, 180);
	if (keycode == RIGHT)
		player_movement(d, 270);
	if (keycode == ARROW_LEFT)
	{
		d->player.dir += 15;
		if ((int)d->player.dir >= 360)
			d->player.dir -= 360;
	}
	if (keycode == ARROW_RIGHT)
	{
		d->player.dir -= 15;
		if ((int)d->player.dir < 0)
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

void	action(int keycode, t_data *d)
{
	t_ray	ray;

	if (keycode == INTERACT)
	{
		ray = raycast(d, d->player.pos, d->player.speed, d->player.dir);
		if (ray.walltype == '2')
			d->map.map[(int)ray.mapcurr.y][(int)ray.mapcurr.x] = '0';
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
	action(keycode, d);
	return (0);
}
