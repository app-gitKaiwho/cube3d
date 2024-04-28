/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spook <spook@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/15 18:23:20 by lvon-war          #+#    #+#             */
/*   Updated: 2024/04/28 11:14:58 by spook            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

/// @brief quit the program with an error message.
/// @param txt the message to display.
/// @param code the error code to return.
void	error_handler(char *txt, int code)
{
	ft_printf("%s\n", txt);
	exit(code);
}

/// @brief convert a t_RGB struct to an int (for the mlx format).
/// @param color the t_RGB struct to convert.
/// @return a int representing the color.
int	rgb_to_int(t_RGB color)
{
	return ((color.red << 16) + (color.green << 8) + color.blue);
}

/// @brief convert an int to a t_RGB struct usefull with rand() for example.
/// @param color the int to convert.
/// @return a rgb struct.
t_RGB	int_to_rgb(int color)
{
	t_RGB	rgb;

	rgb.red = (color & 0xFF0000) >> 16;
	rgb.green = (color & 0xFF00) >> 8;
	rgb.blue = color & 0xFF;
	return (rgb);
}

t_RGB	*texture_pattern_create(t_point2d size, t_RGB color)
{
	t_RGB		*texture;
	t_RGB		tmp;
	int			i;
	int			j;
	int			n;

	j = -1;
	n = 0;
	texture = malloc(sizeof(t_RGB) * size.x * size.y);
	if (!texture)
		error_handler("Failed to create texture", 1);
	while (++j < size.y)
	{
		i = -1;
		tmp = color;
		if (j > size.y / 2)
			tmp = int_to_rgb(DARKBLUE);
		while (++i < size.x)
		{
			if (i > size.x / 2)
			{
				tmp = int_to_rgb(DARKRED);
				if (j > size.y / 2)
					tmp = int_to_rgb((DARKBLUE + DARKRED) / 2);
			}
			texture[n] = tmp;
			n++;
		}
	}
	return (texture);
}
