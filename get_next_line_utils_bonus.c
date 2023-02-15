/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dimolin2 <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 18:21:47 by dimolin2          #+#    #+#             */
/*   Updated: 2022/11/22 18:21:49 by dimolin2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

void	*ft_calloc(int size, size_t type)
{
	void	*new;
	int		i;
	int		dim;

	dim = size * type;
	if (!dim)
		dim = 1;
	new = (void *)malloc(dim);
	if (!new)
		return (0);
	i = 0;
	while (i < dim)
	{
		((unsigned char *)new)[i] = 0;
		i++;
	}
	return (new);
}

char	*ft_strchr(char *s, int c)
{
	int	i;

	i = 0;
	if (!s)
		return (NULL);
	if (c == '\0')
		return ((char *)&s[ft_strlen(s)]);
	while (s[i])
	{
		if (s[i] == (char)c)
			return ((char *)s + i);
		i++;
	}
	return (0);
}

char	*ft_strjoin(char *s1, char *s2)
{
	size_t	i;
	size_t	j;
	char	*new;

	i = -1;
	j = 0;
	if (!s1)
	{
		s1 = (char *)malloc(1 * sizeof(char));
		s1[0] = '\0';
	}
	if (!s1 || !s2)
		return (NULL);
	new = (char *)ft_calloc((ft_strlen(s1) + ft_strlen(s2) + 1), sizeof(char));
	if (s1)
	{
		while (s1[++i] != '\0')
			new[i] = s1[i];
	}
	while (s2[j] != '\0')
		new[i++] = s2[j++];
	new[ft_strlen(s1) + ft_strlen(s2)] = '\0';
	free(s1);
	return (new);
}

int	ft_strlen(char *s)
{
	int	i;

	i = 0;
	if (!s || ! s[i])
		return (0);
	while (s[i])
		i++;
	return (i);
}
