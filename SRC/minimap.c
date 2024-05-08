/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spook <spook@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/08 11:02:20 by spook             #+#    #+#             */
/*   Updated: 2024/05/08 18:27:13 by spook            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"
void    player(t_data *d)
{
    put_square((t_pixel){d->player.pos.x * d->minimap.scale, d->player.pos.y * d->minimap.scale, d->minimap.player}, \
    (t_point){d->minimap.scale * d->player.size.x, d->minimap.scale * d->player.size.y}, d->minimapimg);    
}

void    put_walls(t_data *d)
{
    int i;
    int j;

    j = 0;
    while (j < d->map.size.y)
    {
        i = 0;
        while (i < d->map.size.x)
        {
            if (d->map.map[j][i] == '1')
                put_square((t_pixel){i * d->minimap.scale + 1 , j * d->minimap.scale + 1, d->minimap.wall}, \
                (t_point){d->minimap.scale - 1, d->minimap.scale - 1}, d->minimapimg);
            i++;
        }
        j++;
    }
}

void    minimap(t_data *d)
{
    put_square((t_pixel){0, 0, d->minimap.bg}, d->minimapimg.size, d->minimapimg);
    put_walls(d);
    player(d);
}