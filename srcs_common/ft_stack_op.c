/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stack_op.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcharvet <tcharvet@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/30 23:45:51 by tcharvet          #+#    #+#             */
/*   Updated: 2021/07/30 23:46:35 by tcharvet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	push_el(t_stack *giver, t_stack *reciver)
{
	if (!ft_lst_create_and_addfront(&reciver->list,
			giver->list->value, giver->list->tag))
		return (1);
	ft_lstdelete(&giver->list, 1);
	giver->len--;
	reciver->len++;
	return (0);
}

void	pa(t_stack *a, t_stack *b)
{
	if (b->len)
	{
		if (push_el(b, a))
			quit(&a->list, &b->list, 1);
		ft_putstr_fd("pa\n", 1);
	}
}

void	pb(t_stack *a, t_stack *b)
{
	if (a->len)
	{
		if (push_el(a, b))
			quit(&a->list, &b->list, 1);
		ft_putstr_fd("pb\n", 1);
	}
}

void	sa(t_stack *a)
{
	if (a->len > 1)
	{
		swap_lst(&a->list);
		ft_putstr_fd("sa\n", 1);
	}
}

void	sb(t_stack *b)
{
	if (b->len > 1)
	{
		swap_lst(&b->list);
		ft_putstr_fd("sb\n", 1);
	}
}
