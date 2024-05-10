/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvon-war <lvon-war@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/15 18:23:20 by lvon-war          #+#    #+#             */
/*   Updated: 2024/05/10 09:24:55 by lvon-war         ###   ########.fr       */
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
	while (++j < img.sizey)
	{
		i = -1;
		while (++i < img.sizex)
		{
			if (j < img.sizey / 2)
				put_pixel((t_pixel){i, j, d.earth}, img);
			else
				put_pixel((t_pixel){i, j, d.sky}, img);
		}
	}
}
