/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcharvet <tcharvet@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/31 00:29:58 by tcharvet          #+#    #+#             */
/*   Updated: 2021/07/31 22:56:32 by tcharvet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sorting_three_or_two(t_stack *a)
{
	if (a->len == 2)
		sa(a);
	else
		sort_three_elements_in_a(a);
}

int	sort_three_elements_in_a(t_stack *a)
{
	int	first;
	int	second;
	int	third;
	int	biggest;

	first = a->list->value;
	second = a->list->next->value;
	third = a->list->next->next->value;
	biggest = get_max(first, second, third);
	if (biggest != third)
	{
		if (first == biggest)
			ra(a);
		else
			rra(a);
	}
	if (a->list->value > a->list->next->value)
		sa(a);
	edit_tag(a, 3);
	return (0);
}

int	group_is_sorted_in_b(t_stack *stack, int len)
{
	t_list	*el;

	el = stack->list;
	if (stack->letter == 'b')
	{
		--len;
		while (len--)
		{
			if (el->value > el->next->value)
				el = el->next;
			else
				return (0);
		}
		return (1);
	}
	return (0);
}

int	group_is_sorted(t_stack *stack, int len)
{
	t_list	*el;

	el = stack->list;
	if (stack->letter == 'a')
	{
		--len;
		while (len--)
		{
			if (el->value < el->next->value)
				el = el->next;
			else
				return (0);
		}
		return (1);
	}
	return (group_is_sorted_in_b(stack, len));
}

int	sort_group(t_stack *stack, int len, t_program *program, int maxgroup)
{
	if (stack->list->tag == maxgroup)
	{
		if (group_is_sorted(stack, len))
			return (group_already_sort_front(stack, len, program));
		else if (len == 2)
			return (sort_two_front(stack, program));
		else
		{
			if (stack->letter == 'a')
			{
				if (stack->len > 3)
					return (sort_three_front_a(stack, program));
				else
					return (sort_three_elements_in_a(stack));
			}
			else
				return (sort_three_front_b(stack, program));
		}
	}
	return (sort_group_back(stack, program, len));
}
