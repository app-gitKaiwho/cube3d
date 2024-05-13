/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angela <angela@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/02 18:58:24 by angela            #+#    #+#             */
/*   Updated: 2024/05/13 10:30:56 by angela           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"
#include <stdbool.h>
#include <stdlib.h>

//recupere la vrai map
//on aura la taille, debut et fin
int	init_mapping(int i, t_map *map)
{
	int		m;
	
    while (map->map[i])
	{
		map->map[i] = skip_space(map->map[i]);
		if (*map->map[i] == '\0')
				i++;
		else
			break;
	}
	map->begin_map = i;
	map->mapping_size = (map->end_map - i) +1;// decallage..
	if (map->mapping_size < 3)
	{
		error_handler("empty map, init mapping\n",1);
		return(ERROR);
	}

	map->mapping =  ft_calloc(map->map_size + 1, sizeof(char *));
	if (!map->mapping)
		return (ERROR);
	m = 0;
	while ((i <= map->end_map) && (map->map[i]))
	{
		map->mapping[m] = ft_strdup(map->map[i]);
		i++;
		m++;
	}
	map->mapping[m] = NULL;
	return (SUCCESS);
	
}

//vérifie qu'on est toujours en train de lire la map
//return error
int	is_struc(char *str)
{
    char	*identifiers[6];
	int		i;
	
	identifiers[0] = "NO";
	identifiers[1] = "SO";
	identifiers[2] = "WE";
	identifiers[3] = "EA";
	identifiers[4] = "F";
	identifiers[5] = "C";
	i = 0;
    str = skip_space(str);
    while (i <= 5) // <= ?
	{
         //ft_printf("je test la str suivante %s\n", str);
		if (ft_strncmp(str, identifiers[i], ft_strlen(identifiers[i])) == 0)
        {
			ft_printf("on a trouvé le caractere %s\n", identifiers[i]);
			return (SUCCESS);
		}
		//  ft_printf("je suis en train de test le caractere %s\n", identifiers[i]);
        i++;

    }
    return (ERROR);
}

// Vérifiez depuis le bas chaque ligne de la carte pour s'assurer qu'elle contient uniquement '1', '0', ' ' ou '\t'
//check et init le player
int	check_character(char *str, t_data *d)
{
    while (*str)
	{
        if (*str == 'N' || *str == 'W' || *str == 'E' || *str == 'S')
		{
			
			if (d->player.player_orientation == '-')
			{
				d->player.player_orientation = *str;
				str++;
			}
			else
			{
				error_handler("too much player\n",1);
				return (ERROR);
			}
		}
		if (!(*str == '1' || *str == '0' || *str == ' ' || *str == '\t'))
        {
			error_handler("on a une map avec d'autres caractere\n",1);
			return (ERROR);
		}
        str++;
    }
	
    return (SUCCESS);
}
//adapter selon besoin de l'execution (initmap)
//set la position du player
void turn_player_direction(t_map *map, t_data *d)
{
	if (map->player_orientation == 'N')
		d->player.dir = M_PI / 2;
	if (map->player_orientation == 'S')
		d->player.dir = 3 * M_PI / 2;
	if (map->player_orientation == 'E')
		d->player.dir = 0;
	if (map->player_orientation == 'W')
		d->player.dir = M_PI;
	d->player.pos.x = map->player_x;
	d->player.pos.y = map->player_y;
	
	// int i = 0;
	// int j = 0;
	// while (map->mapping && map->mapping[j])
	// {
	// 	i= 0;
	// 	while (map->mapping[j][i])
	// 	{
		
			 
	// 		if (map->mapping[j][i] == map->player_orientation)
	// 		{
	// 			d->player.pos.x = j;
	// 			d->player.pos.y = i;
	// 			ft_printf("valeur du player  x%d  et y%d \n", i , j);
	// 			break;
	// 		}
	// 		i++;
	// 	}
	// 	j++;
	// }
	
}

// Parcourt la carte de bas en haut jusqu'à ce qu'un identifiant de configuration soit trouvé
//retourne 
//line_texture, index de la ligne ou la derniere texture a été lu
//verifie le contenu
int	check_carte(t_map *map, int line_texture, t_data *d)
{
    int	i;

	i = map->map_nb_lines -1;
	while (i > line_texture)
	{
		map->map[i] = skip_space(map->map[i]);
		if (*map->map[i] == '\0')
				i--;
		else
			break;
	}
	map->end_map = i;
    while (i > line_texture && map->map[i])
	{
		if (check_character(map->map[i], d) == ERROR)
		{
			error_handler("map with wrong character\n", 1);
            return (ERROR);
        }
		else
			i--;
    }
    if (map->player_orientation == '-')
	{ 
        error_handler("No player found\n", 1);
        return (ERROR);
    }
    return (SUCCESS); //la position du debut de la map
}
