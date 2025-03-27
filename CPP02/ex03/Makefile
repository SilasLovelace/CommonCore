################################################################################
######                             PROPERTIES                             ######
################################################################################

CC			= c++
RM			= rm -rf
CFLAGS		= -Wall -Wextra -Werror -MD -MP -g -I -std=c++98
MAKEFLAGS	= -j$(nproc) --no-print-directory

NAME		= bsp

SRCSDIR		= srcs

SRCS		= \
			main.cpp \
			Fixed.cpp \
			Point.cpp \

OBJSDIR		= objs
OBJS		= $(addprefix $(OBJSDIR)/, $(SRCS:.cpp=.o))
DEPS		= $(addprefix $(OBJSDIR)/, $(SRCS:.cpp=.d))

#------------------------------------------------------------------------------#
#------------------------------------RULES-------------------------------------#
#------------------------------------------------------------------------------#

all		: $(NAME)

$(NAME)	: ${OBJS}
		$(CC) ${CFLAGS} -o $@ $^ 

${OBJSDIR}/%.o	: %.cpp
		@mkdir -p $(dir $@)
		${CC} ${CFLAGS} -c $< -o $@

clean	:
		$(RM) $(OBJSDIR)

fclean	:
		$(RM) $(OBJSDIR) $(NAME)

re		:
		$(RM) $(OBJSDIR) $(NAME)
		$(MAKE) all

-include $(DEPS)

.PHONY	: all clean fclean re
