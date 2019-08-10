# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ldonnor- <ldonnor-@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/05/14 22:31:23 by ldonnor-          #+#    #+#              #
#    Updated: 2019/07/04 18:12:29 by ldonnor-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= ldonnor-.filler

SRC		= main.c\
		go_go_diega.c\
		who_is_who.c\
		split_str.c\

GREEN = \033[0;32m
RED = \033[0;31m
PURPLE = \033[0;35m
CYAN = \033[0;36m
RESET = \033[0m
YELLOW = \033[0;33m
BLUE = \033[0;34m
CHANGE = \033[0;35m
TAB = "\	"
FTAB = "\	\	"

OBJ		= $(addprefix $(OBJDIR),$(SRC:.c=.o))

CC		= gcc
CFLAGS	= -Wall -Wextra -Werror -g -O3

MLX		= ./miniLibX/
MLX_LIB	= $(addprefix $(MLX),mlx.a)
MLX_INC	= -I ./miniLibX
MLX_LNK	= -L ./miniLibX -l mlx -framework OpenGL -framework AppKit

FT		= ./libft/
FT_LIB	= $(addprefix $(FT),libft.a)
FT_INC	= -I ./libft/includes
FT_LNK	= -L ./libft -l ft

SRCDIR	= ./src/
INCDIR	= ./includes/
OBJDIR	= ./obj/

all: $(FT_LIB) $(MLX_LIB) $(NAME)

$(OBJDIR)%.o:$(SRCDIR)%.c
	@find . -type f -name "obj" -delete
	@mkdir -p obj/
	@echo "$(CHANGE)∰$(RESET)\c"
	@$(CC) $(CFLAGS) $(MLX_INC) $(FT_INC) -I $(INCDIR) -o $@ -c $<

$(FT_LIB):
	@make -C $(FT)

$(MLX_LIB):
	@make -C $(MLX)

$(NAME): $(OBJ)
	@echo "\n\n$(NAME):$(TAB)$(YELLOW)object files$(FTAB)$(GREEN)were created.$(RESET)"
	@$(CC) -framework OpenCL $(OBJ) $(MLX_LNK) $(FT_LNK) -lm -o $(NAME)
	@echo "$(NAME):$(TAB)$(YELLOW)$(NAME)$(FTAB)$(GREEN)was  created.$(RESET)"

tony: clean re

tony2:
	@rm -rf $(NAME)
	@echo "\n$(NAME):$(FAB)$(YELLOW)$(NAME)$(FTAB)$(RED)was  deleted.$(RESET)"
	@rm -rf $(OBJDIR)
	@find . -type f -name "obj" -delete
	@mkdir -p obj
	@rm -Rf obj
	@echo "$(NAME):$(TAB)$(YELLOW)object files$(FTAB)$(RED)were deleted.$(RESET)\n"
	@make

clean:
	@rm -rf $(OBJDIR)
	@find . -type f -name "obj" -delete
	@mkdir -p obj
	@rm -Rf obj
	@echo "$(NAME):$(TAB)$(YELLOW)object files$(FTAB)$(RED)were deleted.$(RESET)\n"
	@make -C $(FT) clean
	@make -C $(MLX) clean

fclean: clean
	@rm -rf $(NAME)
	@echo "\n$(NAME):$(TAB)$(YELLOW)$(NAME)$(FTAB)$(RED)was  deleted.$(RESET)\n"
	@make -C $(FT) fclean

re: fclean all

.PHONY: all clean fclean re