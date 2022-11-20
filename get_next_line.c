/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpapot <cpapot@student.42lyon.fr >         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 11:48:15 by cpapot            #+#    #+#             */
/*   Updated: 2022/11/20 19:10:14 by cpapot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_read_line(char *buf, int fd)
{
	int		i;
	int		line_len;
	int		buf_len;
	char	*line;

	i = 0;
	buf_len = 1;
	line_len = -1;
	line = malloc(sizeof(*line) * 1);
	line[0] = '\0';
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

int	ft_malloc_size(char *line)
{
	int	i;

	i = 0;
	if (line[0] == '\n')
		return (1);
	while (line[i] != '\n' && i < (int)ft_strlen(line))
		i++;
	return (i + 1);
}

char	*ft_malloc_line(char *line)
{
	int		i;
	int		u;
	char	*result;

	i = ft_malloc_size(line);
	result = malloc(sizeof(char) * (i + 1));
	if (result == NULL)
		return (free(line), NULL);
	u = 0;
	if (i == 0)
	{
		result[0] = '\0';
		return (free(line), NULL);
	}
	while (i > u)
	{
		result[u] = line[u];
		u++;
	}
	result[u] = '\0';
	free (line);
	return (result);
}

void	ft_setup_next_line(char *buf, char *line)
{
	int		i;
	int		u;

	i = 0;
	u = 0;
	while (line[i] && line[i] != '\n')
		i++;
	if (line[i] != '\0')
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
		return (NULL);
	if (result[0] == '\0')
		return (free(result), NULL);
	ft_setup_next_line(buf, line);
	return (result);
}
