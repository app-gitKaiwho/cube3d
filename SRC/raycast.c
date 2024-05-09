/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spook <spook@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/08 14:53:46 by spook             #+#    #+#             */
/*   Updated: 2024/05/09 22:07:03 by spook            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

void    displayonminimap(t_data *d, t_point start, t_point end)
{
    start.x *= d->minimap.scale;
    start.y *= d->minimap.scale;
    end.x *= d->minimap.scale;
    end.y *= d->minimap.scale;
    put_line((t_vector){start, end},(t_color){255, 0, 255, 0}, d->minimapimg);
}

void    draw_wall(t_data *d, t_point start, t_point end, int n, int face)
{
    float   dist;
    t_color color;

    color = (t_color){255, 0, 0, 0};
    if (face == 1)
        color = (t_color){0, 255, 0, 0};
    if (face == 2)
        color = (t_color){0, 0, 255, 0};
    if (face == 3)
        color = (t_color){255, 255, 0, 0};
    if (face == 4)
        color = (t_color){255, 0, 255, 0};
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
    int     face;

    n = 0;
    face = 0;
    angle = d->player.dir - d->fov / 2;
    while (angle < d->player.dir + d->fov / 2)
    {
        dir.y = sin(angle) * 0.001;
        dir.x = cos(angle) * 0.001;
        start = (t_point){(d->player.pos.x + d->player.size.x / 2), (d->player.pos.y + d->player.size.y / 2)};
        end = (t_point){start.x, start.y};
        while (end.x >= 0 && end.x < d->map.size.x && end.y >= 0 && end.y < d->map.size.y)
        {   
            if ((end.x - (int)end.x) < 0.001)
            {
                if (d->map.map[(int)(end.y + dir.y)][(int)(end.x + dir.x)] == '1')
                {
                    face = 1;
                    if (dir.x < 0)
                        face = 2;
                    break ;
                }
            }
            if ((end.y - (int)end.y) < 0.001)
            {
                if (d->map.map[(int)(end.y + dir.y)][(int)(end.x + dir.x)] == '1')
                {
                    face = 3;
                    if (dir.y < 0)
                        face = 4;
                    break ;
                }
            }
            end.x += dir.x;
            end.y += dir.y;
        }
        displayonminimap(d, start, end);
        draw_wall(d, start, end, n, face);
        angle += d->fov / ((d->scsize.x - 1));
        n++;
    }
}