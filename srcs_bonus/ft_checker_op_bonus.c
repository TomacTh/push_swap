/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_checker_op_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcharvet <tcharvet@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/01 16:48:30 by tcharvet          #+#    #+#             */
/*   Updated: 2021/08/01 16:58:37 by tcharvet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

void	ra_checker(t_stack *a)
{
	if (a->len > 1)
		rotate(&a->list, a->len);
}

void	rb_checker(t_stack *b)
{
	if (b->len > 1)
		rotate(&b->list, b->len);
}

void	rr_checker(t_stack *a, t_stack *b)
{
	ra_checker(a);
	rb_checker(b);
}
