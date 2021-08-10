/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_front.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcharvet <tcharvet@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/31 00:24:49 by tcharvet          #+#    #+#             */
/*   Updated: 2021/07/31 00:24:55 by tcharvet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	three_front_max_middle(t_stack *a, t_program *program)
{
	ra(a);
	if (a->list->value > a->list->next->value)
		sa(a);
	pb(a, program->b);
	rra(a);
	sa(a);
	pa(a, program->b);
	return (0);
}

int	sort_three_front_a(t_stack *a, t_program *program)
{
	t_list	*el;
	int		max;

	el = a->list;
	max = get_max(el->value, el->next->value, el->next->next->value);
	if (el->next->next->value != max)
	{
		if (max == el->next->value)
		{
			pb(a, program->b);
			sa(a);
			pa(a, program->b);
		}
		else
			return (three_front_max_middle(a, program));
	}
	if (a->list->value > a->list->next->value)
		sa(a);
	edit_tag(a, 3);
	return (0);
}

int	sort_two_front(t_stack *stack, t_program *program)
{
	if (stack->letter == 'a')
		sa(program->a);
	else
	{
		sb(program->b);
		push_many_el(program, 2, 'a');
	}
	edit_tag(program->a, 2);
	return (0);
}

int	group_already_sort_front(t_stack *stack, int len, t_program *program)
{
	edit_tag(stack, len);
	if (stack->letter == 'b')
		push_many_el(program, len, 'a');
	return (0);
}

int	sort_three_front_b(t_stack *b, t_program *program)
{
	int	i;

	i = 0;
	while (i < 3)
	{
		if (i < 2)
		{
			if (b->list->value < b->list->next->value)
				sb(b);
		}
		pa(program->a, b);
		if (program->a->len >= 2)
		{
			if (program->a->list->value > program->a->list->next->value)
				sa(program->a);
		}
		i++;
	}
	edit_tag(program->a, 3);
	return (0);
}
