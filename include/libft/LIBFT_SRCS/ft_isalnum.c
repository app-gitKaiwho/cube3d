/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvon-war <lvonwar42@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 16:45:07 by lvon-war          #+#    #+#             */
/*   Updated: 2023/05/25 16:45:07 by lvon-war         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_libft.h"

int	ft_isalnum(int c)
{
	int	is_alnum;

	is_alnum = (ft_isalpha(c) || ft_isdigit(c));
	return (is_alnum);
}
