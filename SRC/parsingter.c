/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsingter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvon-war <lvon-war@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 07:39:25 by spook             #+#    #+#             */
/*   Updated: 2024/05/14 10:34:51 by lvon-war         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

int	check_path(char *path, char *ext)
{
	char	**split;

	split = ft_split(path, '.');
	if (!split)
		return (1);
	if (!split[1])
		return (1);
	if (ft_strncmp(split[1], ext, 3))
	{
		free(split);
		return (1);
	}
	free(split);
	return (0);
}

int	skip_chara(char *line, int i, char c)
{
	while (line[i] && line[i] == c)
		i++;
	return (i);
}

void	sort_data_line(char **filedata)
{
	char		**tmp;
	t_int_point	p;

	p.x = -1;
	tmp = malloc(sizeof(char *) * HEADERSIZE);
	while (++p.x < HEADERSIZE)
	{
		p.y = skip_chara(filedata[p.x], 0, ' ');
		if (filedata[p.x] && ft_strchr("NSEWFC", filedata[p.x][p.y]))
			tmp[ft_strchr("NSEWFC", filedata[p.x][p.y]) \
			- "NSEWFC"] = filedata[p.x];
		else
			error_handler("Map Error\nInvalid header", 1);
	}
	while (--p.x >= 0)
		filedata[p.x] = tmp[p.x];
	free(tmp);
}
