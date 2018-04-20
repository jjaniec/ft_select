# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jjaniec <jjaniec@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/04/18 17:27:33 by jjaniec           #+#    #+#              #
#    Updated: 2018/04/20 17:12:07 by jjaniec          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ft_select

UNAME_S := $(shell uname -s)

SRC_NAME = init_term_and_settings.c \
		   tools.c \
		   get_term_size.c \
		   main.c

INCLUDES_NAME = ft_select.h

SRC_DIR = ./srcs/
INCLUDES_DIR = ./includes/
OBJ_DIR = ./objs/

SRC = $(addprefix $(SRC_DIR), $(SRC_NAME))
OBJ = $(addprefix $(OBJ_DIR), $(SRC_NAME:.c=.o))

CC = gcc
CFLAGS = -Wall -Wextra -g #-Werror
#DEV_FLAGS = -fsanitize=address -fno-omit-frame-pointer
IFLAGS = -I./libft -I./$(INCLUDES_DIR)
LFLAGS = -L./libft -lft -ltermcap

CFLAGS += $(DEV_FLAGS)
LIBFT_DIR = ./libft
LIBFT = $(addprefix $(LIBFT_DIR),"/libft.a")

MAKEFILE_STATUS = $(addprefix $(LIBFT_DIR),"/.makefile_status")

UNAME_S := $(shell uname -s)

define ui_line
	$(MAKEFILE_STATUS) $(1) $(2) || true
endef

all : $(NAME)

$(NAME) : $(LIBFT) $(OBJ)
ifeq ($(UNAME_S),Linux)
	@$(CC) $(CFLAGS) $(LFLAGS) $(OBJ) $(LIBFT) -o $(NAME)
endif
ifeq ($(UNAME_S),Darwin)
	@$(CC) $(CFLAGS) $(LFLAGS) $(OBJ) -o $(NAME)
endif

$(OBJ_DIR)%.o : $(SRC_DIR)%.c $(addprefix $(INCLUDES_DIR), $(INCLUDES_NAME))
	@mkdir -p $(OBJ_DIR)
	@gcc $(CFLAGS) -c $(IFLAGS) $< -o $@ && $(call ui_line, $@, $(NAME))

$(LIBFT_DIR):
	git clone https://github.com/jjaniec/libft || true

$(LIBFT): $(LIBFT_DIR)
	make -C libft

clean:
	@rm -rf $(OBJ_DIR)
	@make clean -C $(LIBFT_DIR)

fclean: clean
	@rm -f $(NAME)
	@make fclean -C $(LIBFT_DIR)

re: fclean all

.PHONY: clean fclean all re
