/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcharvet <tcharvet@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/30 23:39:43 by tcharvet          #+#    #+#             */
/*   Updated: 2021/07/30 23:44:37 by tcharvet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_lstadd_front(t_list **alst, t_list *new)
{
	if (alst)
	{
		new->next = *alst;
		*alst = new;
	}
}

t_list	*ft_lst_create_and_addback(t_list **alst, int value, int tag)
{
	t_list	*new;

	new = ft_lstnew(value, tag);
	if (!new)
		return (NULL);
	ft_lstadd_back(alst, new);
	return (new);
}

void	ft_lstdelete(t_list **lst, int code)
{
	t_list	*temp;

	if (lst && *lst)
	{
		temp = (*lst)->next;
		if (code)
			free(*lst);
		*lst = temp;
	}
}

void	ft_lstclear(t_list **lst)
{
	t_list	*tmp;

	if (lst)
	{
		while (*lst)
		{
			tmp = *lst;
			*lst = tmp->next;
			free(tmp);
		}
		*lst = 0;
	}
}

t_list	*ft_lst_create_and_addfront(t_list **alst, int tag, int value)
{
	t_list	*new;

	new = ft_lstnew(tag, value);
	if (!new)
		return (NULL);
	ft_lstadd_front(alst, new);
	return (new);
}
