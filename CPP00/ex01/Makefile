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
			main.cpp \
			Phonebook.cpp \
			Contact.cpp

OBJSDIR		= objs
OBJS		= $(SRCS:.cpp=.o)
DEPS		= $(SRCS:.cpp=.d)

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
