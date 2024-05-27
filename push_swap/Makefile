CC = cc
CFLAGS = -Wall -Wextra -Werror -g

INCLUDES = -I.

LIBFT = libft

SRCS = push_swap.c list_utils.c create_stack.c actions.c \
	 simple_sort.c sort_algo.c utils.c test.c output.c stages.c

OBJS = $(SRCS:.c=.o)

NAME = push_swap

all: $(NAME)

$(NAME): $(OBJS)
	make -C $(LIBFT)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS) -L$(LIBFT) -lft

%.o: %.c libft.h
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

clean:
	make clean -C $(LIBFT)
	rm -f $(OBJS)

fclean: clean
	make fclean -C $(LIBFT)
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
