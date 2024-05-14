/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvon-war <lvon-war@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 11:01:20 by lvon-war          #+#    #+#             */
/*   Updated: 2024/05/14 10:08:04 by lvon-war         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

char	*get_newdata(char *data, char *line)
{
	char	*tmp;

	if (!data)
		data = ft_strdup(line);
	else
	{
		tmp = ft_strdup(data);
		free(data);
		data = ft_strjoin(tmp, "\n");
		free(tmp);
		tmp = ft_strjoin(data, line);
		free(data);
		data = ft_strdup(tmp);
		free(tmp);
	}
	return (data);
}

t_int_point	get_and_check_mapsize(char **filedata, int n)
{
	int	x;
	int	j;
	int	i;

	x = 0;
	j = HEADERSIZE - 1;
	while (++j < n)
	{
		i = 0;
		while (filedata[j][i] != '\n' && filedata[j][i] != '\0')
		{
			if (!((filedata[j][i] >= '0' && filedata[j][i] <= '9') || \
			(filedata[j][i] == 32 || filedata[j][i] == 'N' || \
			filedata[j][i] == 'S' || filedata[j][i] == 'W' || \
			filedata[j][i] == 'E')))
				error_handler("Map Error\nInvalid character in map", 1);
			i++;
		}
		if (x <= i)
			x = i;
	}
	return ((t_int_point){x, j - HEADERSIZE});
}

t_map	get_map(t_data *d, char **filedata, int n)
{
	t_map	map;
	int		j;
	int		i;

	map.size = get_and_check_mapsize(filedata, n);
	map.map = malloc(sizeof(char *) * map.size.y);
	if (!map.map)
		error_handler("Malloc Error\ncould not allocate map", 1);
	j = 0;
	while (j < map.size.y)
	{
		map.map[j] = malloc(sizeof(char) * map.size.x);
		if (!map.map[j])
			error_handler("Malloc Error\ncould not allocate flood map", 1);
		i = -1;
		while (++i < map.size.x)
			get_playerpos(d, &map, filedata, (t_int_point){i, j});
		j++;
	}
	if (d->player.pos.x == -1)
		error_handler("Map Error\nNo player", 1);
	return (map);
}

t_img	get_text_from_file(t_data *d, char *path)
{
	t_img	i;
	char	*str;
	int		n;

	n = skip_chara(path, 0, ' ');
	if (path[n] != 'N' && path[n] != 'S' && path[n] != 'W' && path[n] != 'E' \
	&& path[n + 1] != 'O' && path[n + 1] != 'E' && path[n + 1] != 'A')
		error_handler("Invalid texture\nbad texture format", 1);
	n += 2;
	while (path[n] && path[n] != '.')
	{
		if (path[n] != ' ')
			error_handler("Invalid texture\nbad pre-texture format", 1);
		n++;
	}
	str = ft_substr(path, n + 2, ft_strlen(path) - (n + 2));
	if (check_path(str, "xpm"))
		error_handler("File Error\nWrong extention", 1);
	i.img = mlx_xpm_file_to_image(d->win.mlx, str, &i.sizex, &i.sizey);
	if (!i.img)
		error_handler("mlx_img Error\ncould not make img", 1);
	i.addr = mlx_get_data_addr(i.img, &i.bpp, &i.line_size, &i.endian);
	if (!i.addr)
		error_handler("mlx_img Error\ncould not get addr", 1);
	return (i);
}

void	get_texture(t_data *d, char **filedata, t_map *map)
{
	t_img	img;

	sort_data_line(filedata);
	map->wall[0] = get_text_from_file(d, filedata[0]);
	map->wall[1] = get_text_from_file(d, filedata[1]);
	map->wall[2] = get_text_from_file(d, filedata[2]);
	map->wall[3] = get_text_from_file(d, filedata[3]);
	img.img = mlx_xpm_file_to_image(d->win.mlx, "textures/door.xpm", \
	&img.sizex, &img.sizey);
	if (img.img)
	{
		img.addr = mlx_get_data_addr(img.img, &img.bpp, \
		&img.line_size, &img.endian);
		if (!img.addr)
			error_handler("mlx_img Error\ncould not get addr", 1);
		map->wall[4] = img;
	}
	else
	{
		ft_printf("texture failed\ndefault to wall");
		map->wall[4] = map->wall[3];
	}
	d->sky = get_color(filedata[4]);
	d->earth = get_color(filedata[5]);
}
