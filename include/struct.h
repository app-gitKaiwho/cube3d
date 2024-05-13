/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angela <angela@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 14:02:44 by lvon-war          #+#    #+#             */
/*   Updated: 2024/05/13 10:37:15 by angela           ###   ########.fr       */
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

typedef struct int_point
{
	int	x;
	int	y;
}	t_int_point;

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

typedef struct player
{
	t_point	pos;
	float	dir;
	t_point size;
	float	height;
	char	player_orientation;
	float	speed;
	
}	t_player;

typedef struct ray
{
	t_point		start;
	t_point		end;
	t_point		dir;
	t_point		len;
	t_int_point	mapcurr;
	float		x;
	float		size;
	int			face;
	char		walltype;
}	t_ray;

typedef struct minimap
{
	float	scale;
	t_color	bg;
	t_color	wall;
	t_color	player;
}	t_minimap;



//parsing


typedef struct point_pars
{
	int	player_j;
	int	player_i;
}				t_point_pars;

typedef struct	map
{
	t_point		size;
	t_img		wall[5];
	
	char		**map;//cointient le fichier cub
	int			map_nb_lines;
	char		player_orientation;
	char		*texture_north; // a deplacer depuis data...
	char		*texture_south;
	char		*texture_west;
	char		*texture_east;
	t_color 	*floor_color;
	t_color 	*ceiling_color;
	char		**mapping;//contient la maaap
	int			end_map;
	int			begin_map;
	int			map_size;
	int			player_x;
	int			player_y;
	int		mapping_size;
	t_point_pars		p;
	

} t_map;

typedef struct data
{
	t_window	win;
	t_img		img;
	t_img		minimapimg;
	t_map		map;
	t_minimap	minimap;
	t_player	player;
	t_color		sky; // ceiling
	t_color		earth;//floor
	double		fov;
	t_point		scsize;
	float		render_distance;
	double		minimap_scaled;
}	t_data;





#endif /*!STRUCT_H */