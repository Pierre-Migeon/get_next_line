/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmigeon <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/05 12:59:23 by pmigeon           #+#    #+#             */
/*   Updated: 2018/11/25 21:43:06 by pmigeon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# define BUFF_SIZE 200 
# include <unistd.h>
# include <string.h>
# include <strings.h>
# include <stdlib.h>
#include "./libft/libft.h"

int    get_next_line(const int fd, char **line);

#endif
