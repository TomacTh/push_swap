/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_swap.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcharvet <tcharvet@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/14 17:06:02 by tcharvet          #+#    #+#             */
/*   Updated: 2021/07/31 22:58:34 by tcharvet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	quick_sort(t_program *program)
{
	t_quick	quick;

	init_quick_struct(&quick, program);
	while (quick.maxgroup != -1)
	{
		if (quick.len <= 3)
			sort_group(quick.stack, quick.len, program, quick.maxgroup);
		else
		{
			if (quick.stack->list->tag != quick.maxgroup)
				reverse_group(quick.len, quick.stack);
			quick.min = get_min(quick.stack, quick.len);
			if (group_is_sorted(quick.stack, quick.len))
			{
				edit_tag(quick.stack, quick.len);
				if (quick.stack->letter == 'b')
					push_many_el(program, quick.len, 'a');
			}
			else
				choose_good_piv(quick.stack, program,
					quick.len, (int [2]){quick.min, quick.maxgroup});
		}
		quick.stack = search_maxgroup_and_count
			(program->a, program->b, &quick.len, &quick.maxgroup);
	}
}

void	sorting(t_program *program)
{
	if (program->total <= 3)
		sorting_three_or_two(program->a);
	else
	{
		first_quick_sort(program->a, program->total, program);
		quick_sort(program);
	}
	quit(&program->a->list, &program->b->list, 0);
}

void	init_program(int ac, char **av, t_program *program)
{
	check_and_add_args(ac, av, program);
	init_and_sort_tab(program->total, program);
	replace_lst_value_by_index(program->a->list, program->sort_tab);
	free(program->sort_tab);
	reset_lst_tag(program->a->list);
	if (is_sorted(program->a, program->b))
		quit(&program->a->list, &program->b->list, 0);
}

void	init_struct_addresses(t_program *program, t_stack *a, t_stack *b)
{
	ft_bzero(program, sizeof(t_program));
	ft_bzero(a, sizeof(t_stack));
	ft_bzero(b, sizeof(t_stack));
	program->a = a;
	program->b = b;
}

int	main(int ac, char **av)
{
	t_program	program;
	t_stack		a;
	t_stack		b;

	init_struct_addresses(&program, &a, &b);
	init_program(ac, av, &program);
	sorting(&program);
	return (0);
}
