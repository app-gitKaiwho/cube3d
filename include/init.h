/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angela <angela@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/08 10:08:33 by spook             #+#    #+#             */
/*   Updated: 2024/05/13 09:34:12 by angela           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INIT_H
# define INIT_H

# include "struct.h"

//init.c 

t_data	*initdata(int argc, char **argv);
t_minimap	initminimap(t_data *d, double scale);

#endif /*!INIT_H */