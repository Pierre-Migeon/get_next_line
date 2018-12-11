/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmigeon <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/10 16:39:17 by pmigeon           #+#    #+#             */
/*   Updated: 2018/09/13 18:15:07 by pmigeon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	unsigned char *dummy;

	dummy = (unsigned char *)b;
	while (len--)
	{
		*dummy = (unsigned char)c;
		dummy++;
	}
	return ((void *)b);
}
