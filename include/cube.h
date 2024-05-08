/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cube.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spook <spook@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 11:49:18 by lvon-war          #+#    #+#             */
/*   Updated: 2024/05/08 17:39:48 by spook            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FdF.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvon-war <lvonwar42@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/17 11:54:56 by lvon-war          #+#    #+#             */
/*   Updated: 2023/05/25 16:52:02 by lvon-war         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUBE_H
# define CUBE_H

# define M_PI 3.14159265358979323846
# define BLUE 0x0000FF
# define DARKBLUE 0x000080
# define DARKRED 0x8B0000
# define YELLOW 0xFFFF00
# define RED 0xFF0000
# define GREEN 0x00FF00
# define DEFAULMINI 0.2

//standard library
# include <unistd.h>
# include <stdlib.h>
# include <math.h>
# include <X11/X.h>

//libft and mlx library
# include "mlx.h"
# include "ft_libft.h"
# include "ft_printf.h"
# include "get_next_line.h"

//lib from cube3d
# include "keycode.h"
# include "struct.h"
# include "init.h"
# include "display.h"
# include "minimap.h"
# include "control.h"
# include "raycast.h"
# include "player.h"

//utils
# include "utils.h"
#endif /*!CUBE_H */