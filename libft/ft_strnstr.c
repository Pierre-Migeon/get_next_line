/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmigeon <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/24 11:51:31 by pmigeon           #+#    #+#             */
/*   Updated: 2018/10/23 13:08:10 by pmigeon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	int		i;
	size_t	j;

	i = 0;
	j = 0;
	if (!*needle)
		return ((char *)haystack);
	while (j < len)
	{
		if (haystack[j] == needle[i])
			++i;
		else
		{
			i = 0;
			if (haystack[j] == needle[i])
				--j;
		}
		if (needle[i] == '\0')
			return ((char *)&haystack[j - --i]);
		j++;
	}
	return (NULL);
}
