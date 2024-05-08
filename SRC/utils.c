/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spook <spook@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/15 18:23:20 by lvon-war          #+#    #+#             */
/*   Updated: 2024/05/08 17:30:26 by spook            ###   ########.fr       */
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

void	put_bg(t_img img, t_data d)
{
	int	i;
	int	j;

	j = -1;
	while (++j < img.size.y)
	{
		i = -1;
		while (++i < img.size.x)
		{
			if (j < img.size.y / 2)
				put_pixel((t_pixel){i, j, d.earth}, img);
			else
				put_pixel((t_pixel){i, j, d.sky}, img);
		}
	}
}