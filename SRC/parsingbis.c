/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsingbis.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spook <spook@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 06:53:06 by spook             #+#    #+#             */
/*   Updated: 2024/05/14 07:02:36 by spook            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

int	is_num(char *str)
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

char	**map_copy(t_map map)
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

t_color	get_color(char *line)
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
