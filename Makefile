CC		=	gcc
NAME	=	push_swap
NAME_BONUS =	checker
CFLAGS	= 	-Wall -Wextra -Werror
INC		=	./inc
SRCS	=	$(addprefix ./srcs/, ft_args.c ft_push_swap.c ft_quick_one_piv.c ft_quick_two_piv.c ft_sort_back.c ft_sort_front.c ft_sort_utils.c ft_sort.c ft_utils_and_stop_quick.c ft_utils_func3.c)
SRCSCOMMON= $(addprefix ./srcs_common/, ft_list.c ft_list2.c ft_split.c ft_stack_op.c ft_stack_op2.c ft_utils_func.c ft_utils_func2.c ft_utils.c)
SRCSBONUS=  $(addprefix ./srcs_bonus/, ft_checker.c ft_get_next_line_bonus.c ft_utils_bonus.c ft_checker_op_bonus.c ft_checker_op2_bonus.c ft_checker_op3_bonus.c)

OBJS	=	$(SRCS:.c=.o)
OBJSCOMMON =  $(SRCSCOMMON:.c=.o)
OBJSBONUS =	$(SRCSBONUS:.c=.o)

all:	$(NAME)

bonus: $(NAME_BONUS)

%.o: %.c
	$(CC) $(CFLAGS) -I$(INC) -c $< -o $@

$(NAME):	$(OBJS) $(OBJSCOMMON)
	$(CC) $(CFLAGS) $(OBJS) $(OBJSCOMMON) -o $(NAME)

$(NAME_BONUS):	$(OBJSBONUS) $(OBJSCOMMON)
	$(CC) $(CFLAGS) $(OBJSBONUS) $(OBJSCOMMON) -o $(NAME_BONUS)

clean:
	rm -rf $(OBJS)
	rm -rf $(OBJSCOMMON)
	rm -rf $(OBJSBONUS)

fclean:	clean
	rm -f $(NAME) $(NAME_BONUS)


re:	fclean all

.PHONY:	all bonus clean re install
