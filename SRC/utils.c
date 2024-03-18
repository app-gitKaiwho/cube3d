/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvon-war <lvonwar@gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/15 18:23:20 by lvon-war          #+#    #+#             */
/*   Updated: 2024/03/18 15:15:54 by lvon-war         ###   ########.fr       */
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

t_RGB	int_to_rgb(int color)
{
	t_RGB	rgb;

	rgb.red = (color & 0xFF0000) >> 16;
	rgb.green = (color & 0xFF00) >> 8;
	rgb.blue = color & 0xFF;
	return (rgb);
}

//free win.mlx and data itself
void	free_data(t_data *data)
{
	free(data->win.mlx);
	free(data);
}

///	@brief check if a point is out of the window. based on vector's direction
int	break_point(t_vector AB, t_point current)
{
	int	is_out;

	is_out = 0;
	if (AB.a.x > AB.b.x && current.x < 0)
		is_out = 1;
	else if (current.x > WL)
		is_out = 1;
	if (AB.a.y > AB.b.y && current.y < 0)
		is_out = 1;
	else if (current.y > WH)
		is_out = 1;
	return (is_out);
}
