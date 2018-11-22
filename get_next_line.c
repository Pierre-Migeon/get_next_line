/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmigeon <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/12 22:21:19 by pmigeon           #+#    #+#             */
/*   Updated: 2018/11/15 19:21:45 by pmigeon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "./libft/libft.h"
#include "get_next_line.h"
#include <stdio.h>

int    ft_strchri(const char *s, int c)
{
    size_t i;

    i = -1;
    while (++i < ft_strlen(s) + 1)
        if (s[i] == (char)c)
            return (i);
    return (-1);
}

int     ft_strchrc(const char *s, int c)
{
	size_t i;
	size_t i2;

	i = -1;
	i2 = 0;
	while (++i < ft_strlen(s) + 1)
		if (s[i] == (char)c)
			++i2;
	return (i2);
}

int    get_next_line(const int fd, char **line)
{
	int bits_read;
	char *buf[5000];
	char temp[BUFF_SIZE + 1];
	static char *ft_eol = NULL;

	bits_read = 1;
	ft_bzero(temp, ft_strlen(temp));
	if (fd < 0 || BUFF_SIZE < 1 || read(fd, 0, 0) < 0)
		return (-1);
	if (!buf[fd])
		buf[fd] = ft_strnew(BUFF_SIZE + 1);
	if (ft_eol)
		buf[fd] = ft_strjoinfree(buf[fd], ft_eol);
	while (!ft_strchr(buf[fd], '\n') && (bits_read = read(fd, temp, BUFF_SIZE)))
	{
		temp[bits_read] = '\0';
		buf[fd] = ft_strjoinfree(buf[fd], temp);
	}
	ft_eol = (ft_strchrc(buf[fd], '\n') > 0) ? ft_strchr(buf[fd], '\n') + 1: NULL;
	buf[fd][ft_strchri(buf[fd], '\n')] = '\0';
	*line = ft_strdup(buf[fd]);
	ft_bzero(buf[fd], ft_strlen(buf[fd]));
	if (bits_read < 0)
		return (-1);
	if (ft_strchr(temp, '\n'))
		return (1);
	return (ft_strlen(*line) > 0 ? 1 : 0);
}

#include <fcntl.h>
int	main(int argc, char **argv)
{
	int fd;
	char *line;
	int i;
	i = 1;
	line = NULL;
	if (argc >= 2)
	{
        	while (i < argc)
        	{
			fd = open(argv[i], O_RDONLY);
			while (get_next_line(fd, &line) > 0)
			{
				printf("|%s|\n", line);
				ft_memdel((void **)&line);
			}
			close (fd);
			i++;
        	}
	}
	return (0);
}
