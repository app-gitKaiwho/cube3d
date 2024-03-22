/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cube.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvon-war <lvon-war@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 11:49:18 by lvon-war          #+#    #+#             */
/*   Updated: 2024/03/22 11:04:18 by lvon-war         ###   ########.fr       */
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

# define WL 1920
# define WH 1080
# define BLUE 0x0000FF
# define RED 0xFF0000
# define GREEN 0x00FF00

//standard library
# include <unistd.h>
# include <stdlib.h>
# include <math.h>

//libft and mlx library
# include "mlx.h"
# include "ft_libft.h"
# include "ft_printf.h"
# include "get_next_line.h"

//lib from cube3d
# include "keycode.h"
# include "utils.h"
# include "controls.h"
# include "struct.h"
# include "display.h"
# include "calc.h"

//object
# include "object.h"

//sprite
# include "sprite.h"

#endif /*!CUBE_H */