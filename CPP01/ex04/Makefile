################################################################################
######                             PROPERTIES                             ######
################################################################################

CC			= c++
RM			= rm -rf
CFLAGS		= -Wall -Wextra -Werror -MD -MP -g -I -std=c++98 #-fsanitize=thread,undefined 
MAKEFLAGS	= -j$(nproc) --no-print-directory

NAME		= sed

SRCSDIR		= srcs

SRCS		= \
			main.cpp \

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
		${CC} ${CFLAGS} -c $< -o $@

clean	:
		$(RM) $(OBJSDIR)

fclean	: clean
		$(RM) $(NAME)

re		: 
		$(RM) $(OBJSDIR) $(NAME)
		$(MAKE) all

-include $(DEPS)

.PHONY	: all clean fclean re
