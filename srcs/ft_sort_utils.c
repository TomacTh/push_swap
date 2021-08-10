/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcharvet <tcharvet@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/31 00:35:05 by tcharvet          #+#    #+#             */
/*   Updated: 2021/07/31 22:57:46 by tcharvet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	first_quick_sort(t_stack *a, int total, t_program *program)
{
	if (total < 9)
		quick_sort_one_piv_in_a(0, a->len, 0, program);
	else
		quick_sort_two_piv_in_a(0, a->len, 0, program);
}

void	search_in_lst(t_list *el, int *len, int *maxgroup)
{
	while (el)
	{
		if (el->tag > *maxgroup)
		{
			*maxgroup = el->tag;
			*len = 1;
		}
		else if (el->tag == *maxgroup)
			(*len)++;
		el = el->next;
	}
}

t_stack	*search_maxgroup_and_count(t_stack *a, t_stack *b,
	int *len, int *maxgroup)
{
	t_list	*el;
	int		i;

	*maxgroup = -2;
	*len = 0;
	el = a->list;
	search_in_lst(el, len, maxgroup);
	i = *maxgroup;
	el = b->list;
	search_in_lst(el, len, maxgroup);
	if (i == *maxgroup)
		return (a);
	else
		return (b);
}

void	reverse_group(int len, t_stack *stack)
{
	void	(*reverse)();

	if (stack->letter == 'a')
		reverse = &rra;
	else
		reverse = &rrb;
	while (len--)
		reverse(stack);
}

int	back_a_top_middle(t_stack *a, t_program *program)
{
	if (a->list->value > a->list->next->value)
		sa(a);
	pb(a, program->b);
	rra(a);
	sa(a);
	pa(a, program->b);
	return (0);
}
