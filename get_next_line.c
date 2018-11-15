/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmigeon <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/12 22:21:19 by pmigeon           #+#    #+#             */
/*   Updated: 2018/11/12 23:56:26 by pmigeon          ###   ########.fr       */
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
	ft_eol = ft_strchr(buf[fd], '\n') + 1;
	buf[fd][ft_strchri(buf[fd], '\n')] = '\0';
	*line = ft_strdup(buf[fd]);
	//printf("line is %s\n", *line);
	ft_bzero(buf[fd], ft_strlen(buf[fd]));
	if (bits_read <= 0)
		return ((bits_read == 0) ? 0 : -1);
	return (1);
}
/*
#include <string.h>
#include <stdio.h>

int				main(void)
{
	char		*line;
	int			fd;
	int			ret;
	int			count_lines;
	int			errors;

	fd = 0;
	count_lines = 0;
	errors = 0;
	line = NULL;
	while ((ret = get_next_line(fd, &line)) > 0)
	{
		printf("line 1 is %s", line);
		if (count_lines == 0 && strcmp(line, "1234567890abcde") != 0)
			errors++;
		count_lines++;
		if (count_lines > 50)
			break ;
	}
	printf("line 2 is %s", line);
	if (count_lines != 1)
		printf("-> must have returned '1' once instead of %d time(s)\n", count_lines);
	if (errors > 0)
		printf("-> must have read \"1234567890abcde\" instead of \"%s\"\n", line);
	if (count_lines == 1 && errors == 0)
		printf("OK\n");
	return (0);
}



#include <stdio.h>
#include <fcntl.h>
#include <assert.h>
int    main(int argc, char **argv)
{
	char 	*line;
	int		out;
	int		p[2];
	int		fd;

	fd = 1;
	out = dup(fd);
	pipe(p);

	dup2(p[1], fd);
	write(fd, "aaa\nbbb\nccc\nddd\n", 16);
	dup2(out, fd);
	close(p[1]);
	get_next_line(p[0], &line);
	assert(strcmp(line, "aaa") == 0);
	get_next_line(p[0], &line);
	assert(strcmp(line, "bbb") == 0);
	get_next_line(p[0], &line);
	assert(strcmp(line, "ccc") == 0);
	get_next_line(p[0], &line);
	assert(strcmp(line, "ddd") == 0);


argc = 0 ;
if (argv[0])
	;


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
//	printf("|%s|\n", line);
            close (fd);
            i++;
        }
    }
//sleep(30);

    return (0);
} */ 
