/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmigeon <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/30 20:23:06 by pmigeon           #+#    #+#             */
/*   Updated: 2018/10/31 18:44:50 by pmigeon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	if (!f || !lst)
		return NULL;
	t_list *new;
	t_list *temp;
	t_list *begin;

	temp = (*f)(lst);
	if (!(new = ft_lstnew(temp->content, temp->content_size)))
		return (NULL);
	lst = lst->next;
	begin = new;
	while (lst)
	{
		temp = (*f)(lst);
		if (!(new->next = ft_lstnew(temp->content, temp->content_size)))
			return (NULL);
		new = new->next;
		lst = lst->next;
	}
	return (begin);
}

t_list	*ft_lsttoupper(t_list *elem)
{
	if (*(char *)elem->content >= 'a' && *(char *)elem->content <= 'z')
		*(char *)elem->content -= 32;
	return (elem);
}

#include <unistd.h>
void	ft_lstprint(t_list *lst)
{
	while (lst)
	{
		write(1, lst->content, lst->content_size);
		lst = lst->next;
	}
	write(1, "\n", 1);
}

int		main()
{
	t_list *lst1;
	t_list *start;
	t_list *lst2;

	char letter = 'a';
	lst1 = ft_lstnew(&letter, 1);
	start = lst1;
	letter++;
	while (letter <= 'z')
	{
		lst1->next = ft_lstnew(&letter, 1);
		lst1 = lst1->next;
		letter++;
	}
	ft_lstprint(start);
	lst2 = ft_lstmap(start, ft_lsttoupper);
	ft_lstprint(lst2);
	return (0);
}
