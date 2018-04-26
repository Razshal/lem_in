# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: abouvero <abouvero@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/11/08 11:15:51 by mfonteni          #+#    #+#              #
#    Updated: 2018/04/26 13:12:37 by abouvero         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = lem_in
SRC_PATH = src
SRC_NAME = get_list.c \
	   lem_in.c \
	   lem_lists.c \
	   lists.c \
	   searching.c \
	   lem_checks.c \
	   lists_init.c \
	   del_list.c \
	   debug.c \
	   paths.c \
	   moove_lem.c \
	   attr_lem.c
OBJ_NAME = $(SRC_NAME:.c=.o)
OBJ_PATH = obj
CPPFLAGS = -Iinclude
LIBFT = libft/libft.a
LIBDIR = libft
CC = gcc
CFLAGS = -Werror -Wall -Wextra -fsanitize=address -g3

INC_PATH = include
SRC = $(addprefix $(SRC_PATH)/,$(SRC_NAME))
OBJ = $(addprefix $(OBJ_PATH)/,$(OBJ_NAME))

.PHONY: all, clean, fclean, re

all: $(NAME)

$(NAME): $(LIBFT) $(OBJ)
	$(CC) $(CFLAGS) $^ -o $@

$(OBJ_PATH)/%.o: $(SRC_PATH)/%.c
	@mkdir $(OBJ_PATH) 2> /dev/null || true
	$(CC) $(CFLAGS) $(CPPFLAGS) -o $@ -c $< 

$(LIBFT):
	@make -C $(LIBDIR)

norme:
	norminette $(SRC)
	norminette $(INC_PATH)*.h

clean:
	@rm -fv $(OBJ)
	@rmdir $(OBJ_PATH) 2> /dev/null || true
	@make -C $(LIBDIR) clean

fclean: clean
	@rm -fv $(NAME)
	@make -C $(LIBDIR) fclean

re: fclean all
