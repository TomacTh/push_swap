/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_back.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcharvet <tcharvet@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/31 00:25:34 by tcharvet          #+#    #+#             */
/*   Updated: 2021/07/31 00:25:39 by tcharvet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	sort_three_back_a(t_stack *a, t_program *program)
{
	int	max;

	max = a->list->value - 1;
	rra(a);
	if (max == a->list->value)
		reverse_many_el(a, 2, 'a');
	else
	{
		rra(a);
		if (max == a->list->value)
		{
			sa(a);
			rra(a);
		}
		else
			return (back_a_top_middle(a, program));
	}
	if (a->list->value > a->list->next->value)
		sa(a);
	edit_tag(a, 3);
	return (0);
}

int	sort_three_back_b(t_stack *b, t_program *program)
{
	int	max;
	int	i;

	i = 0;
	max = program->a->list->value - 1;
	while (program->b->list->value != max)
	{
		rrb(b);
		i++;
	}
	pa(program->a, b);
	while (i < 3)
	{
		rrb(b);
		i++;
	}
	if (b->list->value < b->list->next->value)
		sb(b);
	push_many_el(program, 2, 'a');
	edit_tag(program->a, 3);
	return (0);
}

int	sort_group_back_one(t_stack *stack, t_program *program)
{
	if (stack->letter == 'a')
		rra(stack);
	else
	{
		rrb(stack);
		pb(program->a, program->b);
		edit_tag(program->a, 1);
	}
	return (0);
}

int	sort_group_back_two(t_stack *stack, t_program *program)
{
	if (stack->letter == 'a')
		reverse_many_el(stack, 2, 'a');
	else
	{
		reverse_many_el(stack, 2, 'b');
		push_many_el(program, 2, 'a');
	}
	if (program->a->list->value > program->a->list->next->value)
		sa(program->a);
	edit_tag(program->a, 2);
	return (0);
}

int	sort_group_back(t_stack *stack, t_program *program, int len)
{
	if (len == 1)
		return (sort_group_back_one(stack, program));
	else if (len == 2)
		return (sort_group_back_two(stack, program));
	else
	{
		if (stack->letter == 'a')
			return (sort_three_back_a(stack, program));
		else
			return (sort_three_back_b(stack, program));
	}
}
