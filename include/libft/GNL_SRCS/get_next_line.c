/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvon-war <lvonwar42@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 16:53:07 by lvon-war          #+#    #+#             */
/*   Updated: 2023/05/25 16:53:07 by lvon-war         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include "ft_libft.h"

char	*get_next_line(int fd)
{
	static char	buffer[BUFFER_SIZE + 1];
	static char	*was;
	char		*line;

	if (fd < 0 || read(fd, 0, 0) < 0)
	{
		if (was)
			free(was);
		was = NULL;
		return (NULL);
	}
	line = ft_get_line(fd, was, &buffer[fd]);
	if (!line)
		return (NULL);
	was = make_line(line);
	return (line);
}

char	*make_line(char *line)
{
	char	*was;
	int		i;

	i = 0;
	while (line[i] != '\n' && line[i] != '\0')
		i++;
	if (line[i] == 0)
		return (0);
	was = ft_substr(line, i + 1, ft_strlen(line) - i);
	if (*was == 0)
	{
		free(was);
		was = NULL;
	}
	line[i] = '\0';
	return (was);
}

char	*ft_get_line(int fd, char *was, char *buffer)
{
	int		n;
	char	*tmp;

	n = 1;
	while (n > 0)
	{
		n = read(fd, buffer, BUFFER_SIZE);
		if (n == -1)
		{
			free(was);
			return (0);
		}
		else if (n == 0)
			break ;
		buffer[n] = 0;
		if (!was)
			was = ft_strdup("");
		tmp = was;
		was = ft_strjoin(tmp, buffer);
		free(tmp);
		tmp = NULL;
		if (ft_strchr(buffer, '\n'))
			break ;
	}
	return (was);
}

char	*ft_strchr(const char *str, int c)
{
	char			*ptr;
	int				size;
	unsigned char	cc;

	size = ft_strlen(str);
	cc = c;
	ptr = (char *)str;
	ptr += size;
	while (0 <= size)
	{
		if (*ptr == cc)
			return (ptr);
		ptr--;
		size--;
	}
	if (cc == '\0')
		return (ptr);
	return (0);
}
