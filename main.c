/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpapot <cpapot@student.42lyon.fr >         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 12:35:50 by cpapot            #+#    #+#             */
/*   Updated: 2022/11/16 18:51:53 by cpapot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>
#define BUF_SIZE 1

char	*get_next_line(int fd);

int	main(void)
{
	int				fd;
	int				ret;
	static char		buf[BUF_SIZE + 1];

	fd = open("42", O_RDONLY);
	printf("%d\n", fd);
	ret = read(fd, buf, BUF_SIZE);

	while (ret)
	{
		printf("%s", buf);
		ret = read(fd, buf, BUF_SIZE);
		buf[ret] = '\0';
	}
	printf("%s", buf);
	//printf("\n%s", get_next_line(fd));
}
