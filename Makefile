# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jjaniec <jjaniec@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/04/18 17:27:33 by jjaniec           #+#    #+#              #
#    Updated: 2018/04/26 20:42:57 by jjaniec          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ft_select

UNAME_S := $(shell uname -s)

SRC_NAME = analyze_key.c \
		   create_args_sorted_list.c \
		   create_ft_select_struct.c \
		   free_args_list.c \
		   get_printing_width.c \
		   get_term_size.c \
		   handle_key_action.c \
		   is_key.c \
		   print_args.c \
		   save_restore_term_settings.c \
		   sig_management.c \
		   update_term.c \
		   cursor_movement.c \
		   parse_options.c \
		   create_args_list.c \
		   print_arg_color.c \
		   print_escape_msg.c \
		   main.c

INCLUDES_NAME = ft_select.h

SRC_DIR = ./srcs/
INCLUDES_DIR = ./includes/
OBJ_DIR = ./objs/

SRC = $(addprefix $(SRC_DIR), $(SRC_NAME))
OBJ = $(addprefix $(OBJ_DIR), $(SRC_NAME:.c=.o))

CC = gcc
CFLAGS = -Wall -Wextra -Werror
#DEV_FLAGS = -fsanitize=address -fno-omit-frame-pointer
IFLAGS = -I./ft_printf/includes -I./$(INCLUDES_DIR)
LFLAGS = -L./ft_printf -lftprintf -ltermcap

CFLAGS += $(DEV_FLAGS)
FT_PRINTF_DIR = ./ft_printf
LIBFT_PRINTF = $(addprefix $(FT_PRINTF_DIR),"/libftprintf.a")

UNAME_S := $(shell uname -s)

define ui_line
	$(MAKEFILE_STATUS) $(1) $(2) || true
endef

all : $(NAME)

$(NAME) : $(LIBFT_PRINTF) $(OBJ)
ifeq ($(UNAME_S),Linux)
	$(CC) $(CFLAGS) $(LFLAGS) $(OBJ) $(LIBFT_PRINTF) -o $(NAME)
endif
ifeq ($(UNAME_S),Darwin)
	$(CC) $(CFLAGS) $(LFLAGS) $(OBJ) -o $(NAME)
endif

$(OBJ_DIR)%.o : $(SRC_DIR)%.c $(addprefix $(INCLUDES_DIR), $(INCLUDES_NAME))
	@mkdir -p $(OBJ_DIR)
	gcc $(CFLAGS) -c $(IFLAGS) $< -o $@

$(FT_PRINTF_DIR):
	git clone https://github.com/Gamouche/ft_printf || true

$(LIBFT_PRINTF): $(FT_PRINTF_DIR)
	make -C $(FT_PRINTF_DIR)

clean:
	@rm -rf $(OBJ_DIR)
	@make clean -C $(FT_PRINTF_DIR)

fclean: clean
	@rm -f $(NAME)
	@make fclean -C $(FT_PRINTF_DIR)

re: fclean all

.PHONY: clean fclean all re
