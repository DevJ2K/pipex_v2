########################################
########## ARGUMENTS

NAME		= libftprintf.a
CC			= gcc
CFLAGS		= -Wall -Werror -Wextra -I ../includes
AR			= ar -crs
SRCS_DIR	= srcs/

########################################
########## SOURCES
SRCS_FILES	= ft_printf ft_putchar ft_puthexa \
			ft_putnbr ft_putptr ft_putstr ft_putunsigned
SRCS 		= 	$(addprefix $(SRCS_DIR), $(addsuffix .c, $(SRCS_FILES)))

OBJS		= ${SRCS:.c=.o}

.c.o:
		@${CC} ${CFLAGS} -c $< -o ${<:.c=.o}

########################################
########## RULES

all: $(NAME)

$(NAME):	$(OBJS)
			$(AR) $(NAME) $(OBJS)

clean:
		@rm -f $(OBJS)

fclean: clean
		@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
