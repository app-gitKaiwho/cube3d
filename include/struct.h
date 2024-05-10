/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvon-war <lvon-war@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 14:02:44 by lvon-war          #+#    #+#             */
/*   Updated: 2024/05/10 10:07:20 by lvon-war         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_H
# define STRUCT_H

typedef struct color
{
	int		red;
	int		green;
	int		blue;
	int		alpha;
}	t_color;

typedef struct pixel
{
	float	x;
	float	y;
	t_color	color;
}	t_pixel;

typedef struct point
{
	float	x;
	float	y;
}	t_point;

typedef struct vector
{
	t_point	a;
	t_point	b;
}	t_vector;

typedef struct img
{
	int		bpp;
	void	*img;
	char	*addr;
	int		endian;
	int		line_size;
	int		sizex;
	int		sizey;
}	t_img;

typedef struct window
{
	void	*ptr;
	void	*mlx;
	int		test;
}	t_window;

typedef struct map
{
	t_point		size;
	char		**map;
	t_img		wall[4];
}	t_map;

typedef struct player
{
	t_point	pos;
	float	dir;
	t_point size;
	float	height;
}	t_player;

typedef struct minimap
{
	float	scale;
	t_color bg;
	t_color wall;
	t_color player;
}	t_minimap;

typedef struct data
{
	t_window	win;
	t_img		img;
	t_img		minimapimg;
	t_map		map;
	t_minimap	minimap;
	t_player	player;
	t_color		sky;
	t_color		earth;
	double		fov;
	t_point		scsize;
	float		render_distance;
	double		minimap_scaled;
}	t_data;

#endif /*!STRUCT_H */