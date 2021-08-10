/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_quick_one_piv.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcharvet <tcharvet@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/31 00:04:46 by tcharvet          #+#    #+#             */
/*   Updated: 2021/07/31 22:56:17 by tcharvet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	init_onepiv(t_onepiv *onepiv, int min, int len, int group)
{
	onepiv->i = len;
	onepiv->y = 0;
	onepiv->first_group = group + 1;
	onepiv->second_group = group + 2;
	onepiv->med = len / 2 + min;
}

int	stop_quick_sort_twopiv_a(t_list *el, t_twopiv *twopiv, int i)
{
	int		y;
	t_list	*copy;

	y = i;
	copy = el;
	if (!twopiv->y)
	{
		while (i--)
		{
			if (el->value >= twopiv->second_piv)
				el = el->next;
			else
				return (0);
		}
		while (y--)
		{
			copy->tag = twopiv->third_group;
			copy = copy->next;
		}
		return (1);
	}
	return (0);
}

int	stop_quick_sort_onepiv_b(t_list *el, t_onepiv *onepiv, int i)
{
	int		y;
	t_list	*copy;

	copy = el;
	y = i;
	if (!onepiv->y)
	{
		while (i--)
		{
			if (el->value < onepiv->med)
				el = el->next;
			else
				return (0);
		}
		while (y--)
		{
			copy->tag = onepiv->first_group;
			copy = copy->next;
		}
		return (1);
	}
	return (0);
}

void	quick_sort_one_piv_in_b(int min, int len, int group, t_program *program)
{
	t_onepiv	onepiv;
	t_list		*el;

	init_onepiv(&onepiv, min, len, group);
	el = program->b->list;
	while (onepiv.i)
	{
		if (el->value >= onepiv.med)
		{
			el->tag = onepiv.second_group;
			pa(program->a, program->b);
		}
		else
		{
			if (stop_quick_sort_onepiv_b(el, &onepiv, onepiv.i))
				break ;
			el->tag = onepiv.first_group;
			pa(program->a, program->b);
			ra(program->a);
			onepiv.y = 1;
		}
		el = program->b->list;
		onepiv.i--;
	}
}

void	quick_sort_one_piv_in_a(int min, int len, int group, t_program *program)
{
	t_onepiv	onepiv;
	t_list		*el;

	init_onepiv(&onepiv, min, len, group);
	el = program->a->list;
	while (onepiv.i)
	{
		if (stop_quick_sort_onepiv_a(el, &onepiv, onepiv.i))
			break ;
		if (el->value >= onepiv.med)
		{
			el->tag = onepiv.second_group;
			if (el->next && el->next->tag != onepiv.second_group)
				ra(program->a);
			onepiv.y = 1;
		}
		else
		{
			el->tag = onepiv.first_group;
			pb(program->a, program->b);
		}
		el = program->a->list;
		onepiv.i--;
	}
}
