/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmigeon <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/12 22:21:19 by pmigeon           #+#    #+#             */
/*   Updated: 2018/11/26 16:21:46 by pmigeon          ###   ########.fr       */
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
	static char **ft_eol = NULL;

	if (!ft_eol)
		ft_eol = (char **)malloc(sizeof(char *) * BUFF_SIZE + 1);
	bits_read = 1;
	ft_bzero(temp, ft_strlen(temp));
	if (fd < 0 || BUFF_SIZE < 1 || read(fd, 0, 0) < 0)
		return (-1);
	if (!buf[fd])
		buf[fd] = ft_strnew(BUFF_SIZE + 1);
	else 
		ft_bzero(buf[fd], ft_strlen(buf[fd]));
	if (ft_eol[fd])
		buf[fd] = ft_strjoinfree(buf[fd], ft_eol[fd]);
	while (!ft_strchr(buf[fd], '\n') && (bits_read = read(fd, temp, BUFF_SIZE)))
	{
		temp[bits_read] = '\0';
		buf[fd] = ft_strjoinfree(buf[fd], temp);
	}
	ft_eol[fd] = (ft_strchrc(buf[fd], '\n') > 0) ? ft_strchr(buf[fd], '\n') + 1: NULL;
	buf[fd][ft_strchri(buf[fd], '\n')] = '\0';
	*line = ft_strdup(buf[fd]);
	if (bits_read < 0)
		return (-1);
	if (ft_strchr(temp, '\n'))
		return (1);
	return ((ft_strlen(*line) > 0 || bits_read != 0) ? 1 : 0);
}

/*
#include <assert.h>
#include <fcntl.h>
int		main(int argc, char **argv)
{
	char *line;
	int fd;
	int fd2;
	int fd3;
	int	diff_file_size;

    system("mkdir -p sandbox");
	system("openssl rand -base64 $((30 * 1000 * 3/4)) | tr -d '\n' | tr -d '\r' > sandbox/one_big_fat_line.txt");
	system("echo '\n' >> sandbox/one_big_fat_line.txt");

	fd = open("sandbox/one_big_fat_line.txt", O_RDONLY);
	fd2 = open("sandbox/one_big_fat_line.txt.mine", O_CREAT | O_RDWR | O_TRUNC, 0755);

	while (get_next_line(fd, &line) == 1)
	{
	    write(fd2, line, strlen(line));
	    write(fd2, "\n", 1);
	}
	if (line)
		write(fd2, line, strlen(line));
	close(fd);
	close(fd2);

	system("diff sandbox/one_big_fat_line.txt sandbox/one_big_fat_line.txt.mine > sandbox/one_big_fat_line.diff");
	fd3 = open("sandbox/one_big_fat_line.diff", O_RDONLY);
	diff_file_size = read(fd3, NULL, 10);
	close(fd3);

	assert(diff_file_size == 0);
}

int		main(int argc, char **argv)
{
	char 	*line;
	int		out;
	int		p[2];
	char 	*str;
	int		len = 50;

	str = (char *)malloc(1000 * 1000);
	*str = '\0';
	while (len--)
		strcat(str, "Lorem ipsum dolor sit amet, consectetur adipiscing elit. Curabitur in leo dignissim, gravida leo id, imperdiet urna. Aliquam magna nunc, maximus quis eleifend et, scelerisque non dolor. Suspendisse augue augue, tempus");
	out = dup(1);
	pipe(p);
	dup2(p[1], 1);

	if (str)
		write(1, str, strlen(str));
	close(p[1]);
	dup2(out, 1);
	get_next_line(p[0], &line);
	printf("%s", line);
	assert(strcmp(line, str) == 0);
}
*/

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
