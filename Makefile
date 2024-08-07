########################################
########## VARIABLES

NAME			= pipex
NAME_BONUS		= pipex_bonus
NAME_ADVANCED	= pipex_advanced
CC				= cc
INCLUDES		= includes
CFLAGS			= -Wall -Werror -Wextra -I
# CFLAGS		= -I
FT_PRINTF		= ft_printf
LIBFT			= libft
RM				= rm -f
SRCS_DIR		= srcs/mandatory/
BONUS_SRCS_DIR	= srcs/bonus/
ADVANCED_SRCS_DIR = srcs/advanced/

########################################
########## COLORS
DEF_COLOR = \033[0;39m
GRAY = \033[1;90m
RED = \033[1;91m
GREEN = \033[1;92m
YELLOW = \033[1;93m
BLUE = \033[1;94m
MAGENTA = \033[1;95m
CYAN = \033[1;96m
WHITE = \033[1;97m

########################################
########## SOURCES

# MANDATORY
SRCS_FILES		= pipex utils ft_error
SRCS 			= $(addprefix $(SRCS_DIR), $(addsuffix .c, $(SRCS_FILES)))
OBJS			= $(SRCS:.c=.o)

# BONUS
BONUS_SRCS_FILES	= pipex utils ft_error lst_function handle_heredoc
BONUS_SRCS 			= $(addprefix $(BONUS_SRCS_DIR), $(addsuffix .c, $(BONUS_SRCS_FILES)))
BONUS_OBJS			= $(BONUS_SRCS:.c=.o)

# ADVANCED
ADVANCED_SRCS_FILES	= pipex utils ft_error lst_function handle_heredoc
ADVANCED_SRCS 		= $(addprefix $(ADVANCED_SRCS_DIR), $(addsuffix .c, $(ADVANCED_SRCS_FILES)))
ADVANCED_OBJS		= $(ADVANCED_SRCS:.c=.o)

.c.o:
		@echo "$(MAGENTA)Compilation of : $<..$(DEF_COLOR)"
		@$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $(<:.c=.o)

########################################
########## RULES

all:		$(NAME)

bonus:		$(NAME_BONUS)

advanced:	$(NAME_ADVANCED)

$(NAME):	$(OBJS)
				@make -C $(FT_PRINTF)
				@make bonus -C $(LIBFT)
				@mv ft_printf/libftprintf.a .
				@mv libft/libft.a .
				@$(CC) $(OBJS) libftprintf.a libft.a -o $(NAME)
				@echo "$(GREEN)$(NAME) successfully compiled !$(DEF_COLOR)"
				python welcome.py

$(NAME_BONUS):	$(BONUS_OBJS)
				@make -C $(FT_PRINTF)
				@make bonus -C $(LIBFT)
				@mv ft_printf/libftprintf.a .
				@mv libft/libft.a .
				@$(CC) $(BONUS_OBJS) libftprintf.a libft.a -o $(NAME_BONUS)
				@echo "$(GREEN)$(NAME_BONUS) successfully compiled !$(DEF_COLOR)"
				python welcome.py

$(NAME_ADVANCED):	$(ADVANCED_OBJS)
				@make -C $(FT_PRINTF)
				@make bonus -C $(LIBFT)
				@mv ft_printf/libftprintf.a .
				@mv libft/libft.a .
				@$(CC) $(ADVANCED_OBJS) libftprintf.a libft.a -o $(NAME_ADVANCED)
				@echo "$(GREEN)$(NAME_ADVANCED) successfully compiled !$(DEF_COLOR)"
				python welcome.py

clean:
				@$(RM) $(OBJS)
				@$(RM) $(BONUS_OBJS)
				@$(RM) $(ADVANCED_OBJS)
				@make clean -C $(FT_PRINTF)
				@make clean -C $(LIBFT)
				@echo "$(RED)Deletion of $(OBJS)$(DEF_COLOR)"

fclean: 	clean
				@$(RM) $(NAME)
				@$(RM) $(NAME_BONUS)
				@$(RM) $(NAME_ADVANCED)
				@$(RM) libftprintf.a
				@$(RM) libft.a
				@echo "$(RED)Deletion of $(NAME) & $(NAME_BONUS) & $(NAME_ADVANCED) $(DEF_COLOR)"

re:			fclean all

norm:
			norminette $(SRCS) $(INCLUDES) $(FT_PRINTF) $(LIBFT) | grep -v Norme -B1 || true

.PHONY: all clean fclean re norm bonus
