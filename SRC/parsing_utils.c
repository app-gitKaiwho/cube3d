/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angela <angela@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/01 21:23:39 by angnguye          #+#    #+#             */
/*   Updated: 2024/05/13 01:30:02 by angela           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"
/*
Fonctions pour récupérer les infos du fichier.cub
*/

// -launcher- la fonction de compter et remplir le tableau
//recupere le fichier lu en entier
void	init_map_cub(char *argv, t_map *map, int nb_line)
{
	map->map_nb_lines = nb_line;
	map->map = map_harvest(argv, map->map_nb_lines);
}
// compte le no,bre de ligne pour le tableau map, ligne vide comprise
int	map_count_line(char *argv)
{
	int		fd;
	int		count;
	char	*gnl_return;

	count = 0;
	fd = open(argv, O_RDONLY);
	gnl_return = get_next_line(fd);
	while (gnl_return)
	{
		count++;
		free(gnl_return);
		gnl_return = get_next_line(fd);
	}
	if (count == 0)
		error_handler("empty file cub", 1);
	close (fd);
	return (count);
}

// -tableau-récupère la map avec gnl et la met dans un tableau
char	**map_harvest(char *map_sample, int line_map)
{
	int		fd;
	char	**tableau_stock;
	char	*gnl_return;
	int		i;

	i = 0;
	fd = open(map_sample, O_RDONLY);
	tableau_stock =  ft_calloc(line_map + 1, sizeof(char *));
	if (!tableau_stock)
		return (NULL);
	gnl_return = get_next_line(fd);
	while (gnl_return)
	{
		tableau_stock[i] = ft_strdup(gnl_return);
		i++;
		free(gnl_return);
		gnl_return = get_next_line(fd);
	}
	close (fd);
	return (tableau_stock);
}

//skip les espaces
char	*skip_space(char *str)
{
	while (*str == ' ' || *str == '\t' || *str == '\n')// ajout de \n et \t
		str++;
	return (str);
}

//libère le tableau avec option message d'erreur
void	free_split(char **split_str, int error)
{
	int	j;

	j = 0;
	while (split_str[j])
	{
		free(split_str[j]);
		j++;
	}
	free(split_str);
	if (error == 1)
		error_handler("Error: Invalid color format\n", 1);
}
