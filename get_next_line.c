/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpapot <cpapot@student.42lyon.fr >         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 11:48:15 by cpapot            #+#    #+#             */
/*   Updated: 2022/11/16 18:51:52 by cpapot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>
#include "get_next_line.h"
#define BUF_SIZE 56

// int		line_finish(char *buf);
// char	*ft_strjoin(char const *s1, char const *s2);
// size_t	ft_strlen(const char *str);

int	line_finish(char *buf)
{
	int	i;

	i = 0;
	while (buf[i] != '\0')
	{
		if (buf[i] == '\n')
			return (i);
		i++;
	}
	return (i);
}

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

char	*ft_strjoin(char const *s1, char const *s2)
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
	return (strs);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*result;
	size_t	i;
	size_t	malloc_size;

	i = 0;
	if (len == 0 || start > ft_strlen(s))
	{
		result = malloc(sizeof(char));
		result[0] = '\0';
		return (result);
	}
	if (start + len > ft_strlen(s))
		malloc_size = ft_strlen(s) - start;
	else
		malloc_size = (len);
	result = malloc(sizeof(char) * malloc_size + 1);
	if (result == 0)
		return (0);
	while (i != malloc_size)
	{
		result[i] = s[i + start];
		i++;
	}
	result[i] = '\0';
	return (result);
}


char	*ft_getline(char *buf, int fd)
{
	char			*line;
	unsigned int	len;
	int				line_len;

	len = 1;
	line = "";
	while (len)
	{
		line_len = 0;
		len = read(fd, buf, BUF_SIZE);
		buf[len] = '\0';
		line_len = line_finish(buf);
		if (line_len != BUF_SIZE)
		{
			line = ft_strjoin(line, ft_substr(buf, 0, line_len));
			buf = &buf[line_len];
			return (ft_substr(line, 0, line_len));
		}
		else
		{
			line = ft_strjoin(line, buf);
		}
	}
	return (NULL);
}

char	*get_next_line(int fd)
{
	static char		buf[BUF_SIZE + 1];

	printf("%s", ft_getline(buf, fd));
	return (NULL);
}

int	main(void)
{
	get_next_line(open("42", O_RDONLY));
}
