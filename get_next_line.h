/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpapot <cpapot@student.42lyon.fr >         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 11:48:19 by cpapot            #+#    #+#             */
/*   Updated: 2022/11/20 19:04:54 by cpapot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H

# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdlib.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <unistd.h>
//# include "ld.h"

# ifndef BUF_SIZE

#  define BUF_SIZE 42

# endif

size_t	ft_strlen(const char *str);
void	ft_bzero(void *s, size_t n);
char	*ft_strjoin(char *s1, char const *s2);
int		ft_line_end(char *line);
char	*get_next_line(int fd);

#endif
