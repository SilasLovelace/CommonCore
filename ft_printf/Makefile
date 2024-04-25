CC = cc
CFLAGS = -Wall -Wextra -Werror

INCLUDES = -I.

LIBFT = libft.a

SRCS = ft_printf.c

OBJS = $(SRCS:.c=.o)

NAME = libftprintf.a

all: $(NAME)

$(NAME): $(OBJS)
	ar rc $@ $^

%.o: %.c libft.h
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

bonus: $(BONUS_OBJS) $(OBJS)
	ar rcs $(NAME) $^

clean:
	rm -f $(OBJS) $(BONUS_OBJS)

fclean: clean
	rm -f $(NAME)


re: fclean all

.PHONY: all clean fclean re bonus

