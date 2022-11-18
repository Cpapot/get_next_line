/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpapot <cpapot@student.42lyon.fr >         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 11:48:15 by cpapot            #+#    #+#             */
/*   Updated: 2022/11/18 18:24:08 by cpapot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_getl(char *str)
{
	int		i;
	int		u;
	char	*result;

	i = 0;
	u = 0;
	if (str == NULL)
		return (NULL);
	if (str[0] == '\n')
		str = &str[1];
	while (str[i] != '\0' && str[i] != '\n')
		i++;
	result = malloc(sizeof(char) * (i + 1));
	if (result == NULL)
		return (NULL);
	while (i != 0)
	{
		result[u] = str[u];
		u++;
		i--;
	}
	result[u] = '\0';
	return (result);
}

char	*ft_readfile(char *buf, int fd, int last_len)
{
	unsigned int	len;
	char			*result;
	char			*test;

	len = 1;
	len = read(fd, buf, BUF_SIZE);
	buf[len] = '\0';
	if (len <= 0)
		return (NULL);
	if (line_finish(buf, last_len) != 0)
		return (buf);
	result = "";
	result = ft_strjoin(result, buf);
	while (line_finish(result, last_len) == 0 && len > 0)
	{
		len = read(fd, buf, BUF_SIZE);
		buf[len] = '\0';
		if (len <= 0)
			return (NULL);
		result = ft_strjoin(result, buf);
	}
	test = result;
	free (result);
	return (test);
}

char	*ft_getcontent(char *buf, int fd, int last_len)
{
	char	*result;
	int		i;
	int		line_len;

	i = 0;
	result = ft_readfile(buf, fd, last_len);
	if (result == NULL)
		return (NULL);
	line_len = line_finish(result, last_len);
	result = ft_substr(result, last_len, line_len - last_len);
	return (ft_getl(result));
}

char	*get_next_line(int fd)
{
	char		buf[BUF_SIZE + 1];
	char		*result;
	static int	last_line_len = 0;

	if (fd < 0)
		return (NULL);
	result = ft_getcontent(buf, fd, last_line_len);
	if (result == NULL)
		return (NULL);
	last_line_len = last_line_len + ft_strlen(result) + 1;
	if (ft_strlen(result) == 0)
		last_line_len++;
	return (result);
}


#include <stdio.h>
int	main(void)
{
	int i;
	i = 0;
	while (i != 25)
	{
		printf("%s\n",get_next_line(open("42.txt", O_RDONLY)));
		printf("%s\n", "============================");
		i++;
	}
}
