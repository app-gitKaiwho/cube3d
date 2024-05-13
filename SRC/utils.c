/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spook <spook@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/15 18:23:20 by lvon-war          #+#    #+#             */
/*   Updated: 2024/05/14 00:24:08 by spook            ###   ########.fr       */
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

t_color	int_to_color(int color)
{
	t_color	c;

	c.alpha = (color & (0xFF << 24)) >> 24;
	c.red = (color & (0xFF << 16)) >> 16;
	c.green = (color & (0xFF << 8)) >> 8;
	c.blue = color & 0xFF;
	return (c);
}

t_color	pixel_plottin(t_img img, int x, int y)
{
	t_color	color;
	int		colorint;

	x = x % img.sizex;
	y = y % img.sizey;
	colorint = *(int *)(img.addr + (y * img.line_size + x * (img.bpp / 8)));
	color = int_to_color(colorint);
	return (color);
}

float	delta(float a, float b)
{
	if (a > b)
		return (a - b);
	return (b - a);
}

float	degtorad(float deg)
{
	return (deg * M_PI / 180);
}
