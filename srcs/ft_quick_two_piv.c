/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_quick_two_piv.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcharvet <tcharvet@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/31 00:08:46 by tcharvet          #+#    #+#             */
/*   Updated: 2021/07/31 22:56:23 by tcharvet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_b_and_rotate_if_needed(t_list *el,
	t_twopiv *twopiv, t_program *program)
{
	el->tag = twopiv->first_group;
	if (!program->b->len)
		pb(program->a, program->b);
	else if (program->b->list->tag == twopiv->first_group)
		pb(program->a, program->b);
	else
	{
		pb(program->a, program->b);
		rb(program->b);
	}
}

void	init_twopiv(t_twopiv *twopiv, int min, int len, int group)
{
	twopiv->i = len;
	twopiv->y = 0;
	twopiv->first_group = group + 1;
	twopiv->second_group = group + 2;
	twopiv->third_group = group + 3;
	twopiv->first_piv = len / 3 + min;
	twopiv->second_piv = ((len / 3) * 2) + min;
}

int	stop_quick_sort_onepiv_a(t_list *el, t_onepiv *onepiv, int i)
{
	int		y;
	t_list	*copy;

	y = i;
	copy = el;
	if (!onepiv->y)
	{
		while (i--)
		{
			if (el->value >= onepiv->med)
				el = el->next;
			else
				return (0);
		}
		while (y--)
		{
			copy->tag = onepiv->second_group;
			copy = copy->next;
		}
		return (1);
	}
	return (0);
}

void	quick_sort_two_piv_in_a(int min, int len, int group, t_program *program)
{
	t_twopiv	twopiv;
	t_list		*el;

	init_twopiv(&twopiv, min, len, group);
	el = program->a->list;
	while (twopiv.i--)
	{
		if (stop_quick_sort_twopiv_a(el, &twopiv, twopiv.i + 1))
			break ;
		if (el->value >= twopiv.second_piv)
		{
			el->tag = twopiv.third_group;
			if (el->next && el->next->tag != twopiv.second_group)
				ra(program->a);
			twopiv.y = 1;
		}
		else if (el->value >= twopiv.first_piv)
		{
			el->tag = twopiv.second_group;
			pb(program->a, program->b);
		}
		else
			push_b_and_rotate_if_needed(el, &twopiv, program);
		el = program->a->list;
	}
}

void	quick_sort_two_piv_in_b(int min, int len, int group, t_program *program)
{
	t_twopiv	twopiv;
	t_list		*el;
	int			j;

	j = 0;
	init_twopiv(&twopiv, min, len, group);
	el = program->b->list;
	while (twopiv.i && (j > -1 && twopiv.y > -1))
	{
		if (el->value >= twopiv.second_piv)
		{
			el->tag = twopiv.third_group;
			pa(program->a, program->b);
		}
		else if (el->value >= twopiv.first_piv)
			second_group_twopiv_in_b(&twopiv, el, program);
		else
			first_group_twopiv_in_b(&twopiv, el, program, &j);
		el = program->b->list;
		twopiv.i--;
	}
}
