/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcharvet <tcharvet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/14 17:06:02 by tcharvet          #+#    #+#             */
/*   Updated: 2021/07/23 16:40:38 by tcharvet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"


t_list	*ft_lstnew(int tag, int value);
void	ft_lstadd_back(t_list **alst, t_list *new);
t_list	*ft_lstlast(t_list *lst);
t_list	*ft_lst_before_last(t_list *lst);
t_list	*ft_lstbefore_last(t_list *lst);

void	ft_lstadd_front(t_list **alst, t_list *new)
{
	if (alst)
	{
		new->next = *alst;
		*alst = new;
	}
}

t_list	*ft_lst_create_and_addback(t_list **alst, int tag, int value)
{
	t_list	*new;

	new = ft_lstnew(tag, value);
	if(!new)
		return (NULL);
	ft_lstadd_back(alst, new);
	return (new);
}

int		init_el(t_stack *a, int value)
{
	if (!ft_lst_create_and_addback(&a->list, value, value))
		return (1);
	return (0);
}

t_list	*ft_lst_create_and_addfront(t_list **alst, int tag, int value)
{
	t_list	*new;

	new = ft_lstnew(tag, value);
	if(!new)
		return (NULL);
	ft_lstadd_front(alst, new);
	return (new);
}

size_t	ft_strlen(const char *s)
{
	size_t i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

void	ft_lstdelete(t_list **lst, int code)
{
	t_list *temp;

	if (lst && *lst)
	{
		temp = (*lst)->next;
		if(code)
			free(*lst);
		*lst = temp;
	}
}

void	ft_lstclear(t_list **lst)
{
	t_list *tmp;

	if (lst)
	{
		while (*lst)
		{
			tmp = *lst;
			*lst = tmp->next;
			free(tmp);
		}
		*lst = 0;
	}
}

void	ft_putstr_fd(char *s, int fd)
{
	if (s)
		write(fd, s, ft_strlen(s));
}

void	swap_lst(t_list **alst)
{
	t_list *temp;

	if (*alst && (*alst)->next)
	{
		temp = (*alst)->next;
		(*alst)->next = temp->next;
		temp->next = *alst;
		*alst = temp;
	}
}

int		push_el(t_stack *giver, t_stack *reciver)
{
	if (!ft_lst_create_and_addfront(&reciver->list,
			giver->list->value, giver->list->tag))
		return (1);
	ft_lstdelete(&giver->list, 1);
	giver->len--;
	reciver->len++;
	return (0);
}

void	rotate(t_list **alst, unsigned int len)
{
	t_list *last;
	t_list *temp;

	if(len == 2)
	{
		swap_lst(alst);
	}
	else
	{	
		last = ft_lstlast(*alst);
		temp = (*alst)->next;
		last->next = *alst;
		(*alst)->next = NULL;
		*alst = temp;
	}
}

void	ra(t_stack *a, int *command_code)
{
	if(a->len > 1)
	{
		rotate(&a->list, a->len);
		if(*command_code == 7)
		{
			ft_putstr_fd("rr\n", 1);
			*command_code = 8;
		}
		else
		{
			ft_putstr_fd("ra\n", 1);
			*command_code = 6;
		}
	}
}

void	rb(t_stack *b, int *command_code)
{
	if(b->len > 1)
	{
		rotate(&b->list, b->len);
		if(*command_code == 6)
		{
			ft_putstr_fd("rr\n", 1);
			*command_code = 8;
		}
		else
		{
			ft_putstr_fd("ra\n", 1);
			*command_code = 7;
		}
	}
}

void	pa(t_stack *a, t_stack *b, int *command_code)
{	
	if(b->len)
	{
		if(push_el(b, a))
			exit(1);
		ft_putstr_fd("pb\n", 1);
		*command_code = 4;
	}
}

void	pb(t_stack *a, t_stack *b, int *command_code)
{	
	if(a->len)
	{
		if(push_el(a, b))
			exit(1);
		ft_putstr_fd("pb\n", 1);
		*command_code = 5;
	}
}

void	sa(t_stack *a, int *command_code)
{
	if (a->len > 1)
	{
		swap_lst(&a->list);
		if (*command_code == 2)
		{
			ft_putstr_fd("ss\n", 1);
			*command_code = 3;
		}
		else
		{	
			ft_putstr_fd("sa\n", 1);
			*command_code = 1;
		}
	}
}

void	sb(t_stack *b, int *command_code)
{
	if (b->len > 1)
	{
		swap_lst(&b->list);
		if (*command_code == 1)
		{
			ft_putstr_fd("ss\n", 1);
			*command_code = 3;
		}
		else
		{	
			ft_putstr_fd("sa\n", 1);
			*command_code = 2;
		}
	}
}

void	reverse(t_list **alst, unsigned int len)
{
	t_list *before_last;
	t_list *last;

	if(len == 2)
		swap_lst(alst);
	else
	{
		before_last = ft_lstbefore_last(*alst);
		last = before_last->next;
		before_last->next = NULL;
		last->next = *alst;
		*alst = last;
	}
}

void	rra(t_stack *a, int *command_code)
{
	if(a->len > 1)
	{
		reverse(&a->list, a->len);
		if(*command_code == 10)
		{
			ft_putstr_fd("rrr\n", 1);
			*command_code = 11;
		}
		else
		{
			ft_putstr_fd("rra\n", 1);
			*command_code = 9;
		}
	}
}

void	rrb(t_stack *b, int *command_code)
{
	if(b->len > 1)
	{
		reverse(&b->list, b->len);
		if(*command_code == 9)
		{
			ft_putstr_fd("rrr\n", 1);
			*command_code = 11;
		}
		else
		{
			ft_putstr_fd("rra\n", 1);
			*command_code = 10;
		}
	}
}

t_list	*ft_lstbefore_last(t_list *lst)
{	
	t_list *prev;

	prev = 0;
	while (lst && lst->next)
	{	
		prev = lst;
		lst = lst->next;
	}
	return (prev);
}

t_list	*ft_lstlast(t_list *lst)
{
	while (lst && lst->next)
		lst = lst->next;
	return (lst);
}

void	ft_lstadd_back(t_list **alst, t_list *new)
{
	t_list *end;

	if (alst)
	{
		if (!*alst)
		{
			*alst = new;
			(*alst)->next = NULL;
		}
		else
		{
			end = ft_lstlast(*alst);
			end->next = new;
			new->next = NULL;
		}
	}
}

t_list	*ft_lstnew(int tag, int value)
{
	t_list *new;

	if (!(new = malloc(sizeof(t_list) * 1)))
		return (NULL);
	new->value = value;
	new->tag = tag;
	new->next = NULL;
	return (new);
}

void	ft_bzero(void *s, size_t n)
{
	while (n-- > 0)
		*(char*)s++ = 0;
}

int	ft_atoi_push_swap(const char *str, int *error_code)
{
	ssize_t	num;
	int		sign;

	num = 0;
	sign = 1;
	while ((*(char*)str >= '\t' && *(char*)str <= '\r')
	|| *(char*)str == ' ')
		str++;
	if (*(char*)str == '-')
	{
		sign = -1;
		str++;
	}
	if(!*str)
		*error_code = 1;
	while (*(char*)str >= '0' && *(char*)str <= '9')
	{
		num = num * 10 + (*(char*)str - '0');
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
	while(el)
	{
		if(el->value == num)
		{
			*error_code = 1;
			return (1);
		}
		el = el->next;
	}
	return (0);
}

void	quit(t_push_swap *program, int exit_code)
{
	ft_lstclear(&program->a->list);
	ft_lstclear(&program->b->list);
	if(program->sort_tab)
		free(program->sort_tab);
	if(exit_code == 1)
	{
		ft_putstr_fd("Error\n", 2);
		exit(1);
	}
	exit(0);
}

void	check_and_add_args(int ac, char **av, t_push_swap *program)
{
	int	i;
	int				num;
	t_stack			*a;

	i = 1;
	a = program->a;
	if(ac < 2)
	{
		ft_putstr_fd("Error\n", 2);
		exit(1);
	}
	while(i < ac)
	{
		num = ft_atoi_push_swap(av[i], &program->error_code);
		check_double(num, a->list, &program->error_code);
		if(program->error_code)
			quit(program, 1);
		if	(init_el(a, num))
			quit(program, 1);
		i++;
	}
	a->len = i - 1;
	program->total = a->len;
	a->stack_letter = 'a';
	program->b->stack_letter = 'b';
}

int	insert_sort(int *tab, unsigned int len)
{
	unsigned int	curr;
	int 			i;
	int				swap;

	curr = 1;
	while(curr < len)
	{
		i = curr - 1;
		if(tab[curr] < tab[i])
		{
			swap = tab[curr];
			while(i >= 0 && swap < tab[i])
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

void	add_to_tab(int *tab, t_list *el)
{	
	unsigned int i;
	
	i = 0;
	while(el)
	{
		tab[i] = el->value;
		i++;
		el = el->next;
	}
}

void	init_and_sort_tab(unsigned int total, t_push_swap *program)
{	
	if (total == 1)
		quit(program, 0);
	program->sort_tab = malloc(sizeof(int) * total);
	if (!program->sort_tab)
		quit(program, 1);
	add_to_tab(program->sort_tab, program->a->list);
	insert_sort(program->sort_tab, total);
}

void	replace_lst_value_by_index(t_list *lst, int *tab)
{	
	unsigned int	i;
	
	while(lst)
	{
		i = 0;
		while(tab[i] != lst->tag)
			i++;
		lst->value = i;
		lst = lst->next;
	}
}

void	reset_lst_tag(t_list *el)
{
	while(el)
	{
		el->tag = 0;
		el = el->next;
	}
}

int		is_sorted(t_stack *a, t_stack *b)
{
	t_list *el;

	el = a->list;
	if(b->len)
		return (0);
	while(el && el->next)
	{
		if(el->value < el->next->value)
			el = el->next;
		else
			return (0);
	}
	return (1);
}

int		max(int a, int b, int c)
{
	if(a > b && a > c)
		return (a);
	else if(b > c && b > a)
		return (b);
	return (c);
}
void	sort_three_elements_in_a(t_stack *a, int *command_code)
{
	int	first;
	int	second;
	int	third;
	int biggest;

	first = a->list->value;
	second = a->list->next->value;
	third  = a->list->next->next->value;
	biggest = max(first, second, third);
	if(biggest != third)
	{
		if(first == biggest)
			ra(a, command_code);
		else
			rra(a, command_code);
	}
	if(a->list->value > a->list->next->value)
		sa(a, command_code);
}

void	sorting_three_or_two(t_push_swap *program)
{
	if(program->total <= 3)
	{
		if(program->total == 2)
			sa(program->a, &	program->command_code);
		else
			sort_three_elements_in_a(program->a, &program->command_code);
		quit(program, 0);
	}
}

void	sorting(t_push_swap *program)
{
	sorting_three_or_two(program);
}

void	init_program(int ac, char **av, t_push_swap *program)
{	
	check_and_add_args(ac, av, program);
	init_and_sort_tab(program->total, program);
	replace_lst_value_by_index(program->a->list, program->sort_tab);
	reset_lst_tag(program->a->list);
	if(is_sorted(program->a, program->b))
		quit(program,0);	
}

void	init_struct_addresses(t_push_swap *program, t_stack *a, t_stack *b)
{
	ft_bzero(program, sizeof(t_push_swap));
	ft_bzero(a, sizeof(t_stack));
	ft_bzero(b, sizeof(t_stack));
	program->a = a;
	program->b = b;
}

int main(int ac, char **av)
{


	t_push_swap	program;
	t_stack		a;
	t_stack		b;

	init_struct_addresses(&program, &a, &b);
	init_program(ac, av, &program);
	sorting(&program);
	return (0);
}
//run 45 -1000 0 9 -1 45 7812 448
