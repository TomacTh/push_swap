/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_checker_op2_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcharvet <tcharvet@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/01 16:49:56 by tcharvet          #+#    #+#             */
/*   Updated: 2021/08/01 16:57:45 by tcharvet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

void	pa_checker(t_stack *a, t_stack *b)
{
	if (b->len)
	{
		if (push_el(b, a))
			quit(&a->list, &b->list, 1);
	}
}

void	pb_checker(t_stack *a, t_stack *b)
{
	if (a->len)
	{
		if (push_el(a, b))
			quit(&a->list, &b->list, 1);
	}
}

void	sa_checker(t_stack *a)
{
	if (a->len > 1)
		swap_lst(&a->list);
}

void	sb_checker(t_stack *b)
{
	if (b->len > 1)
		swap_lst(&b->list);
}

void	ss_checker(t_stack *a, t_stack *b)
{
	sa_checker(a);
	sb_checker(b);
}
