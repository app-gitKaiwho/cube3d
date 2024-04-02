/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keycode.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvon-war <lvonwar@gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/17 11:54:56 by lvon-war          #+#    #+#             */
/*   Updated: 2024/04/02 14:45:39 by lvon-war         ###   ########.fr       */
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
#  define LEFT 0 //A
#  define UP 13 //W
#  define DOWN 1 //S
#  define RIGHT 2 //D
#  define LEAN_LEFT 12//Q
#  define LEAN_RIGHT 14//E
#  define INVENTORY 34 // I
#  define INTERACT 3 // F
#  define JLETTER 40//j
#  define KLETTER 38//k
#  define MAP 46//m
#  define OPTION1 65436 //num pad 1
#  define OPTION2 65433 //num pad 2
#  define OPTION3 65435 //num pad 3
#  define OPTION4 65430 //num pad 4
#  define OPTION5 65437 //num pad 5
#  define OPTION6 65432 //num pad 6
#  define OPTION7 65429 //num pad 7
#  define OPTION8 65431 //num pad 8
#  define OPTION9 65434 //num pad 9
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
#  define LEFT 97//A
#  define UP  119//W
#  define DOWN  115//S
#  define RIGHT 100//D
#  define LEAN_LEFT 113//Q
#  define LEAN_RIGHT 101//E
#  define INVENTORY 105 // I
#  define INTERACT 102 // F
#  define KLETTER 107//k
#  define JLETTER 106//j
#  define MAP 109//m
#  define OPTION1 65436 //num pad 1
#  define OPTION2 65433 //num pad 2
#  define OPTION3 65435 //num pad 3
#  define OPTION4 65430 //num pad 4
#  define OPTION5 65437 //num pad 5
#  define OPTION6 65432 //num pad 6
#  define OPTION7 65429 //num pad 7
#  define OPTION8 65431 //num pad 8
#  define OPTION9 65434 //num pad 9

# endif /*!__APPLE__ */

# define CLOSE_WINDOW_KEY 17 //aka destroy signal

#endif /*!KEYCODE_H */