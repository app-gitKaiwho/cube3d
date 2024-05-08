/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spook <spook@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/08 14:53:46 by spook             #+#    #+#             */
/*   Updated: 2024/05/08 19:28:44 by spook            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"
#include <stdio.h>

void    displayonminimap(t_data *d, t_point start, t_point end)
{
    start.x *= d->minimap.scale;
    start.y *= d->minimap.scale;
    end.x *= d->minimap.scale;
    end.y *= d->minimap.scale;
    put_line((t_vector){start, end},(t_color){255, 0, 255, 0}, d->minimapimg);
}

#include <stdio.h>
void    draw_wall(t_data *d, t_point start, t_point end, int n)
{
    float   dist;
    t_color color;

    color = (t_color){255, 0, 0, 0};
    n = d->scsize.x - n;
    dist = sqrt(pow(end.x - start.x, 2) + pow(end.y - start.y, 2));
    dist = dist * cos(d->player.dir - atan2(end.y - start.y, end.x - start.x));
    put_line((t_vector){(t_point){n, (int)(d->scsize.y / 2) - 1}, (t_point){n, (int)(d->scsize.y / 2 + (d->scsize.y / 4 / dist))}}, color, d->img);
    put_line((t_vector){(t_point){n, (int)(d->scsize.y / 2) + 1}, (t_point){n, (int)(d->scsize.y / 2 - (d->scsize.y / 4 / dist))}}, color, d->img);
}

void    raycast(t_data *d)
{
    t_point start;
    t_point dir;
    t_point end;
    float   angle;
    int     n;

    n = 0;
    angle = d->player.dir - d->fov / 2;
    while (angle < d->player.dir + d->fov / 2)
    {
        dir.y = sin(angle) * 0.01;
        dir.x = cos(angle) * 0.01;
        start = (t_point){(d->player.pos.x + d->player.size.x / 2), (d->player.pos.y + d->player.size.y / 2)};
        end = (t_point){start.x, start.y};
        while (d->map.map[(int)end.y][(int)end.x] != '1')
        {
            end.x += dir.x;
            end.y += dir.y;
        }
        displayonminimap(d, start, end);
        draw_wall(d, start, end, n);
        angle += d->fov / (d->scsize.x - 1);
        n++;
    }
}