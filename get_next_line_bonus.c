/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dimolin2 <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 18:21:30 by dimolin2          #+#    #+#             */
/*   Updated: 2022/11/22 18:21:31 by dimolin2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*ft_clean_stash(char *stash)
{
	char	*str;
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (stash[i] && stash[i] != '\n')
		i++;
	if (!stash[i])
	{
		free(stash);
		return (NULL);
	}
	str = (char *)ft_calloc(ft_strlen(stash) - i, sizeof(char));
	i++;
	while (stash[i] != '\0')
		str[j++] = stash[i++];
	str[j] = '\0';
	free(stash);
	stash = NULL;
	return (str);
}

char	*ft_read_and_stash(int fd, char *stash)
{
	int		x;
	char	*str;

	//aggiungere if BUFFER_SIZE < 0
	str = (char *)ft_calloc((BUFFER_SIZE + 1), sizeof(char));
	x = 1;
	while (x && !ft_strchr(stash, '\n'))
	{
		x = read(fd, str, 1);
		if (x < 0)
		{
			free(str);
			return (NULL);
		}
		str[x] = '\0';
		stash = ft_strjoin(stash, str);
	}
	free(str);
	return (stash);
}

char	*ft_fill_line(char *stash)
{
	char	*str;
	int		i;

	i = 0;
	while (stash[i] && stash[i] != '\n')
		i++;
	str = (char *)ft_calloc(i + 2, sizeof(char));
	if (!str)
		return (0);
	i = 0;
	while (stash[i] && stash[i] != '\n')
	{
		str[i] = stash[i];
		i++;
	}
	if (stash[i] == '\n')
	{
		str[i] = stash[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

char	*get_next_line(int fd)
{
	char		*line;
	static char	*stash;

	stash = ft_read_and_stash(fd, stash);
	if (!stash || !stash[0])
	{
		free(stash);
		stash = NULL;
		return (NULL);
	}
	line = ft_fill_line(stash);
	stash = ft_clean_stash(stash);
	if (!stash || !stash[0])
	{
		free(stash);
		stash = NULL;
	}
	return (line);
}
