/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsingter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spook <spook@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 07:39:25 by spook             #+#    #+#             */
/*   Updated: 2024/05/14 08:22:50 by spook            ###   ########.fr       */
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
