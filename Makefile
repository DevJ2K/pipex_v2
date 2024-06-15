########################################
########## VARIABLES

NAME		= pipex
CC			= gcc
INCLUDES	= includes
# CFLAGS		= -Wall -Werror -Wextra -I
CFLAGS		= -I
FT_PRINTF	= ft_printf
LIBFT		= libft
RM			= rm -f
SRCS_DIR	= srcs/

########################################
########## SOURCES
SRCS_FILES	= pipex utils ft_error
SRCS 		= $(addprefix $(SRCS_DIR), $(addsuffix .c, $(SRCS_FILES)))
OBJS		= $(SRCS:.c=.o)

.c.o:
		@$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $(<:.c=.o)

########################################
########## RULES

all:		$(NAME)

$(NAME):	$(OBJS)
				make -C $(FT_PRINTF)
				make -C $(LIBFT)
				mv ft_printf/libftprintf.a .
				mv libft/libft.a .
				$(CC) $(OBJS) libftprintf.a libft.a -o $(NAME)

clean:
				$(RM) $(OBJS)
				make clean -C $(FT_PRINTF)
				make clean -C $(LIBFT)

fclean: 	clean
				@$(RM) $(NAME)
				@$(RM) libftprintf.a
				@$(RM) libft.a

re:			fclean all

bonus:		all

norm:
			norminette $(SRCS) $(INCLUDES) $(FT_PRINTF) $(LIBFT) | grep -v Norme -B1 || true

.PHONY: all clean fclean re norm bonus
