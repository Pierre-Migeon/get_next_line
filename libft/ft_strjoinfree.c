/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmigeon <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/20 16:07:23 by pmigeon           #+#    #+#             */
/*   Updated: 2018/10/24 18:37:38 by pmigeon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoinfree(char *s1, char *s2)
{
	char	*merge;
	size_t	len;

	if (s1 == NULL || s2 == NULL)
		return (NULL);
	len = 0;
	len += ft_strlen(s1);
	len += ft_strlen(s2);
	if (!(merge = (char *)malloc(sizeof(char) * (len + 1))))
		return (NULL);
	ft_strcpy(merge, s1);
	ft_strcat(merge, s2);
	if (s1 && ft_strcmp(s1, ""))
		free (s1);
	return (merge);
}
