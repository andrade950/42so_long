# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: andrade <andrade@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/02/19 10:39:28 by joaomart          #+#    #+#              #
#    Updated: 2025/03/07 17:35:16 by andrade          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long
CC = cc
FLAGS = -Wall -Wextra -Werror -g
MLXFLAGS = -I$(MINILIBX_DIR) -L$(MINILIBX_DIR) -lmlx -lXext -lX11

# Libft , ft_printf e get_next_line #
LIBFT_DIR = libs/libft
FT_PRINTF_DIR = libs/ft_printf
GNL_DIR = libs/get_next_line
LIBFT = $(LIBFT_DIR)/libft.a
FT_PRINTF = $(FT_PRINTF_DIR)/libftprintf.a
GNL = $(GNL_DIR)/get_next_line.a

# minilibx-linux #
MINILIBX_DIR = libs/minilibx-linux
MINILIBX = $(MINILIBX_DIR)/libmlx.a

# so_long #
SO_LONG_SRCS = srcs/so_long.c srcs/args_checker.c srcs/error.c srcs/validate_map.c \
				srcs/init_map.c srcs/elements_map.c srcs/init_game.c
SO_LONG_OBJ_DIR = srcs/objs
SO_LONG_OBJS = $(patsubst srcs/%.c, $(SO_LONG_OBJ_DIR)/%.o, $(SO_LONG_SRCS))

all: $(NAME)

$(NAME): $(SO_LONG_OBJS) $(LIBFT) $(FT_PRINTF) $(GNL) $(MINILIBX)
	@echo "$(BOLD_BLUE)╔══════════════════════════════════════╗"
	@echo "$(BOLD_BLUE)║       🔨 Building $(NAME)...         ║"
	@echo "$(BOLD_BLUE)╚══════════════════════════════════════╝$(RESET)"
	@$(CC) $(FLAGS) $(SO_LONG_OBJS) $(LIBFT) $(FT_PRINTF) $(GNL) $(MINILIBX) $(MLXFLAGS) -lm -o $(NAME)
	@echo "$(BOLD_GREEN)✅ $(NAME) built successfully!$(RESET)"

$(SO_LONG_OBJ_DIR)/%.o: srcs/%.c
	@mkdir -p $(SO_LONG_OBJ_DIR)
	@echo "$(YELLOW)🛠️  Compiling $<...$(RESET)"
	@$(CC) $(FLAGS) -c $< -o $@

$(LIBFT):
	@echo "$(BOLD_BLUE)╔══════════════════════════════════════╗"
	@echo "$(BOLD_BLUE)║        📚 Compiling libft...         ║"
	@echo "$(BOLD_BLUE)╚══════════════════════════════════════╝$(RESET)"
	@$(MAKE) -C $(LIBFT_DIR) --no-print-directory
	@echo "$(BOLD_GREEN)✅ libft.a built successfully!$(RESET)"

$(FT_PRINTF):
	@echo "$(BOLD_BLUE)╔══════════════════════════════════════╗"
	@echo "$(BOLD_BLUE)║      🖨️  Compiling ft_printf...       ║"
	@echo "$(BOLD_BLUE)╚══════════════════════════════════════╝$(RESET)"
	@$(MAKE) -C $(FT_PRINTF_DIR) --no-print-directory
	@echo "$(BOLD_GREEN)✅ libftprintf.a built successfully!$(RESET)"

$(GNL):
	@echo "$(BOLD_BLUE)╔══════════════════════════════════════╗"
	@echo "$(BOLD_BLUE)║     📄 Compiling get_next_line...    ║"
	@echo "$(BOLD_BLUE)╚══════════════════════════════════════╝$(RESET)"
	@$(MAKE) -C $(GNL_DIR) --no-print-directory
	@echo "$(BOLD_GREEN)✅ get_next_line.a built successfully!$(RESET)"

$(MINILIBX):
	@echo "$(BOLD_BLUE)╔══════════════════════════════════════╗"
	@echo "$(BOLD_BLUE)║    🐧 Compiling minilibx-linux...    ║"
	@echo "$(BOLD_BLUE)╚══════════════════════════════════════╝$(RESET)"
	@$(MAKE) -C $(MINILIBX_DIR) all --silent
	@echo "$(BOLD_GREEN)✅ libmlx.a built successfully!$(RESET)"

clean:
	@echo "$(BOLD_BLUE)╔══════════════════════════════════════╗"
	@echo "$(BOLD_BLUE)║     🧹 Cleaning object files...      ║"
	@echo "$(BOLD_BLUE)╚══════════════════════════════════════╝$(RESET)"
	@rm -rf $(SO_LONG_OBJ_DIR)
	@$(MAKE) -C $(LIBFT_DIR) clean --no-print-directory
	@$(MAKE) -C $(FT_PRINTF_DIR) clean --no-print-directory
	@$(MAKE) -C $(GNL_DIR) clean --no-print-directory
	@echo "$(BOLD_GREEN)✅ Object files cleaned.$(RESET)"

fclean: clean
	@echo "$(BOLD_BLUE)╔══════════════════════════════════════╗"
	@echo "$(BOLD_BLUE)║        🗑️  Removing $(NAME)...        ║"
	@echo "$(BOLD_BLUE)╚══════════════════════════════════════╝$(RESET)"
	@rm -f $(NAME)
	@$(MAKE) -C $(LIBFT_DIR) fclean --no-print-directory
	@$(MAKE) -C $(FT_PRINTF_DIR) fclean --no-print-directory
	@$(MAKE) -C $(GNL_DIR) fclean --no-print-directory
	@$(MAKE) -C $(MINILIBX_DIR) clean --silent
	@echo "$(BOLD_GREEN)✅ Full clean completed.$(RESET)"

re: fclean all

.PHONY: all clean fclean re

# Cores #
GREEN = \033[0;32m
YELLOW = \033[0;33m
BLUE = \033[0;34m
BOLD_GREEN = \033[1;32m
BOLD_YELLOW = \033[1;33m
BOLD_BLUE = \033[1;34m
RESET = \033[0m
