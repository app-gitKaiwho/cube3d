/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvon-war <lvonwar@gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 14:02:44 by lvon-war          #+#    #+#             */
/*   Updated: 2024/03/18 15:10:58 by lvon-war         ###   ########.fr       */
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
}	t_img;

typedef struct window
{
	void	*ptr;
	void	*mlx;
	int		test;
}	t_window;

typedef struct rgb
{
	int	red;
	int	green;
	int	blue;
}	t_RGB;

//in order x, y, z, color
typedef struct pixel
{
	double	x;
	double	y;
	double	z;
	t_RGB	color;
}	t_pixel;	

typedef struct point
{
	double	x;
	double	y;
	double	z;
}	t_point;

typedef struct point2d
{
	double	x;
	double	y;
}	t_point2d;

//a = start, b = end
typedef struct vector
{
	t_point	a;
	t_point	b;
}	t_vector;

typedef struct data
{
	t_window	win;
	t_img		img;
	int			focal;
	int			fov;
	int			render_distance;
	char		*bg;
}	t_data;

typedef struct object
{
	t_point		pos;
	t_point2d	size;
	t_RGB		*texture;
}	t_object;

typedef struct sprite
{
	t_point2d	pos;
	t_point2d	size;
	t_RGB		*texture;
}	t_sprite;

#endif /*!STRUCT_H */