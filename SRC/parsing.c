/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spook <spook@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 11:01:20 by lvon-war          #+#    #+#             */
/*   Updated: 2024/05/14 06:55:13 by spook            ###   ########.fr       */
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
				error_handler("Error\nInvalid map\n", 1);
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
		error_handler("Error\nMalloc failed\n", 1);
	j = 0;
	while (j < map.size.y)
	{
		map.map[j] = malloc(sizeof(char) * map.size.x);
		if (!map.map[j])
			error_handler("Error\nMalloc failed\n", 1);
		i = -1;
		while (++i < map.size.x)
			get_playerpos(d, &map, filedata, (t_int_point){i, j});
		j++;
	}
	return (map);
}

t_img	get_text_from_file(t_data *d, char *path)
{
	t_img	img;
	char	*str;
	int		i;

	i = 0;
	while (ft_strlen(path) > i && path[i] == ' ')
		i++;
	if (path[i] != 'N' && path[i] != 'S' && path[i] != 'W' && path[i] != 'E' \
	&& path[i + 1] != 'O' && path[i + 1] != 'E' && path[i + 1] != 'A')
		error_handler("Invalid texture\n bad texture format\n", 1);
	while (ft_strlen(path) > i && path[i] != '.')
		i++;
	str = ft_substr(path, i + 2, ft_strlen(path) - (i + 2));
	if (ft_strncmp(ft_split(str, '.')[1], "xpm", 3))
		error_handler("invalide file type...\n", 1);
	img.img = mlx_xpm_file_to_image(d->win.mlx, str, &img.sizex, &img.sizey);
	if (!img.img)
		error_handler("Failed to init texture\ncould not make img", 1);
	img.addr = mlx_get_data_addr(img.img, &img.bpp, \
	&img.line_size, &img.endian);
	if (!img.addr)
		error_handler("Failed to init texture\ncould not get addr", 1);
	return (img);
}

void	get_texture(t_data *d, char **filedata, t_map *map)
{
	t_img	img;

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
			error_handler("Failed to init texture\ncould not get addr", 1);
		map->wall[4] = img;
	}
	else
	{
		ft_printf("Failed to init door\ndefault to wall");
		map->wall[4] = map->wall[3];
	}
	d->sky = get_color(filedata[4]);
	d->earth = get_color(filedata[5]);
}
