/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpapot <cpapot@student.42lyon.fr >         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 11:48:15 by cpapot            #+#    #+#             */
/*   Updated: 2022/11/19 17:45:16 by cpapot           ###   ########.fr       */
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
	if (s1[0] != '\0')
		free (s1);
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

char	*ft_read_line(char *buf, int fd)
{
	int		i;
	int		line_len;
	int		buf_len;
	char	*line;

	i = 0;
	buf_len = 1;
	line_len = -1;
	line = "";
	if (buf)
		line = ft_strjoin(line, buf);
	while (ft_line_end(line) == -1 && buf_len > 0)
	{
		ft_bzero(buf, BUF_SIZE + 1);
		buf_len = read(fd, buf, BUF_SIZE);
		if (buf_len == -1)
			return (free(line), NULL);
		buf[buf_len] = '\0';
		line = ft_strjoin(line, buf);
	}
	return (line);
}

char	*ft_malloc_line(char *line)
{
	int		i;
	int		u;
	char	*result;

	i = 0;
	u = ft_strlen(line);
	while (line[i] != '\n' && i != u)
		i++;
	result = malloc(sizeof(char) * (i + 1));
	if (result == NULL)
		return (NULL);
	u = 0;
	while (i >= u)
	{
		result[u] = line[u];
		u++;
	}
	result[u] = '\0';
	free (line);
	return (result);
}

void	ft_setup_next_line(char *buf, char* line)
{
	int		i;
	int		u;

	i = 0;
	u = 0;
	while (buf[i] && buf[i] != '\n')
		i++;
	i++;
	while (line[i + u] != '\0')
	{
		buf[u] = line [i + u];
		u++;
	}
	buf[u] = '\0';
}

char	*get_next_line(int fd)
{
	static char	buf[BUF_SIZE + 1];
	char		*line;
	char		*result;

	if (fd < 0)
		return (NULL);
	line = ft_read_line(buf, fd);
	if (line == NULL)
		return (NULL);
	result = ft_malloc_line(line);
	if (result == NULL)
		return (free(line), NULL);
	ft_setup_next_line(buf, line);
	return(result);
}

#include <stdio.h>
int	main(void)
{
	int i;
	i = 0;
	while (i != 50)
	{
		printf("%s",get_next_line(open("42.txt", O_RDONLY)));
		printf("%s\n", "============================");
		i++;
	}
}
