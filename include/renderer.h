/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   renderer.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spook <spook@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/11 17:51:04 by spook             #+#    #+#             */
/*   Updated: 2024/05/12 12:42:22 by spook            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RENDERER_H
# define RENDERER_H

# include "struct.h"

//renderer.c

void	castray(t_data *d);
void	displayonminimap(t_data *d, t_point start, t_point end);

#endif /*!renderer */