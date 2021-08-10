/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stack_op2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcharvet <tcharvet@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/30 23:47:50 by tcharvet          #+#    #+#             */
/*   Updated: 2021/07/30 23:52:01 by tcharvet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ra(t_stack *a)
{
	if (a->len > 1)
	{
		rotate(&a->list, a->len);
		ft_putstr_fd("ra\n", 1);
	}
}

void	rb(t_stack *b)
{
	if (b->len > 1)
	{
		rotate(&b->list, b->len);
		ft_putstr_fd("rb\n", 1);
	}
}

void	reverse(t_list **alst, int len)
{
	t_list	*before_last;
	t_list	*last;

	if (len == 2)
		swap_lst(alst);
	else
	{
		before_last = ft_lstbefore_last(*alst);
		last = before_last->next;
		before_last->next = NULL;
		last->next = *alst;
		*alst = last;
	}
}

void	rra(t_stack *a)
{
	if (a->len > 1)
	{
		reverse(&a->list, a->len);
		ft_putstr_fd("rra\n", 1);
	}
}

void	rrb(t_stack *b)
{
	if (b->len > 1)
	{
		reverse(&b->list, b->len);
		ft_putstr_fd("rrb\n", 1);
	}
}
