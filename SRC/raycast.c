/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spook <spook@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/08 14:53:46 by spook             #+#    #+#             */
/*   Updated: 2024/05/12 02:19:57 by spook            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

void get_dir(t_ray ray, int angle, t_movement *move)
{
	move->dir = (t_point){cos(degtorad(angle)), sin(degtorad(angle))};
	move->inc = (t_point){ sqrt(1 + (move->dir.y / move->dir.x) * \
	(move->dir.y / move->dir.x)),sqrt(1 + (move->dir.x / move->dir.y) \
	* (move->dir.x / move->dir.y))};
	move->mapcurr = (t_int_point){(int)ray.start.x, (int)ray.start.y};
	if (move->dir.x < 0)
	{
		move->step.x = -1;
		move->dist.x = (ray.start.x - (float)(move->mapcurr.x)) * move->inc.x;
	}
	else
	{
		move->step.x = 1;
		move->dist.x = ((float)(move->mapcurr.x + 1) - ray.start.x) * move->inc.x;
	}
	if (move->dir.y < 0)
	{
		move->step.y = -1;
		move->dist.y = (ray.start.y - (float)(move->mapcurr.y)) * move->inc.y;
	}
	else
	{
		move->step.y = 1;
		move->dist.y = ((float)(move->mapcurr.y + 1) - ray.start.y) * move->inc.y;
	}
}

void	horizontal(t_ray *ray, t_movement *move)
{
	move->mapcurr.x += move->step.x;
	ray->size = move->dist.x;
	move->dist.x += move->inc.x;
	if (move->step.x > 0)
		ray->face = 1;
	else
		ray->face = 3;
}

void	vertical(t_ray *ray, t_movement *move)
{
	move->mapcurr.y += move->step.y;
	ray->size = move->dist.y;
	move->dist.y += move->inc.y;
	if (move->step.y > 0)
		ray->face = 0;
	else
		ray->face = 2;
}
void	seek_wall(t_data *d, t_ray *ray, t_movement *move, int max_length)
{
	while (ray->size < max_length)
	{
		if (move->dist.x < move->dist.y)
			horizontal(ray, move);
		else
			vertical(ray, move);
		if (move->mapcurr.x >= 0 && move->mapcurr.x < d->map.size.x  \
		&& move->mapcurr.y >= 0 && move->mapcurr.y < d->map.size.y)
		{
			if (d->map.map[(int)move->mapcurr.y][(int)move->mapcurr.x] == '1')
				return;
		}
	}
}

t_ray	raycast(t_data *d, t_point p, int max_length, int angle)
{
	t_ray	ray;
	t_movement move;

	ray.start = p;
	ray.size = 0.0f;
	ray.face = 0;
	get_dir(ray, angle, &move);
	seek_wall(d, &ray, &move, max_length);
	ray.end.x = ray.start.x + move.dir.x * ray.size;
	ray.end.y = ray.start.y + move.dir.y * ray.size;
	return (ray);
}
