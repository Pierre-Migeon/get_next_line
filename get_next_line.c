/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmigeon <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/30 12:38:59 by pmigeon           #+#    #+#             */
/*   Updated: 2018/12/04 20:39:34 by pmigeon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

char	*ft_strjoinfree(char *s1, char *s2)
{
	char	*merge;
	size_t	len;

	if (s1 == NULL || s2 == NULL)
		return (NULL);
	len = 1;
	len += ft_strlen(s1);
	len += ft_strlen(s2);
	if (!(merge = (char *)malloc(sizeof(char) * len)))
		return (NULL);
	ft_strcpy(merge, s1);
	ft_strcat(merge, s2);
	//free((void *)s1);
	return (merge);
}

int		ft_strchri(const char *s, int c)
{
	size_t i;

	i = -1;
	while (++i < ft_strlen(s) + 1)
		if (s[i] == (char)c)
			return (i);
	return (-1);
}

int		strc(const char *s, int c)
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

int		ft_spool(char **buf, int fd, char *temp)
{
	int bits_read;

	while ((bits_read = read(fd, temp, BUFF_SIZE)) > 0)
	{
		temp[bits_read] = '\0';
		buf[fd] = ft_strjoinfree(buf[fd], temp);
		if(ft_strchr(buf[fd], '\n'))
			break ;
	}
	return (bits_read);
}

int		get_next_line(const int fd, char **line)
{
	int			bits_read;
	static char		*buf[FD_MAX];
	char			temp[BUFF_SIZE + 1];
	char 			*ptr;

	if (fd < 0 || BUFF_SIZE < 1 || read(fd, 0, 0) < 0 || fd > FD_MAX )
		return (-1);
	if (!buf[fd])
		buf[fd] = ft_strnew(1);
	bits_read = ft_spool(buf, fd, temp);
	if (!(ptr = ft_strchr(buf[fd], '\n')) && bits_read < BUFF_SIZE)
		*line = ft_strdup(buf[fd]);
	else
		*line = ft_strsub(buf[fd], 0, (size_t)(ptr - buf[fd]));
	buf[fd] = ft_strchr(buf[fd], '\n');
	if (buf[fd])
		buf[fd]++;
	if (bits_read < 0)
		return (-1);
	if ((bits_read == 0 && *buf[fd] == '\0'))
	{
		//free(buf[fd]);
		return (0);
	}
	while (1)
		;
	return (1);
}


/*
#include <fcntl.h>
int		main(int argc, char **argv)
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
*/
