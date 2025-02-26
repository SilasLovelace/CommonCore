################################################################################
######                             PROPERTIES                             ######
################################################################################

CC			= c++
RM			= rm -rf
CFLAGS		= -Wall -Wextra -Werror -MD -MP -g -I -std=c++98 #-fsanitize=thread,undefined 
MAKEFLAGS	= -j$(nproc) --no-print-directory

NAME		= Fixed

SRCSDIR		= srcs

SRCS		= \
			main.cpp \
			Fixed.cpp 

OBJSDIR		= objs
OBJS		= $(SRCS:.cpp=.o)
DEPS		= $(addprefix $(OBJSDIR)/, $(SRCS:.c=.d))

################################################################################
######                               RULES                                ######
################################################################################

all		: $(NAME)

$(NAME)	: ${OBJS}
		$(CC) ${CFLAGS} -o $@ $^

%.o	: %.cpp
		@mkdir -p $(dir $@)
		${CC} ${CFLAGS} -c $< -o $@

clean	:
		$(RM) 

fclean	:
		$(RM) $(NAME)

re		:
		$(RM) $(NAME)
		$(MAKE) all

-include $(DEPS)

.PHONY	: all clean fclean re
