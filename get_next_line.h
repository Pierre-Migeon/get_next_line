/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmigeon <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/05 12:59:23 by pmigeon           #+#    #+#             */
/*   Updated: 2018/12/04 20:39:49 by pmigeon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# define BUFF_SIZE 40
# include <unistd.h>
# include "./libft/libft.h"

int		get_next_line(const int fd, char **line);
int		strc(const char *s, int c);
int		ft_spool(char **buf, int fd, char *temp);
int		get_next_line(const int fd, char **line);
char	*ft_strjoinfree(char const *s1, char const *s2);

#endif
