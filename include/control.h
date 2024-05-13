/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   control.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spook <spook@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/08 13:49:55 by spook             #+#    #+#             */
/*   Updated: 2024/05/13 21:53:16 by spook            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTROL_H
# define CONTROL_H

//control.c

int	exit_hook(t_data *d);
int	keyhook(int keycode, void *param);

//mouse.c
int	mouse_hook(int button, int x, int y, void *param);
int	mouse_move(int x, int y, void *param);

#endif /* CONTROL_H */