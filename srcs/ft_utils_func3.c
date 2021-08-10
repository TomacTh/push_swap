/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils_func3.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcharvet <tcharvet@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/31 00:22:48 by tcharvet          #+#    #+#             */
/*   Updated: 2021/07/31 00:22:54 by tcharvet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	edit_tag(t_stack *stack, int len)
{
	t_list	*el;

	el = stack->list;
	while (len--)
	{
		el->tag = -1;
		el = el->next;
	}
}

void	push_many_el(t_program *program, int len, char letter)
{
	void	(*push)();

	if (letter == 'a')
		push = &pa;
	else
		push = &pb;
	while (len--)
		push(program->a, program->b);
}

void	reverse_many_el(t_stack *stack, int len, char letter)
{
	void	(*reverse)();

	if (letter == 'a')
		reverse = &rra;
	else
		reverse = &rrb;
	while (len--)
		reverse(stack);
}

void	choose_good_piv(t_stack *stack, t_program *program, int len, int tab[2])
{
	void	(*piv)();

	if (len >= 9)
	{
		if (stack->letter == 'a')
			piv = &quick_sort_two_piv_in_a;
		else
			piv = &quick_sort_two_piv_in_b;
	}
	else
	{
		if (stack->letter == 'a')
			piv = &quick_sort_one_piv_in_a;
		else
			piv = &quick_sort_one_piv_in_b;
	}
	piv(tab[0], len, tab[1], program);
}

void	init_quick_struct(t_quick *quick, t_program *program)
{
	quick->min = 0;
	quick->stack = 0;
	quick->maxgroup = -2;
	quick->stack = search_maxgroup_and_count
		(program->a, program->b, &quick->len, &quick->maxgroup);
}
