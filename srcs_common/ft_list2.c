/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcharvet <tcharvet@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/30 23:39:43 by tcharvet          #+#    #+#             */
/*   Updated: 2021/07/30 23:50:45 by tcharvet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*ft_lstbefore_last(t_list *lst)
{
	t_list	*prev;

	prev = lst;
	while (lst && lst->next)
	{
		prev = lst;
		lst = lst->next;
	}
	return (prev);
}

t_list	*ft_lstlast(t_list *lst)
{
	while (lst && lst->next)
		lst = lst->next;
	return (lst);
}

void	ft_lstadd_back(t_list **alst, t_list *new)
{
	t_list	*end;

	if (alst)
	{
		if (!*alst)
		{
			*alst = new;
			(*alst)->next = NULL;
		}
		else
		{
			end = ft_lstlast(*alst);
			end->next = new;
			new->next = NULL;
		}
	}
}

t_list	*ft_lstnew(int value, int tag)
{
	t_list	*new;

	new = malloc(sizeof(t_list) * 1);
	if (!new)
		return (NULL);
	new->value = value;
	new->tag = tag;
	new->next = NULL;
	return (new);
}

void	swap_lst(t_list **alst)
{
	t_list	*temp;

	if (*alst && (*alst)->next)
	{
		temp = (*alst)->next;
		(*alst)->next = temp->next;
		temp->next = *alst;
		*alst = temp;
	}
}
