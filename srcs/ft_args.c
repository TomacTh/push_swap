/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_args.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcharvet <tcharvet@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/30 23:56:30 by tcharvet          #+#    #+#             */
/*   Updated: 2021/08/01 16:52:19 by tcharvet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	add_args_to_stack(int ac, char **tab, t_program *program)
{
	int		i;
	int		num;
	t_stack	*a;

	i = 1;
	a = program->a;
	while (i < ac)
	{
		num = ft_atoi_push_swap(tab[i], &program->error_code);
		check_double(num, a->list, &program->error_code);
		if (program->error_code || init_el(a, num))
			quit(&program->a->list, &program->b->list, 1);
		i++;
	}
	a->len = i - 1;
	program->total = a->len;
	a->letter = 'a';
	program->b->letter = 'b';
}

void	add_var_args__to_stack(char **tab, t_program *program)
{
	int		i;
	int		num;
	t_stack	*a;

	a = program->a;
	i = 0;
	while (tab[i])
	{
		num = ft_atoi_push_swap(tab[i], &program->error_code);
		check_double(num, a->list, &program->error_code);
		if (program->error_code || init_el(a, num))
		{
			free_split(tab, -1);
			quit(&program->a->list, &program->b->list, 1);
		}
		i++;
	}
	free_split(tab, -1);
	a->len = i;
	program->total = a->len;
	a->letter = 'a';
	program->b->letter = 'b';
}

void	check_and_add_args(int ac, char **av, t_program *program)
{
	char			**arg;

	arg = 0;
	if (ac == 1)
		exit(0);
	if (ac == 2)
	{
		arg = ft_split(av[1], ' ');
		if (!arg)
			quit(&program->a->list, &program->b->list, 1);
		add_var_args__to_stack(arg, program);
	}
	else
		add_args_to_stack(ac, av, program);
}

int	insert_sort(int *tab, int len)
{
	int	curr;
	int	i;
	int	swap;

	curr = 1;
	while (curr < len)
	{
		i = curr - 1;
		if (tab[curr] < tab[i])
		{
			swap = tab[curr];
			while (i >= 0 && swap < tab[i])
			{
				tab[i + 1] = tab[i];
				i--;
			}
			tab[i + 1] = swap;
		}
		curr++;
	}
	return (0);
}

void	init_and_sort_tab(int total, t_program *program)
{
	if (total == 1)
		quit(&program->a->list, &program->b->list, 0);
	program->sort_tab = malloc(sizeof(int) * total);
	if (!program->sort_tab)
		quit(&program->a->list, &program->b->list, 1);
	add_to_tab(program->sort_tab, program->a->list);
	insert_sort(program->sort_tab, total);
}
