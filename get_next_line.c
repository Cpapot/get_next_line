/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpapot <cpapot@student.42lyon.fr >         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 11:48:15 by cpapot            #+#    #+#             */
/*   Updated: 2022/11/17 19:10:14 by cpapot           ###   ########.fr       */
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
	{
		i++;
		u++;
	}
	while (str[i] != '\0' && str[i] != '\n')
		i++;
	result = malloc(sizeof(char) * (i + 1));
	while (i != 0)
	{
		result[u] = str[u];
		u++;
		i--;
	}
	result[u] = '\0';
	return (result);
}

char	*ft_getcontent(char *buf, int fd, int lt)
{
	char			*l;
	unsigned int	len;
	int				lc;
	int				bc;

	len = 1;
	bc = 0;
	l = "";
	while (len)
	{
		lc = 0;
		len = read(fd, buf, BUF_SIZE);
		buf[len] = '\0';
		lc = line_finish(buf);
		if (lc != BUF_SIZE && lt < lc + (bc * BUF_SIZE))
		{
			l = ft_strjoin(l, ft_substr(buf, 0, lc + 1));
			return (ft_getl(ft_substr(l, lt, (lc + 1 + bc * BUF_SIZE))));
		}
		else
			l = ft_strjoin(l, buf);
		bc++;
	}
	return (NULL);
}

char	*get_next_line(int fd)
{
	char		buf[BUF_SIZE + 1];
	char		*result;
	static int	last_line_len = 0;

	result = ft_getcontent(buf, fd, last_line_len);
	last_line_len = last_line_len + ft_strlen(result) + 1;
	return (result);
}
/*
#include <stdio.h>
int	main(void)
{
	int i;
	i = 0;
	while (i != 100)
	{
		printf("%s\n",get_next_line(open("42", O_RDONLY)));
		printf("%s\n", "============================");
		i++;
	}
}
*/
