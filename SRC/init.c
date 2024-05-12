/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spook <spook@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/08 10:08:08 by spook             #+#    #+#             */
/*   Updated: 2024/05/12 14:21:36 by spook            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

void	inittexture(t_data *d, char *path, char *path1, char *path2, char *path3, char *path4)
{
	d->map.wall[0].img = mlx_xpm_file_to_image(d->win.mlx, path, \
	&d->map.wall[0].sizex, &d->map.wall[0].sizey);
	d->map.wall[1].img = mlx_xpm_file_to_image(d->win.mlx, path1, \
	&d->map.wall[1].sizex, &d->map.wall[1].sizey);
	d->map.wall[2].img = mlx_xpm_file_to_image(d->win.mlx, path2, \
	&d->map.wall[2].sizex, &d->map.wall[2].sizey);
	d->map.wall[3].img = mlx_xpm_file_to_image(d->win.mlx, path3, \
	&d->map.wall[3].sizex, &d->map.wall[3].sizey);
	d->map.wall[4].img = mlx_xpm_file_to_image(d->win.mlx, path4, \
	&d->map.wall[4].sizex, &d->map.wall[4].sizey);
	if (!d->map.wall[0].img || !d->map.wall[1].img || !d->map.wall[2].img \
	|| !d->map.wall[3].img || !d->map.wall[4].img)
		error_handler("Failed to init texture", 1);
	d->map.wall[0].addr = mlx_get_data_addr(d->map.wall[0].img, \
	&d->map.wall[0].bpp, &d->map.wall[0].line_size, &d->map.wall[0].endian);
	d->map.wall[1].addr = mlx_get_data_addr(d->map.wall[1].img, \
	&d->map.wall[1].bpp, &d->map.wall[1].line_size, &d->map.wall[1].endian);
	d->map.wall[2].addr = mlx_get_data_addr(d->map.wall[2].img, \
	&d->map.wall[2].bpp, &d->map.wall[2].line_size, &d->map.wall[2].endian);
	d->map.wall[3].addr = mlx_get_data_addr(d->map.wall[3].img, \
	&d->map.wall[3].bpp, &d->map.wall[3].line_size, &d->map.wall[3].endian);
	d->map.wall[4].addr = mlx_get_data_addr(d->map.wall[4].img, \
	&d->map.wall[4].bpp, &d->map.wall[4].line_size, &d->map.wall[4].endian);
	if (!d->map.wall[0].addr || !d->map.wall[1].addr || !d->map.wall[2].addr \
	|| !d->map.wall[3].addr || !d->map.wall[4].addr)
		error_handler("Failed to init texture", 1);
}

t_map   initmap(t_data *d)
{
	t_map	m;
	int		i;
	int		j;
	int		n;
	char	testmap[] = {
	'1','1','1','1','1','1','1','1','1','1',
	'1','0','0','0','0','0','0','0','0','1',
	'1','0','1','1','2','1','1','0','0','1',
	'1','0','1','0','0','0','0','1','0','1',
	'1','0','0','0','0','0','0','0','0','1',
	'1','0','0','0','N','0','1','0','0','1',
	'1','0','1','0','0','0','0','1','0','1',
	'1','0','1','1','1','1','0','1','0','1',
	'1','0','0','1', 0,'1','0','0','0','1',
	'1','1','1','1', 0,'1','1','1','1','1'};

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
			if (m.map[i][j] == 'N' || m.map[i][j] == 'S' \
			|| m.map[i][j] == 'E' || m.map[i][j] == 'W')
			{
				if (m.map[i][j] == 'N')
					d->player.dir = 90;
				if (m.map[i][j] == 'S')
					d->player.dir = 270;
				if (m.map[i][j] == 'E')
					d->player.dir = 0;
				if (m.map[i][j] == 'W')
					d->player.dir = 180;
				d->player.pos.x = j;
				d->player.pos.y = i;
				m.map[i][j] = '0';
			}
			j++;
			n++;
		}
		i++;
	}
	return (m);
}

t_minimap	initminimap(t_data *d, double scale)
{
	t_minimap	m;

	m.scale = (d->scsize.y * scale) / d->map.size.y;
	d->minimapimg.sizex = (d->map.size.x * m.scale);
	d->minimapimg.sizey = (d->map.size.x * m.scale);
	d->minimapimg.img = mlx_new_image(d->win.mlx, \
	d->minimapimg.sizex, d->minimapimg.sizey);
	d->minimapimg.addr = mlx_get_data_addr(d->minimapimg.img, \
	&d->minimapimg.bpp, &d->minimapimg.line_size, &d->minimapimg.endian);
	m.bg = (t_color){0, 0, 255, (char)90};
	m.player = (t_color){255, 0, 0, (char)90};
	m.wall = (t_color){0, 255, 0, (char)90};
	return (m);
}

t_player	initplayer(void)
{
	t_player	p;

	p.size.x = 0.2;
	p.size.y = 0.2;
	p.height = 0.5;
	p.speed = 0.5;
	return (p);
}

t_data	*initdata(void)
{
	t_data	*d;

	d = malloc(sizeof(t_data));
	if (!d)
		error_handler("Failed to init data", 1);
	d->win.mlx = mlx_init();
	d->scsize = (t_point){1920, 1080};
	d->img.sizex = d->scsize.x;
	d->img.sizey = d->scsize.y;
	d->win.ptr = mlx_new_window(d->win.mlx, d->img.sizex, \
	d->img.sizey, "Best Game");
	d->img.img = mlx_new_image(d->win.mlx, d->scsize.x, d->scsize.y);
	d->img.addr = mlx_get_data_addr(d->img.img, &d->img.bpp, \
	&d->img.line_size, &d->img.endian);
	d->sky = (t_color){153, 204, 255, 0};
	d->earth = (t_color){153, 153, 255, 0};
	d->fov = 90;
	d->render_distance = 1000;
	d->player = initplayer();
	d->map = initmap(d);
	d->minimap = initminimap(d, DEFAULMINI);
	d->minimap_scaled = 0;
	inittexture(d, "textures/north.xpm", "textures/south.xpm", \
	"textures/east.xpm", "textures/west.xpm", "textures/door.xpm");
	return (d);
}
