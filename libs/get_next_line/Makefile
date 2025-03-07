# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: joaomart <joaomart@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/02/25 11:46:33 by joaomart          #+#    #+#              #
#    Updated: 2025/02/25 12:09:22 by joaomart         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = get_next_line.a
CC = cc
CFLAGS = -Wall -Wextra -Werror

SOURCES = srcs/get_next_line.c srcs/get_next_line_utils.c
BONUS_SOURCES = bonus/get_next_line_bonus.c bonus/get_next_line_utils_bonus.c

OBJ = $(SOURCES:.c=.o)
BONUS_OBJ = $(BONUS_SOURCES:.c=.o)
RM = rm -f
AR = ar rcs

all: $(NAME)

$(NAME): $(OBJ)
	@$(AR) $(NAME) $(OBJ)

%.o: %.c
	@$(CC) $(CFLAGS) -c $< -o $@

bonus: $(NAME) $(BONUS_OBJ)
	@$(AR) $(NAME) $(BONUS_OBJ)

clean:
	@$(RM) $(OBJ) $(BONUS_OBJ)

fclean: clean
	@$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re bonus
