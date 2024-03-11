/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_listmanip.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvon-war <lvonwar42@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/12 17:41:56 by lvon-war          #+#    #+#             */
/*   Updated: 2023/05/25 16:46:00 by lvon-war         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_libft.h"

t_list	freelist(t_list li, int mode)
{
	t_list	temp;

	while (li)
	{	
		if (mode)
			free(li->mot);
		temp = li->last;
		free(li);
		li = temp;
	}
	if (mode)
		free(li->mot);
	return (li);
}

t_list	push_front(t_list li, int size, char *nw)
{
	words	*word;

	word = ft_calloc(sizeof(*word), 1);
	if (!word)
	{
		li = freelist(li, 1);
		return (0);
	}
	word->mot = nw;
	word->wsize = size;
	if (li == NULL)
	{
		word->pos = 0;
		word->last = NULL;
	}
	else
	{
		word->last = li;
		word->pos = word->last->pos + 1;
	}
	return (word);
}

t_list	conevertlisttotab(t_list mots, char ***ptr)
{
	char	**str;
	t_list	dup;

	dup = mots;
	if (mots->mot == NULL)
		str = (char **) ft_calloc(sizeof(char *), 1);
	else
		str = (char **) ft_calloc(sizeof(mots->mot), (mots->pos + 2));
	if (!str)
	{
		freelist(mots, 1);
		return (NULL);
	}
	while (mots)
	{
		str[mots->pos] = mots->mot;
		mots = mots->last;
	}
	*ptr = str;
	return (freelist(dup, 0));
}
