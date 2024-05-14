/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvon-war <lvon-war@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/08 10:08:08 by spook             #+#    #+#             */
/*   Updated: 2024/05/14 09:58:21 by lvon-war         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

t_minimap	initminimap(t_data *d, double scale)
{
	t_minimap	m;

	m.scale.y = (d->scsize.y * scale) / d->map.size.y;
	m.scale.x = (d->scsize.x * scale) / d->map.size.x;
	d->minimapimg.sizex = (d->map.size.x * m.scale.x);
	d->minimapimg.sizey = (d->map.size.y * m.scale.y);
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

int	get_file_data(int fd, char ***split)
{
	int		n;
	char	*line;
	char	*data;

	n = 0;
	data = NULL;
	while (fd)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		if (line[0] == '\n' || line[0] == '\0')
		{
			free(line);
			continue ;
		}
		data = get_newdata(data, line);
		free(line);
		n++;
	}
	if (!data || !data[0])
		error_handler("Map error\nEmpty map", 1);
	*split = ft_split(data, '\n');
	free(data);
	return (n);
}

t_map	parsing(t_data *d, int arc, char *file)
{
	char	**filedata;
	t_map	map;
	char	**copy;
	int		n;

	if (arc != 2)
		error_handler("Input Error\nInvalid number of arguments", 1);
	if (check_path(file, "cub"))
		error_handler("Input Error\nInvalid file type", 1);
	n = open(file, O_RDONLY);
	if (n < 0)
		error_handler("Error\nCould not open file", 1);
	n = get_file_data(n, &filedata);
	d->player.pos.x = -1;
	map = get_map(d, filedata, n);
	copy = map_copy(map);
	if (floodsearch(map, (t_int_point){(int)d->player.pos.x, \
	(int)d->player.pos.y}, ' ', '1'))
		error_handler("Invalid map\nbackroom access", 1);
	free(map.map);
	map.map = copy;
	get_texture(d, filedata, &map);
	free(filedata);
	return (map);
}

t_data	*initdata(int argc, char *argv)
{
	t_data	*d;

	d = malloc(sizeof(t_data));
	if (!d)
		error_handler("Malloc Error\nFailed to init data", 1);
	d->win.mlx = mlx_init();
	d->scsize = (t_point){1920, 1080};
	d->img.sizex = d->scsize.x;
	d->img.sizey = d->scsize.y;
	d->win.ptr = mlx_new_window(d->win.mlx, d->img.sizex, \
	d->img.sizey, "Best Game");
	d->img.img = mlx_new_image(d->win.mlx, d->scsize.x, d->scsize.y);
	d->img.addr = mlx_get_data_addr(d->img.img, &d->img.bpp, \
	&d->img.line_size, &d->img.endian);
	d->fov = 90;
	d->render_distance = 1000;
	d->player = initplayer();
	d->map = parsing(d, argc, argv);
	d->minimap = initminimap(d, DEFAULMINI);
	d->minimap_scaled = 0;
	return (d);
}
