/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcharvet <tcharvet@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/31 23:04:53 by tcharvet          #+#    #+#             */
/*   Updated: 2021/08/01 16:46:07 by tcharvet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <limits.h>

typedef struct s_list
{
	int				value;
	int				tag;
	struct s_list	*next;
}					t_list;

typedef struct s_stack
{
	t_list			*list;
	int				len;
	char			letter;
}					t_stack;

typedef struct s_program
{
	t_stack			*a;
	t_stack			*b;
	int				total;
	int				error_code;
	int				*sort_tab;
}					t_program;

typedef struct s_onepiv
{
	int				med;
	int				i;
	int				y;
	int				first_group;
	int				second_group;
}					t_onepiv;

typedef struct s_twopiv
{
	int				first_piv;
	int				second_piv;
	int				i;
	int				y;
	int				first_group;
	int				second_group;
	int				third_group;
}					t_twopiv;

typedef struct s_quick
{
	int				len;
	int				maxgroup;
	t_stack			*stack;
	int				min;
}					t_quick;

void	pa(t_stack *a, t_stack *b);
void	pb(t_stack *a, t_stack *b);
void	sa(t_stack *a);
void	sb(t_stack *b);
void	rb(t_stack *b);
void	ra(t_stack *a);
void	rra(t_stack *a);
void	rra(t_stack *a);
void	rrb(t_stack *b);

void	rotate(t_list **alst, int len);
void	reverse_many_el(t_stack *stack, int len, char letter);
void	push_many_el(t_program *program, int len, char letter);
int		init_el(t_stack *a, int value);
void	reverse_group(int len, t_stack *stack);

void	quick_sort_one_piv_in_a(int min, int len, int group,
			t_program *program);
void	quick_sort_two_piv_in_a(int min, int len, int group,
			t_program *program);
void	quick_sort_one_piv_in_b(int min, int len, int group,
			t_program *program);
void	quick_sort_two_piv_in_b(int min, int len, int group,
			t_program *program);
int		stop_quick_sort_onepiv_a(t_list *el, t_onepiv *onepiv, int i);
int		stop_quick_sort_twopiv_a(t_list *el, t_twopiv *twopiv, int i);
int		second_group_twopiv_in_b(t_twopiv *twopiv,
			t_list *el, t_program *program);
int		first_group_twopiv_in_b(t_twopiv *twopiv, t_list *el,
			t_program *program, int *j);

void	ft_lstdelete(t_list **lst, int code);
void	ft_lstadd_back(t_list **alst, t_list *new);
t_list	*ft_lstlast(t_list *lst);
t_list	*ft_lst_before_last(t_list *lst);
t_list	*ft_lstbefore_last(t_list *lst);
t_list	*ft_lst_create_and_addback(t_list **alst, int value, int tag);
t_list	*ft_lst_create_and_addfront(t_list **alst, int tag, int value);
t_list	*ft_lstnew(int tag, int value);
void	ft_lstclear(t_list **lst);

void	swap_lst(t_list **alst);
void	reset_lst_tag(t_list *el);
void	edit_tag(t_stack *stack, int len);
void	choose_good_piv(t_stack *stack, t_program *program,
			int len, int tab[2]);
int		group_is_sorted(t_stack *stack, int len);
int		get_max(int a, int b, int c);
int		get_min(t_stack *stack, int len);
int		back_a_top_middle(t_stack *a, t_program *program);
void	init_quick_struct(t_quick *quick, t_program *program);
void	first_quick_sort(t_stack *a, int total, t_program *program);
void	quit(t_list **a, t_list **b, int exit_code);

int		sort_group(t_stack *stack, int len, t_program *program, int maxgroup);
int		sort_three_front_a(t_stack *a, t_program *program);
int		sort_three_front_b(t_stack *b, t_program *program);
int		group_already_sort_front(t_stack *stack, int len, t_program *program);
int		sort_two_front(t_stack *stack, t_program *program);
int		sort_three_elements_in_a(t_stack *a);
int		sort_group_back(t_stack *stack, t_program *program, int len);
void	sorting_three_or_two(t_stack *a);
t_stack	*search_maxgroup_and_count(t_stack *a, t_stack *b,
			int *len, int *maxgroup);

void	ft_bzero(void *s, size_t n);
void	ft_putstr_fd(char *s, int fd);
char	**ft_split(char const *s, char c);
char	**free_split(char **strs, int len);
int		ft_atoi_push_swap(const char *str, int *error_code);

void	add_to_tab(int *tab, t_list *el);
int		is_sorted(t_stack *a, t_stack *b);
void	check_and_add_args(int ac, char **av, t_program *program);
int		check_double(int num, t_list *list, int *error_code);
void	replace_lst_value_by_index(t_list *lst, int *tab);
void	init_and_sort_tab(int total, t_program *program);

#endif
