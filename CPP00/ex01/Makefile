################################################################################
######                             PROPERTIES                             ######
################################################################################

CC			= c++
RM			= rm -rf
CFLAGS		= -Wall -Wextra -Werror -MD -MP -g -I -std=c++98 #-fsanitize=thread,undefined 
MAKEFLAGS	= -j$(nproc) --no-print-directory

NAME		= phonebook

SRCSDIR		= srcs

SRCS		= \
			phonebook.cpp \

OBJSDIR		= objs
OBJS		= $(SRCS:.cpp=.o)
DEPS		= $(addprefix $(OBJSDIR)/, $(SRCS:.c=.d))

################################################################################
######                               RULES                                ######
################################################################################

all		: $(NAME)

$(NAME)	: ${OBJS}
		$(CC) ${CFLAGS} -o $@ $^

$(OBJSDIR)/%.o : %.cpp
		@mkdir -p $(dir $@)
		${CC} ${CFLAGS} -c $< -o $@

clean	:
		$(RM) $(OBJSDIR)

fclean	: clean
		$(RM) $(NAME)

re		: fclean all

-include $(DEPS)

.PHONY	: all clean fclean re
