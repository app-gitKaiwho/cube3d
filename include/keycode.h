/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Keycode.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvon-war <lvon-war@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/17 11:54:56 by lvon-war          #+#    #+#             */
/*   Updated: 2024/03/11 11:49:31 by lvon-war         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef KEYCODE_H
# define KEYCODE_H

# ifdef __APPLE__
//compiled on macOS
#  define ESC 53 // Escape key on MacOs
#  define MINUS 78
#  define PLUS 69
#  define L_CLICK 1
#  define R_CLICK 2
#  define ON_PRESS 4
#  define SCROLL_UP 4
#  define SCROLL_DOWN 5
#  define ON_RELEASE 5
#  define ARROW_LEFT 123
#  define ARROW_UP 126
#  define ARROW_RIGHT 124 
#  define ARROW_DOWN 125
#  define RESET 15 //r
#  define ROT_LEFT 0 //A
#  define ROT_UP 13 //W
#  define ROT_DOWN 1 //S
#  define ROT_RIGHT 2 //D
#  define BARREL_ROLL_LEFT 12//Q
#  define BARREL_ROLL_RIGHT 14//E
#  define ISO_VIEW 34 // I
#  define FRONT_VIEW 3 // F
#  define LOWER_H 40//j
#  define UPPY_H 38//k
# else
//compiled if not on macOS
#  define ESC 65307 // Escape key on Linux
#  define MINUS 65453
#  define PLUS 65451
#  define L_CLICK 1
#  define R_CLICK 2
#  define ON_PRESS 4
#  define SCROLL_UP 4
#  define SCROLL_DOWN 5
#  define ON_RELEASE 5
#  define ARROW_LEFT 65361
#  define ARROW_UP 65362
#  define ARROW_RIGHT 65363 
#  define ARROW_DOWN 65364
#  define RESET 114 //r
#  define ROT_LEFT 97//A
#  define ROT_UP  119//W
#  define ROT_DOWN  115//S
#  define ROT_RIGHT 100//D
#  define BARREL_ROLL_LEFT 113//Q
#  define BARREL_ROLL_RIGHT 101//E
#  define ISO_VIEW 105 // I
#  define FRONT_VIEW 102 // F
#  define LOWER_H 107//k
#  define UPPY_H 106//j
# endif /*!__APPLE__ */

# define CLOSE_WINDOW_KEY 17 //aka destroy signal
#endif /*!KEYCODE_H */