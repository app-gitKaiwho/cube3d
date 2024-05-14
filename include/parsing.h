/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spook <spook@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/08 11:10:15 by spook             #+#    #+#             */
/*   Updated: 2024/05/14 08:24:08 by spook            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSING_H
# define PARSING_H

# include "struct.h"

//parsing.c 

char		*get_newdata(char *data, char *line);
t_int_point	get_and_check_mapsize(char **filedata, int n);
t_map		get_map(t_data *d, char **filedata, int n);
t_img		get_text_from_file(t_data *d, char *path);
void		get_texture(t_data *d, char **filedata, t_map *map);

//parsingbis.c

int			is_num(char *str);
int			floodsearch(t_map map, t_int_point p, char seek, char wall);
char		**map_copy(t_map map);
void		get_playerpos(t_data *d, t_map *map, \
char **filedata, t_int_point p);
t_color		get_color(char *line);

//parsingter.c

int			check_path(char *path, char *ext);
int			skip_chara(char *line, int i, char c);

#endif /*!PARSING_H */ 