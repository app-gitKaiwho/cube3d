/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calc.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvon-war <lvonwar@gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/15 11:14:25 by lvon-war          #+#    #+#             */
/*   Updated: 2024/03/18 14:59:23 by lvon-war         ###   ########.fr       */
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
