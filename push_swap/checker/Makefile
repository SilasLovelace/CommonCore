CC = cc
CFLAGS = -Wall -Wextra -Werror -g

INCLUDES = -I.

LIBFT = libft

BONUS_SRCS = get_next_line/get_next_line.c get_next_line/get_next_line_utils.c bonus.c \
	bonus_actions.c list_utils.c create_stack.c actions.c \
	sort_algo.c utils.c test.c output.c stages.c bubble_sort.c free.c \
	checks.c small_input_solutions.c
BONUS_OBJS = $(BONUS_SRCS:.c=.o)
BONUS = checker

all: $(BONUS)

$(BONUS): $(BONUS_OBJS)
	make -C $(LIBFT)
	$(CC) $(CFLAGS) -o $(BONUS) $(BONUS_OBJS) -L$(LIBFT) -lft

clean:
	make clean -C $(LIBFT)
	rm -f $(OBJS) $(BONUS_OBJS)

fclean: clean
	make fclean -C $(LIBFT)
	rm -f $(NAME) $(BONUS)

re: fclean all

.PHONY: all clean fclean re
