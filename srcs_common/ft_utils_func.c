/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils_func.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcharvet <tcharvet@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/31 00:02:42 by tcharvet          #+#    #+#             */
/*   Updated: 2021/08/01 16:45:38 by tcharvet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	add_to_tab(int *tab, t_list *el)
{
	int	i;

	i = 0;
	while (el)
	{
		tab[i] = el->value;
		i++;
		el = el->next;
	}
}

void	replace_lst_value_by_index(t_list *lst, int *tab)
{
	int	i;

	while (lst)
	{
		i = 0;
		while (tab[i] != lst->tag)
			i++;
		lst->value = i;
		lst = lst->next;
	}
}

void	reset_lst_tag(t_list *el)
{
	while (el)
	{
		el->tag = 0;
		el = el->next;
	}
}

int	is_sorted(t_stack *a, t_stack *b)
{
	t_list	*el;

	el = a->list;
	if (b->len)
		return (0);
	while (el && el->next)
	{
		if (el->value < el->next->value)
			el = el->next;
		else
			return (0);
	}
	return (1);
}
