/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvon-war <lvonwar@gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 12:05:24 by lvon-war          #+#    #+#             */
/*   Updated: 2024/03/12 15:56:48 by lvon-war         ###   ########.fr       */
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

void free_data(t_data *data)
{
	free(data->win.mlx);
	free(data->pixel);
	free(data);
}

t_point	*initpixels(void)
{
	t_point	*pixel;
	int		i;

	i = 0;
	pixel = malloc(sizeof(t_point) * WL * WH);
	if (!pixel)
		error_handler("Failed to init pixel array", 1);
	while (i < (WH * WL))
	{
		pixel[i].x = 0;
		pixel[i].y = i % WL;
		pixel[i].z = 0;
		pixel[i].color = (t_RGB){0, 0, 0};
		i++;
	}
	return (pixel);
}
