/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvon-war <lvonwar@gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 14:02:44 by lvon-war          #+#    #+#             */
/*   Updated: 2024/04/02 17:28:13 by lvon-war         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_H
# define STRUCT_H

typedef struct img
{
	int		bpp;
	void	*img;
	char	*addr;
	int		endian;
	int		line_size;
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

typedef struct vector2d
{
	t_point2d	a;
	t_point2d	b;
}	t_vector2d;

//triangular polygon
typedef struct polygon
{
	int			seen;
	t_point		normal;
	t_vector	edges[3];
}	t_polygon;

//for texture : Nord = 0, Sud = 1, Est = 2, West = 3
//pos is the center of the object, all object are cubes
typedef struct object
{
	int			id;
	t_point		pos;
	t_point		rot;
	int			seen;
	t_point		size;
	t_point		verti[8];
	t_polygon	poly[12];
	t_RGB		**textures;
}	t_object;

typedef struct sprite
{
	int			id;
	t_point2d	pos;
	t_point2d	size;
	t_RGB		*texture;
}	t_sprite;

//c for current
typedef struct world
{
	int			sky;
	t_point2d	size;
	t_point		spawn;
	int			earth;
	int			nb_obj;
	t_object	*c_obj;
	t_sprite	*c_sprite;
	int			nb_sprite;
}	t_world;

typedef struct player
{
	t_point		pos;
	t_point		size;
	int			speed;
	t_point		angle;
	t_point		cast[2];
	t_sprite	mapsprite;
}	t_player;

typedef struct minimap
{
	t_point2d	pos;
	t_point2d	size;
	t_RGB		color;
	int			scale;
}	t_minimap;

typedef struct option
{
	int		raytoplayer;
	int		playerview;
	int		minimap;
}	t_option;

typedef struct data
{
	t_window	win;
	t_img		img;
	double		fov;
	int			sky;
	int			earth;
	double		focal;
	double		width;
	double		scale;
	t_world		world;
	t_option	option;
	double		height;
	t_player	player;
	t_minimap	minimap;
	int			render_distance;
}	t_data;

#endif /*!STRUCT_H */