#**************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mfonteni <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/11/08 11:15:51 by mfonteni          #+#    #+#              #
#    Updated: 2018/03/13 18:42:55 by mfonteni         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = lem_in
SRC_PATH = src
SRCS = get_list.c \
	   lem_in.c \
	   lem_lists.c \
	   lists.c \
	   searching.c
OBJ_PATH = obj
CPPFLAGS = -Iinclude
LIBFT = libft/libft.a
CC = clang
CFLAGS = -Werror -Wall -Wextra
OBJ_NAME = $(SRC_NAME:.c=.o)
SRC = $(addprefix $(SRC_PATH)/,$(SRC_NAME))
OBJ = $(addprefix $(OBJ_PATH)/,$(OBJ_NAME))

.PHONY: all, clean, fclean, re

all: $(NAME)

$(NAME): $(LIBFT) $(OBJ)
	$(CC) $(LIBFT) $^ -o $@

$(OBJ_PATH)%.o: $(SRC_PATH)%.c
	@mkdir $(OBJ_PATH) 2> /dev/null || true
	$(CC) $(CFLAGS) $(CPPFLAGS) -o $@ -c $<

$(LIBFT):
	make -C libft/

norme:
	norminette $(SRC)
	norminette $(INC_PATH)*.h

clean:
	@rm -fv $(OBJ)
	@rmdir $(OBJ_PATH) 2> /dev/null || true
	@make -C libft/ clean

fclean: clean
	rm -fv $(NAME)
	@make -C libft/ fclean

re: fclean all
