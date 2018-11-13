/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmigeon <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/05 12:59:14 by pmigeon           #+#    #+#             */
/*   Updated: 2018/11/08 17:58:31 by pmigeon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

void	get_full_line(const int fd, char *line, char **buf)
{
	int	size_read;
	
	while (!ft_strchr((const char *)line, '\n'))
	{
		line = ft_strjoin((const char *)line, (const char *)buf[fd]);
		size_read = read(fd, buf[fd], BUFF_SIZE);
		if (size_read == 0)
			break ;
	}
}

int		get_next_line(const int fd, char **line)
{
	static char *buf[4864];
	int			size_read;

	if (BUFF_SIZE < 1 || !fd || fd < 0)
		return (-1);
	if (!buf[fd])
	{
		if (!(buf[fd] = (char *)malloc(sizeof(char) * (BUFF_SIZE + 1))))
			return (-1);
		ft_bzero(buf[fd], BUFF_SIZE + 1);
	}
	size_read = read(fd, buf[fd], BUFF_SIZE);
	if (size_read <= 0)
		return (size_read == 0 ? 0 : -1);
	if (size_read <= BUFF_SIZE)
	{
		*line = strndup(buf[fd], size_read);
		if (!ft_strchr((const char *)line, '\n'))
			get_full_line(fd, *line, buf);
		return (1);
	}
	return (0);
}

#include <fcntl.h>
#include <stdio.h>
int		main(int argc, char **argv)
{
	char *str;
	int fd;
	int	i;

	i = 1;
	if (argc >= 2)
	{
		while (i < argc)
		{
			fd = open(argv[i], O_RDONLY);
			while (get_next_line(fd, &str) == 1)
			{
				printf("%s", str);
				free(str);
			}
			close(fd);
			i++;
		}
	}
	return (0);
}
