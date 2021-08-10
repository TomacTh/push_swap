/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils_func2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcharvet <tcharvet@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/31 00:04:00 by tcharvet          #+#    #+#             */
/*   Updated: 2021/07/31 00:04:10 by tcharvet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate(t_list **alst, int len)
{
	t_list	*last;
	t_list	*temp;

	if (len == 2)
		swap_lst(alst);
	else
	{
		last = ft_lstlast(*alst);
		temp = (*alst)->next;
		last->next = *alst;
		(*alst)->next = NULL;
		*alst = temp;
	}
}

int	ft_atoi_push_swap(const char *str, int *error_code)
{
	ssize_t	num;
	int		sign;

	num = 0;
	sign = 1;
	while ((*(char *)str >= '\t' && *(char *)str <= '\r')
		|| *(char *)str == ' ')
		str++;
	if (*(char *)str == '-' || *(char *)str == '+')
	{
		if (*(char *)str == '-')
			sign = -1;
		str++;
	}
	if (!*str)
		*error_code = 1;
	while (*(char *)str >= '0' && *(char *)str <= '9')
	{
		num = num * 10 + (*(char *)str - '0');
		str++;
	}
	if (num > INT_MAX || num < INT_MIN || *str)
		*error_code = 1;
	return (num * sign);
}

int	check_double(int num, t_list *list, int *error_code)
{
	t_list	*el;

	el = list;
	while (el)
	{
		if (el->value == num)
		{
			*error_code = 1;
			return (1);
		}
		el = el->next;
	}
	return (0);
}

void	quit(t_list **a, t_list **b, int exit_code)
{
	ft_lstclear(a);
	ft_lstclear(b);
	if (exit_code == 1)
	{
		ft_putstr_fd("Error\n", 2);
		exit(1);
	}
	exit(0);
}
