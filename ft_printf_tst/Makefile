CC = cc
CFLAGS = -Wall -Wextra -Werror

INCLUDES = -I.

LIBFT = libft

SRCS = ft_printf.c helper_i_d_u.c helper_base.c

OBJS = $(SRCS:.c=.o)

NAME = libftprintf.a

all: $(NAME)

$(NAME): $(OBJS)
	make -C $(LIBFT)
	cp libft/libft.a $(NAME)
	ar rc $@ $^

%.o: %.c libft.h
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

clean:
	make clean -C $(LIBFT)
	rm -f $(OBJS) 

fclean: clean
	make fclean -C $(LIBFT)
	rm -f $(NAME)


re: fclean all

.PHONY: all clean fclean re bonus
