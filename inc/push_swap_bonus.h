/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_bonus.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcharvet <tcharvet@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/01 00:53:38 by tcharvet          #+#    #+#             */
/*   Updated: 2021/08/01 17:00:55 by tcharvet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_BONUS_H
# define PUSH_SWAP_BONUS_H
# include <unistd.h>
# include <stdlib.h>

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

typedef struct s_gnl
{
	char	*buf;
	size_t	i;
	size_t	max;
	int		y;
}			t_gnl;

void	quit(t_list **a, t_list **b, int exit_code);
void	rotate(t_list **alst, int len);
int		init_el(t_stack *a, int value);
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
int		get_next_line(int fd, char **line);

void	sa_checker(t_stack *a);
void	sb_checker(t_stack *b);
void	ss_checker(t_stack *a, t_stack *b);
void	pa_checker(t_stack *a, t_stack *b);
void	pb_checker(t_stack *a, t_stack *b);
void	ra_checker(t_stack *a);
void	rb_checker(t_stack *b);
void	rr_checker(t_stack *a, t_stack *b);

void	*ft_memcpy(void *dst, const void *src, size_t n);
void	*ft_calloc(size_t count, size_t size);
int		ft_strcmp(const char *s1, const char *s2);
char	*ft_strdup(const char *s);

int		is_sorted(t_stack *a, t_stack *b);
int		push_el(t_stack *giver, t_stack *reciver);
size_t	ft_strlen(const char *s);
void	ft_bzero(void *s, size_t n);
void	ft_putstr_fd(char *s, int fd);
char	**ft_split(char const *s, char c);
char	**free_split(char **strs, int len);
int		ft_atoi_push_swap(const char *str, int *error_code);
void	reverse(t_list **alst, int len);
int		check_double(int num, t_list *list, int *error_code);

int		choose_good_op(char *cmd, t_stack *a, t_stack *b);

#endif
