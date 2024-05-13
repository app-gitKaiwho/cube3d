/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spook <spook@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 11:01:20 by lvon-war          #+#    #+#             */
/*   Updated: 2024/05/14 00:43:28 by spook            ###   ########.fr       */
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
			line = NULL;
			continue ;
		}
		data = get_newdata(data, line);
		free(line);
		n++;
	}
	*split = ft_split(data, '\n');
	free(data);
	return (n);
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

void	get_playerpos(t_data *d, t_map *map, char **filedata, t_int_point p)
{
	if (ft_strlen(filedata[p.y + HEADERSIZE]) > p.x)
	{
		map->map[p.y][p.x] = filedata[p.y + HEADERSIZE][p.x];
		if (map->map[p.y][p.x] == 'N' || map->map[p.y][p.x] == 'S' ||
			map->map[p.y][p.x] == 'W' || map->map[p.y][p.x] == 'E')
		{
			if (d->player.pos.x != -1)
				error_handler("Error\nMultiple player\n", 1);
			if (map->map[p.y][p.x] == 'N')
				d->player.dir = 90;
			if (map->map[p.y][p.x] == 'S')
				d->player.dir = 270;
			if (map->map[p.y][p.x] == 'E')
				d->player.dir = 0;
			if (map->map[p.y][p.x] == 'W')
				d->player.dir = 180;
			d->player.pos = (t_point){p.x, p.y};
			map->map[p.y][p.x] = '0';
		}
	}
	else
		map->map[p.y][p.x] = ' ';
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

int is_num(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
			return (0);
		i++;
	}
	return (1);
}

t_color get_color(char *line)
{
	t_color	color;
	char	**fst_split;
	char	**split;

	fst_split = ft_split(line, ' ');
	if (!fst_split || (fst_split[0][0] != 'F' && fst_split[0][0] != 'C'))
		error_handler("Error\nbad Floor/Celing format", 1);
	split = ft_split(fst_split[1], ',');
	free(fst_split);
	if (!split || !is_num(split[0]) || !is_num(split[1]) || !is_num(split[2]))
		error_handler("Error\nbad color value", 1);
	color.red = ft_atoi(split[0]);
	color.green = ft_atoi(split[1]);
	color.blue = ft_atoi(split[2]);
	color.alpha = 0;
	free(split);
	return (color);
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

int	floodsearch(t_map map, t_int_point p, char seek, char wall)
{
	if (p.x < 0 || p.x >= map.size.x || p.y < 0 || p.y >= map.size.y)
		return (0);
	if (map.map[p.y][p.x] == wall)
		return (0);
	if (map.map[p.y][p.x] == 'F')
		return (0);
	if (map.map[p.y][p.x] == seek)
		return (1);
	map.map[p.y][p.x] = 'F';
	if (floodsearch(map, (t_int_point){p.x + 1, p.y}, seek, wall) ||
		floodsearch(map, (t_int_point){p.x - 1, p.y}, seek, wall) ||
		floodsearch(map, (t_int_point){p.x, p.y + 1}, seek, wall) ||
		floodsearch(map, (t_int_point){p.x, p.y - 1}, seek, wall))
		return (1);
	return (0);
}

char **map_copy(t_map map)
{
	char	**copy;
	int		i;

	copy = malloc(sizeof(char *) * map.size.y);
	if (!copy)
		error_handler("Error\nMalloc failed\n", 1);
	i = 0;
	while (i < map.size.y)
	{
		copy[i] = ft_strdup(map.map[i]);
		if (!copy[i])
			error_handler("Error\nMalloc failed\n", 1);
		i++;
	}
	return (copy);
}

t_map	parsing(t_data *d, int arc, char *file)
{
	char	**filedata;
	t_map	map;
	char	**copy;
	int		n;

	if (arc != 2)
		error_handler("Error\nInvalid number of arguments\n", 1);
	n = get_file_data(open(file, O_RDONLY), &filedata);
	d->player.pos.x = -1;
	map = get_map(d, filedata, n);
	copy = map_copy(map);
	if (floodsearch(map, (t_int_point){(int)d->player.pos.x, \
	(int)d->player.pos.y}, ' ', '1'))
		error_handler("Invalid map\n backroom access", 1);
	free(map.map);
	map.map = copy;
	get_texture(d, filedata, &map);
	free(filedata);
	return (map);
}
