/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpapot <cpapot@student.42lyon.fr >         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 11:48:11 by cpapot            #+#    #+#             */
/*   Updated: 2022/11/20 17:06:17 by cpapot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

void	ft_bzero(void *s, size_t n)
{
	int	i;

	i = 0;
	while (i != (int)n)
	{
		((unsigned char *)s)[i] = 0;
		i++;
	}
}

char	*ft_strjoin(char *s1, char const *s2)
{
	char	*strs;
	int		i;
	int		u;

	i = 0;
	u = 0;
	strs = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (strs == 0)
		return (0);
	while (s1[i] != '\0')
	{
		strs[i] = s1[i];
		i++;
	}
	while (s2[u] != '\0')
	{
		strs[i + u] = s2[u];
		u++;
	}
	strs[i + u] = '\0';
	free(s1);
	return (strs);
}

int	ft_line_end(char *line)
{
	int	i;

	i = 0;
	while (line[i] != '\0')
	{
		if (line[i] == '\n')
			return (i);
		i++;
	}
	return (-1);
}
