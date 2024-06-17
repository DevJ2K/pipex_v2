LIBC =	ft_atoi.c ft_bzero.c ft_calloc.c ft_isalnum.c ft_isalpha.c \
		ft_isascii.c ft_isdigit.c ft_isprint.c ft_memchr.c \
		ft_memcmp.c ft_memcpy.c ft_memmove.c ft_memset.c ft_strchr.c \
		ft_strdup.c ft_strlcat.c ft_strlcpy.c ft_strlen.c ft_strncmp.c \
		ft_strnstr.c ft_strrchr.c ft_tolower.c ft_toupper.c ft_strcpy.c \
		ft_strncat.c get_next_line.c get_next_line_utils.c ft_strcmp.c

ADDITIONAL =	ft_itoa.c ft_putchar_fd.c ft_putendl_fd.c ft_putnbr_fd.c ft_putstr_fd.c \
				ft_split.c ft_strjoin.c ft_strmapi.c ft_strtrim.c ft_substr.c ft_striteri.c

BONUS =	ft_lstadd_back_bonus.c ft_lstadd_front_bonus.c ft_lstclear_bonus.c \
		ft_lstdelone_bonus.c ft_lstiter_bonus.c ft_lstlast_bonus.c \
		ft_lstmap_bonus.c ft_lstnew_bonus.c ft_lstsize_bonus.c

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


SRCS = ${LIBC} ${ADDITIONAL}

SRCSALL = ${LIBC} ${ADDITIONAL} ${BONUS}

OBJS = ${SRCS:.c=.o}

OBJSALL = ${SRCSALL:.c=.o}

NAME = libft.a

CC = gcc

CFLAGS = -Wall -Werror -Wextra -I ../includes

.c.o:
		@echo "$(YELLOW)Compilation of : $<..$(DEF_COLOR)"
		@${CC} ${CFLAGS} -c $< -o ${<:.c=.o}

${NAME}:	${OBJS}
	ar -rsc ${NAME} ${OBJS}

bonus:	${OBJSALL}
		@ar -rsc ${NAME} ${OBJSALL}
		@echo "$(CYAN)Libft successfully compiled into$(DEF_COLOR) $(WHITE)$(NAME)$(DEF_COLOR) $(CYAN)!$(DEF_COLOR)"

all:	${NAME}

clean:
		@rm -f ${OBJSALL}
		@echo "$(RED)Deletion of $(OBJS)$(DEF_COLOR)"


fclean:	clean;
		@rm -f ${NAME}
		@echo "$(RED)Deletion of $(OBJS)$(DEF_COLOR)"

re:		fclean all

.PHONY: all clean fclean re bonus
