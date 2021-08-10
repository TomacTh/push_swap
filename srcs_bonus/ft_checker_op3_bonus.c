/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_checker_op3_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcharvet <tcharvet@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/01 16:51:39 by tcharvet          #+#    #+#             */
/*   Updated: 2021/08/01 16:58:07 by tcharvet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

void	rra_checker(t_stack *a)
{
	if (a->len > 1)
		reverse(&a->list, a->len);
}

void	rrb_checker(t_stack *b)
{
	if (b->len > 1)
		reverse(&b->list, b->len);
}

void	rrr_checker(t_stack *a, t_stack *b)
{
	rra_checker(a);
	rrb_checker(b);
}

int	choose_good_op(char *cmd, t_stack *a, t_stack *b)
{
	if (!ft_strcmp(cmd, "ra"))
		ra_checker(a);
	else if (!ft_strcmp(cmd, "rb"))
		rb_checker(b);
	else if (!ft_strcmp(cmd, "rr"))
		rr_checker(a, b);
	else if (!ft_strcmp(cmd, "sa"))
		sa_checker(a);
	else if (!ft_strcmp(cmd, "sb"))
		sb_checker(b);
	else if (!ft_strcmp(cmd, "ss"))
		ss_checker(a, b);
	else if (!ft_strcmp(cmd, "pa"))
		pa_checker(a, b);
	else if (!ft_strcmp(cmd, "pb"))
		pb_checker(a, b);
	else if (!ft_strcmp(cmd, "rrb"))
		rrb_checker(b);
	else if (!ft_strcmp(cmd, "rra"))
		rra_checker(a);
	else if (!ft_strcmp(cmd, "rrr"))
		rrr_checker(a, b);
	else
		return (1);
	return (0);
}
