/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_floor_ceiling.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angela <angela@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/01 21:39:05 by angnguye          #+#    #+#             */
/*   Updated: 2024/05/13 09:10:47 by angela           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

static char *ft_strncpy(char *dest, const char *src, size_t n) {
    size_t i = 0;
    while (i < n && src[i] != '\0') {
        dest[i] = src[i];
        i++;
    }
    // Remplissage avec des zéros si la longueur de src est inférieure à n
    while (i < n) {
        dest[i] = '\0';
        i++;
    }
    return dest;
}



static int is_space(char c) {
    return (c == ' ' || c == '\t' || c == '\n') ? 1 : 0;
}
static char **clear_space(char **split_str) {
    int i, j = 0, begin, end;
    char **result = malloc(sizeof(char *) * 3);  // Allocating memory for 3 pointers.

    if (!result)
        return NULL;  // Always check malloc return.

    while (j < 3 && split_str[j] != NULL) {
        i = 0;
        // Skip leading spaces
        while (is_space(split_str[j][i]))
            i++;
        begin = i;
        // Find the end index
        while (split_str[j][i] && !is_space(split_str[j][i]))
            i++;
        end = i;

        // Allocate memory for the new string
        result[j] = malloc(sizeof(char) * (end - begin + 1));
        if (result[j] == NULL) {
            // Properly handle memory allocation failure
            while (--j >= 0) free(result[j]);
            free(result);
            return NULL;
        }

        // Copy the substring
        ft_strncpy(result[j], split_str[j] + begin, end - begin);
        result[j][end - begin] = '\0';  // Null-terminate the string

        j++;
    }

    return result;
}

//-launcher-recupere du tableau les lignes F ou C
// converti en char*->int* avec les check.
int	*set_color(char *str)
{
	char	**split_str;
	int		*rgb;
	int		i;

	i = 0;
	split_str = NULL;
	rgb = (int *)malloc(sizeof(int) * 3);
	if (rgb == NULL)
	{
		free_split(split_str, 1);
		return (NULL);
	}
	str++;
	str = skip_space(str);
	split_str = ft_split(str, ',');
	while (split_str[i] != NULL)
		i++;
	if (i != 3)
	{
		free_split(split_str, 1);
		return (NULL);
	}
	char **cleared; 
	cleared = clear_space(split_str);
	check_components(split_str, rgb);
	free_split(split_str, 0);
	free(cleared);
	return (rgb);
}

//-check- if char = nombre et le converti en int
int	check_str_digit(char **split_str, int *rgb, int i)
{
	char	*current;

	current = split_str[i];
	while (*current)
	{
		if (!ft_isdigit(*current))
		{
			free(rgb);
			free_split(split_str, 1);
			return (ERROR);
		}
		current++;
	}
	return (SUCCESS);
}

//-check- pour Floor et ceiling si c'est bien des RGB numeriques
int	*check_components(char **split_str, int *rgb)
{
	int		i;

	i = 0;
	while (split_str[i] != NULL && i <= 3)
	{
		if (check_str_digit(split_str, rgb, i) == ERROR)
			return (NULL);
		rgb[i] = ft_atoi(split_str[i]);
		if (rgb[i] < 0 || rgb[i] > 255)
		{
			free(rgb);
			free_split(split_str, 1);
			return (NULL);
		}
		i++;
	}
	return (rgb);
}

//-init-Fini de set les informations dans la structure
void	init_floor_ceiling(int *rgb, t_map *map, char letter)
{
	// ft_printf("\nplop\n");
	
	if (letter == 'C')
	{
		map->ceiling_color->red = rgb[0];
		map->ceiling_color->green = rgb[1];
		map->ceiling_color->blue = rgb[2];
	}
	else if (letter == 'F')
	{
		map->floor_color->red = rgb[0];
		map->floor_color->green = rgb[1];
		map->floor_color->blue = rgb[2];
	}
}
