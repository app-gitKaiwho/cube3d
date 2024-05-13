/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvon-war <lvon-war@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 11:01:20 by lvon-war          #+#    #+#             */
/*   Updated: 2024/05/13 14:30:40 by lvon-war         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

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
			free(line);
		if (line[0] == '\n' || line[0] == '\0')
			continue ;
		if (!data)
			data = ft_strdup(line);
		else
			data = ft_strjoinmore(3, data, "\n", line);
		free(line);
		n++;
	}
	*split = ft_split(data, '\n');
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
		i = 0;
		while (i < map.size.x)
		{
			if (ft_strlen(filedata[j + HEADERSIZE]) > i)
			{
				map.map[j][i] = filedata[j + HEADERSIZE][i];
				if (map.map[j][i] == 'N' || map.map[j][i] == 'S' || \
					map.map[j][i] == 'W' || map.map[j][i] == 'E')
				{
					if (d->player.pos.x != -1)
						error_handler("Error\nMultiple player\n", 1);
					if (map.map[j][i] == 'N')
					d->player.dir = 90;
					if (map.map[j][i] == 'S')
						d->player.dir = 270;
					if (map.map[j][i] == 'E')
						d->player.dir = 0;
					if (map.map[j][i] == 'W')
						d->player.dir = 180;
					d->player.pos = (t_point){i, j};
					map.map[j][i] = '0';
				}
			}
			else
				map.map[j][i] = ' ';
			i++;
		}
		j++;
	}
	return (map);
}

t_map	parsing(t_data *d, int arc, char *file)
{
	char	**filedata;
	t_map	map;
	int		n;

	(void)d;
	if (arc != 2)
		error_handler("Error\nInvalid number of arguments\n", 1);
	n = get_file_data(open(file, O_RDONLY), &filedata);
	d->player.pos.x = -1;
	map = get_map(d, filedata, n);
	map.wall[0] = d->map.wall[0];
	map.wall[1] = d->map.wall[1];
	map.wall[2] = d->map.wall[2];
	map.wall[3] = d->map.wall[3];
	map.wall[4] = d->map.wall[4];
	return (map);
}
