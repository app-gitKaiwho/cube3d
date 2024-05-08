/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spook <spook@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/08 10:08:08 by spook             #+#    #+#             */
/*   Updated: 2024/05/08 19:29:25 by spook            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

//replace by parsing
t_map   initmap(t_data *d)
{
    t_map   m;
    int     i;
    int     j;
    int     n;
    char    testmap[] = {
    '1','1','1','1','1','1','1','1','1','1',
    '1','0','0','0','0','0','0','0','0','1',
    '1','0','1','1','1','1','1','0','0','1',
    '1','0','1','0','0','0','0','1','0','1',
    '1','0','0','0','0','0','0','0','0','1',
    '1','0','0','0','N','0','0','0','0','1',
    '1','0','1','0','0','0','0','1','0','1',
    '1','0','1','0','0','0','0','1','0','1',
    '1','0','0','0','0','0','0','0','0','1',
    '1','1','1','1','1','1','1','1','1','1'};
    m.size.x = 10;
    m.size.y = 10;
    m.map = malloc(sizeof(char *) * m.size.y);
    if (!m.map)
        error_handler("Failed to init map", 1);
    i = 0;
    n = 0;
    while (i < m.size.y)
    {
        m.map[i] = malloc(sizeof(char) * m.size.x);
        if (!m.map[i])
            error_handler("Failed to init map", 1);
        j = 0;
        while (j < m.size.x)
        {
            m.map[i][j] = testmap[n];
            if (m.map[i][j] == 'N' || m.map[i][j] == 'S' || m.map[i][j] == 'E' || m.map[i][j] == 'W')
            {
                if (m.map[i][j] == 'N')
                    d->player.dir =  M_PI / 2;
                if (m.map[i][j] == 'S')
                    d->player.dir = 3 * M_PI / 2;
                if (m.map[i][j] == 'E')   
                    d->player.dir = 0;
                if (m.map[i][j] == 'W')   
                    d->player.dir = M_PI;
                d->player.pos.x = j;
                d->player.pos.y = i;
            }
            j++;
            n++;
        }
        i++;
    }
    return (m);
}

t_minimap  initminimap(t_data *d, double scale)
{
    t_minimap   m;

    m.scale = (d->scsize.y * scale) / d->map.size.y; // 1 is % of screen covered by minimap 1 = 100%
    d->minimapimg.size.x = (d->map.size.x * m.scale);
    d->minimapimg.size.y = (d->map.size.x * m.scale);
    d->minimapimg.img = mlx_new_image(d->win.mlx, d->minimapimg.size.x, d->minimapimg.size.y);
	d->minimapimg.addr = mlx_get_data_addr(d->minimapimg.img, &d->minimapimg.bpp, &d->minimapimg.line_size, &d->minimapimg.endian);
    m.bg = (t_color){0, 0, 255, (char)150};
    m.player = (t_color){255, 0, 0, (char)150};
    m.wall = (t_color){0, 255, 0, (char)150};
    return (m);
}

t_player    initplayer()
{
    t_player    p;

    p.size.x = 0.2;
    p.size.y = 0.2;
    p.height = 0.5;
    return (p);
}

t_data *initdata(void)
{
	t_data	*d;

	d = malloc(sizeof(t_data));
	if (!d)
		error_handler("Failed to init data", 1);
	d->win.mlx = mlx_init();
	d->scsize.x = 1920;
	d->scsize.y = 1080;
    d->img.size.x = d->scsize.x;
    d->img.size.y = d->scsize.y;
	d->win.ptr = mlx_new_window(d->win.mlx, d->img.size.x, d->img.size.y, "Best Game");
	d->img.img = mlx_new_image(d->win.mlx, d->scsize.x, d->scsize.y);
	d->img.addr = mlx_get_data_addr(d->img.img, &d->img.bpp, &d->img.line_size, &d->img.endian);
	d->sky = (t_color){153, 204, 255, 0};
	d->earth = (t_color){153, 153, 255, 0};
	d->fov = 90 * (M_PI / 180);
	d->render_distance = 1000;
    d->player = initplayer();
    d->map = initmap(d);
    d->minimap_scaled = 0;
    d->minimap = initminimap(d, DEFAULMINI);
	return (d);
}
