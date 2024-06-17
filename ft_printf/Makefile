########################################
########## ARGUMENTS

NAME		= libftprintf.a
CC			= gcc
CFLAGS		= -Wall -Werror -Wextra -I ../includes
AR			= ar -crs
SRCS_DIR	= srcs/

########################################
########## COLORS
DEF_COLOR = \033[0;39m
GRAY = \033[0;90m
BOLD_RED = \033[1;91m
RED = \033[0;91m
GREEN = \033[1;92m
YELLOW = \033[1;93m
BLUE = \033[1;94m
MAGENTA = \033[1;95m
CYAN = \033[1;96m
WHITE = \033[1;97m

########################################
########## SOURCES
SRCS_FILES	= ft_printf ft_putchar ft_puthexa \
			ft_putnbr ft_putptr ft_putstr ft_putunsigned
SRCS 		= 	$(addprefix $(SRCS_DIR), $(addsuffix .c, $(SRCS_FILES)))

OBJS		= ${SRCS:.c=.o}

.c.o:
		@echo "$(BLUE)Compilation of : $<..$(DEF_COLOR)"
		@${CC} ${CFLAGS} -c $< -o ${<:.c=.o}

########################################
########## RULES

all: $(NAME)

$(NAME):	$(OBJS)
			@$(AR) $(NAME) $(OBJS)
			@echo "$(CYAN)Ft_printf successfully compiled into$(DEF_COLOR) $(WHITE)$(NAME)$(DEF_COLOR) $(CYAN)!$(DEF_COLOR)"

clean:
		@rm -f $(OBJS)

fclean: clean
		@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
