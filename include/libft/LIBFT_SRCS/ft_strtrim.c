/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvon-war <lvonwar42@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 16:50:25 by lvon-war          #+#    #+#             */
/*   Updated: 2023/05/25 16:50:25 by lvon-war         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_libft.h"

size_t	is_unwanted(const char c, const char *set)
{
	size_t	i;
	size_t	it_is;

	it_is = 0;
	i = 0;
	while (set[i])
	{
		if (set[i] == c)
		{
			it_is = 1;
			break ;
		}
		i++;
	}
	return (it_is);
}

int	nboccurence(const char *s1, const char *set, size_t *len)
{
	size_t	occurence;
	int		i;
	int		trigger;

	i = -1;
	trigger = 0;
	occurence = 0;
	while (s1[++i])
	{
		if (!is_unwanted(s1[i], set))
		{
			trigger = 1;
			break ;
		}
		occurence++;
	}
	while (s1[--(*len)])
	{
		if (!is_unwanted(s1[*len], set))
			break ;
		occurence++;
	}
	if (trigger != 1)
		occurence = -1;
	return (occurence);
}

char	*flipfloptrim(const char *s1, char *ptr, const char *set, size_t end)
{
	size_t	i;
	size_t	j;
	int		trigger;

	i = 0;
	j = 0;
	trigger = 0;
	while (s1[i] && i < end + 1)
	{
		if (!is_unwanted(s1[i], set))
			trigger = 1;
		if (trigger == 1)
		{
			ptr[j] = s1[i];
			j++;
		}
		i++;
	}
	ptr[j] = 0;
	return (ptr);
}

char	*ft_strtrim(const char *s1, const char *set)
{
	int		occurence;
	char	*trimed;
	size_t	len;

	if (!*s1)
		return (ft_strdup(""));
	len = ft_strlen(s1);
	occurence = nboccurence(s1, set, &len);
	if (occurence == 0)
		return (ft_strdup(s1));
	else if (occurence < 0)
		return (ft_strdup(""));
	trimed = (char *) malloc(sizeof(char) * (ft_strlen(s1) - occurence + 1));
	if (!trimed)
		return (0);
	return (flipfloptrim(s1, trimed, set, len));
}
