/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvon-war <lvonwar42@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/04 14:35:27 by lvon-war          #+#    #+#             */
/*   Updated: 2023/05/25 16:46:10 by lvon-war         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_libft.h"

int	findocc(const char *s, int *start, char c)
{
	int	i;

	i = *start;
	while (s[i] == c)
		i++;
	*start = i;
	while (s[i] != c && s[i])
		i++;
	return (i);
}

char	**ft_split(char const *s, char c)
{
	t_list	li;
	int		tab[3];
	char	**ptr;
	char	*str;

	tab[0] = 0;
	tab[1] = 0;
	tab[2] = 0;
	li = NULL;
	while (tab[2] < ft_strlen(s))
	{
		tab[2] = findocc(s, &tab[1], c);
		if (tab[2] == tab[1])
			break ;
		str = ft_substr(s, tab[1], tab[2] - tab[1]);
		if (str == NULL)
			return (NULL);
		li = push_front(li, tab[2] - tab[1], str);
		tab[1] = tab[2];
		tab[0]++;
	}
	if (s == NULL || !*s || !tab[0])
		li = push_front(li, 0, NULL);
	li = conevertlisttotab(li, &ptr);
	return (ptr);
}
