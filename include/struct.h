/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvon-war <lvonwar@gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 14:02:44 by lvon-war          #+#    #+#             */
/*   Updated: 2024/03/11 21:02:50 by lvon-war         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_H
# define STRUCT_H

typedef struct img
{
	void	*img;
	char	*addr;
	int		bpp;
	int		line_size;
	int		endian;
}t_img;

typedef struct window
{
	void	*ptr;
	void	*mlx;
	int		test;
}t_window;

typedef struct rgb
{
	int	red;
	int	green;
	int	blue;
}t_RGB;

typedef struct point
{
	double	x;
	double	y;
	double	z;
	t_RGB	color;
}t_point;

typedef struct data
{
	t_window	win;
	t_img		img;
	t_point		*pixel;
}t_data;

#endif /*!STRUCT_H */