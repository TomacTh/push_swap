#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <limits.h>

typedef struct		s_list
{
	int				value;
	int				tag;
	struct s_list	*next;
}					t_list;

typedef struct		s_stack
{
	t_list			*list;
	unsigned int	max_group;
	unsigned int	len;
	char			stack_letter;
}					t_stack;


typedef	struct		s_push_swap 
{
	t_stack			*a;
	t_stack			*b;
	int				command_code;
	unsigned int	total;
	int				error_code;
	int				*sort_tab;
}					t_push_swap;
