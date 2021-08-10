/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stop_quicksort_twopivb.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcharvet <tcharvet@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/31 00:15:18 by tcharvet          #+#    #+#             */
/*   Updated: 2021/07/31 00:27:53 by tcharvet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get_min(t_stack *stack, int len)
{
	int		min;
	t_list	*el;

	min = stack->list->value;
	el = stack->list;
	while (len--)
	{
		if (el->value < min)
			min = el->value;
		el = el->next;
	}
	return (min);
}

int	stop_second_group_twopiv_in_b(t_twopiv *twopiv, t_list *el, int i)
{
	t_list	*copy;
	int		y;

	y = i;
	copy = el;
	if (!twopiv->y)
	{
		while (i--)
		{
			if (copy->value < twopiv->second_group
				&& copy->value >= twopiv->first_group)
				copy = copy->next;
			else
				return (0);
		}
		while (y--)
		{
			el->tag = twopiv->second_group;
			el = el->next;
		}
		twopiv->y = -1;
		return (1);
	}
	return (0);
}

int	second_group_twopiv_in_b(t_twopiv *twopiv,
	t_list *el, t_program *program)
{
	if (!stop_second_group_twopiv_in_b(twopiv, el, twopiv->i))
	{
		twopiv->y = 1;
		el->tag = twopiv->second_group;
		pa(program->a, program->b);
		ra(program->a);
	}
	return (0);
}

int	stop_first_group_twopiv_in_b(t_twopiv *twopiv,
	t_list *el, int *j)
{
	t_list	*copy;
	int		i;
	int		y;

	i = twopiv->i;
	y = i;
	copy = el;
	if (!(*j))
	{
		while (i--)
		{
			if (copy->value < twopiv->first_piv)
				copy = copy->next;
			else
				return (0);
		}
		while (y--)
		{
			el->tag = twopiv->first_group;
			el = el->next;
		}
		*j = -1;
		return (1);
	}
	return (0);
}

int	first_group_twopiv_in_b(t_twopiv *twopiv, t_list *el,
	t_program *program, int *j)
{
	if (!stop_first_group_twopiv_in_b(twopiv, el, j))
	{
		*j = 1;
		el->tag = twopiv->first_group;
		rb(program->b);
	}
	return (0);
}
