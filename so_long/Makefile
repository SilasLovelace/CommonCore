CC = cc
CFLAGS = -Wall -Wextra -Werror  -g

INCLUDES = -I.

LIBFT = libft

SRCS = so_long.c map_maker.c

OBJS = $(SRCS:.c=.o)

NAME = so_long

all: $(NAME)

$(NAME): $(OBJS)
	make -C $(LIBFT)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS) -L$(LIBFT) -lXext -lX11 -lm -lz -lmlx -lft

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
