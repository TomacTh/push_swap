/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_checker.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcharvet <tcharvet@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/31 23:43:25 by tcharvet          #+#    #+#             */
/*   Updated: 2021/08/01 16:53:44 by tcharvet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

void	add_args_to_stack_checker(int ac, char **tab, t_stack *a, t_stack *b)
{
	int		i;
	int		num;
	int		error_code;

	error_code = 0;
	i = 1;
	while (i < ac)
	{
		num = ft_atoi_push_swap(tab[i], &error_code);
		check_double(num, a->list, &error_code);
		if (error_code || init_el(a, num))
			quit(&a->list, &b->list, 1);
		i++;
	}
	a->len = i - 1;
}

void	add_var_args__to_stack_checker(char **tab, t_stack *a, t_stack *b)
{
	int		i;
	int		num;
	int		error_code;

	error_code = 0;
	i = 0;
	while (tab[i])
	{
		num = ft_atoi_push_swap(tab[i], &error_code);
		check_double(num, a->list, &error_code);
		if (error_code || init_el(a, num))
		{
			free_split(tab, -1);
			quit(&a->list, &b->list, 1);
		}
		i++;
	}
	free_split(tab, -1);
	a->len = i;
}

void	check_and_add_args_checker(int ac, char **av, t_stack *a, t_stack *b)
{
	char			**arg;

	arg = 0;
	if (ac == 1)
		exit(0);
	if (ac == 2)
	{
		arg = ft_split(av[1], ' ');
		if (!arg)
			quit(&a->list, &b->list, 1);
		add_var_args__to_stack_checker(arg, a, b);
	}
	else
		add_args_to_stack_checker(ac, av, a, b);
}

void	check(t_stack *a, t_stack *b)
{
	int		i;
	char	*cmd;

	i = 1;
	cmd = 0;
	while (i)
	{
		i = get_next_line(0, &cmd);
		if (i == -1)
			quit(&a->list, &b->list, 1);
		else if (i && choose_good_op(cmd, a, b))
		{
			free(cmd);
			quit(&a->list, &b->list, 1);
		}
		free(cmd);
	}
	if (is_sorted(a, b))
		ft_putstr_fd("OK\n", 1);
	else
		ft_putstr_fd("KO\n", 1);
	quit(&a->list, &b->list, 0);
}

int	main(int ac, char **av)
{
	t_stack	a;
	t_stack	b;

	ft_bzero(&a, sizeof(a));
	ft_bzero(&b, sizeof(b));
	check_and_add_args_checker(ac, av, &a, &b);
	check(&a, &b);
	return (0);
}
