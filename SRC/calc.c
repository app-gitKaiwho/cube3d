/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calc.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvon-war <lvon-war@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/15 11:14:25 by lvon-war          #+#    #+#             */
/*   Updated: 2024/03/15 14:29:37 by lvon-war         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

//unused function
double	calculate_slope(t_vector AB)
{
	double	dy;
	double	dx;
	double	slope;

	dy = AB.b.y - AB.a.y;
	dx = AB.b.x - AB.a.x;
	slope = dy / dx;
	return (slope);
}
