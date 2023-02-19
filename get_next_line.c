/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aomman <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/07 19:57:56 by aomman            #+#    #+#             */
/*   Updated: 2022/03/08 22:41:43 by aomman           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"so_long.h"

int	ft_strlen(const char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_strdup(char *s1)
{
	int		i;
	char	*s2;

	i = 0;
	while (s1[i])
		i++;
	s2 = malloc((sizeof(char) * i + 1));
	if (!s2)
		return (NULL);
	i = 0;
	while (s1[i] != '\0')
	{
		s2[i] = s1[i];
		i++;
	}
	s2[i] = '\0';
	return (s2);
}

char	*ft_strjoin(char *s, char c)
{
	char	*r;
	int		i;

	if (!s)
		return (NULL);
	i = 0;
	while (s[i])
		i++;
	r = malloc (sizeof(char) * i + 2);
	if (!r)
		return (NULL);
	i = 0;
	while (s[i])
	{
		r[i] = s[i];
		i++;
	}
	r[i] = c;
	r[i + 1] = '\0';
	free (s);
	return (r);
}

char	*get_next_line(int fd)
{
	char		buff;
	char		*line;
	int			i;

	if (fd < 0)
		return (NULL);
	line = ft_strdup("");
	while (read(fd, &buff, 1))
	{
		line = ft_strjoin(line, buff);
		if (buff == '\0')
			break ;
	}
	i = 0;
	while (line[i])
		i++;
	if (i == 0 || read(fd, &buff, 1) == -1)
	{
		free (line);
		return (NULL);
	}
	return (line);
}
