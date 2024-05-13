/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_flood_fill.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angela <angela@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/08 11:52:36 by angela            #+#    #+#             */
/*   Updated: 2024/05/13 00:14:47 by angela           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

//on aimerait checker que si la case actuel est un \0 ou le player... que les cases adjacents n'est ni un \n ni un espace.
// car on veut que ce soit border de 0 ou de 1.

#include <stdio.h>

//a quoi sert les coodoné de plauuyer
int check_direction(t_map *map, t_point_pars p, int direction)
{
    // ft_printf("\n\n check pour la case ");
    if (direction == P_LEFT)
    {
        if ((p.player_i - 1) < 0 )
        {
            return (ERROR);
        }
        if (map->mapping[p.player_j][p.player_i -1] &&  map->mapping[p.player_j][p.player_i -1] == ' ' )
        {
            error_handler("c'est un espace dans le viiiide \n",1);
            return(ERROR);
        }
    }
    if (direction == P_RIGHT)
    {
        // ft_printf("check droite,valeur de droite %d \n", (p.player_i + 1));
        if ((p.player_i +1) >= (ft_strlen(map->mapping[p.player_j])))
        {
            return (ERROR);
        }
        if (map->mapping[p.player_j][p.player_i+1] == ' ' )
        {
            error_handler("c'est un espace dans le viiiide\n",1);
            return(ERROR);
        }
    }
    if (direction == P_UP)
    {
        // ft_printf("check up,valeur de haut%d \n", (p.player_j - 1));
        if (p.player_j  == 0 || (p.player_j - 1) < 0)
         {
            return (ERROR);
        }
          if (map->mapping[p.player_j -1][p.player_i] && map->mapping[p.player_j -1][p.player_i] == ' ' )
        {
            error_handler("c'est un espace dans le viiiide\n",1);
            return(ERROR);
        }
    }
    if (direction == P_DOWN)
    {
        // ft_printf("check down,valeur de bas %d \n", (p.player_j + 1));
        if ((p.player_j + 1) >= map->mapping_size)
         {
            return (ERROR);
        }
          if (map->mapping[p.player_j+1][p.player_i] == ' '  && map->mapping[p.player_j+1][p.player_i] == ' ' )
        {
            error_handler("c'est un espace dans le viiiide\n",1);
            return(ERROR);
        }
    }
    return(SUCCESS);
}

    
    
int check_open_map(t_map *map, t_point_pars pp)
{
    // Vérifie si le point_pars est au bord ou s'il est un espace
    if (check_direction(map, pp, P_LEFT))
        return(ERROR);
    if (check_direction(map, pp, P_RIGHT))
        return(ERROR);
    if (check_direction(map, pp, P_UP))
        return(ERROR);
    if (check_direction(map, pp, P_DOWN))
        return(ERROR);
    return SUCCESS;
}

// Pas de modifications nécessaires dans check_surroundings pour l'instant
//check si la map ojuverte

int path_finding(t_map *map) 
{
    int j;
    int i;

    j = 0;
    i = 0;


    while(map->mapping[j] && j < map->mapping_size)
    {
        i = 0;
        while(map->mapping[j][i])
        {
            // while(map->mapping[j][i] == '1')
            //     i++;
            if (map->mapping[j][i] == '0' || map->mapping[j][i] == map->player_orientation)
            {
                // ft_printf(" je suis sur une case 0 ouverte a %d,%d\n",j,i);
                if (check_open_map(map, (t_point_pars){j, i}) == ERROR)  // Notez la modification ici
                {
                    error_handler("map ouverte\n",1);
                    return(ERROR);
                }
            }
            else if (map->mapping[j][i] == ' ')
            {
                // ft_printf("je suis sur un espace");
            }
            i++;
            
            
        }
        // ft_printf("\nJJJJ on etait sur la ligne %d,avec la ligne %s\n\n ",j, map->mapping[j]);
        j++;
        
    }
    ft_printf(" map fermé\n");
    return(SUCCESS);

}