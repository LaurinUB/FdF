# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: luntiet- <luntiet-@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/28 17:07:30 by luntiet-          #+#    #+#              #
#    Updated: 2022/12/20 10:17:10 by luntiet-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = -Wall -Werror -Wextra
MLXFLAGS = -lglfw -L "$(HOME)/.brew/opt/glfw/lib"
NAME = fdf
SRC_DIR = src
OBJ_DIR = obj
DIR_DUP = mkdir -p $(@D)

SRC = fdf.c \
		init.c \
		draw.c \
		utils.c \
		free_utils.c \
		controls.c \
		key_hooks.c \
		mouse_hooks.c \
		rotate.c \
		projection.c \
		color.c

SRC := $(SRC:%=$(SRC_DIR)/%)
OBJ = $(SRC:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)
LIBFT = ./libft/libft.a
MLX42 = ./MLX42/libmlx42.a

all: $(NAME)

LSANLIB = /LeakSanitizer/liblsan.a
lsan: CFLAGS += -ILeakSanitizer -Wno-gnu-include-next
lsan: LINK_FLAGS += -LLeakSanitizer -llsan -lc++
lsan: fclean $(LSANLIB)
lsan: all

$(LSANLIB):
	@if [ ! -d "LeakSanitizer" ]; then git clone https://github.com/mhahnFr/LeakSanitizer.git; fi
	@$(MAKE) -C LeakSanitizer

$(NAME): $(LIBFT) $(MLX42) $(OBJ)
	@$(CC) $(LINK_FLAGS) $(OBJ) $(MLX42) $(LIBFT) -o $(NAME) $(MLXFLAGS)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	$(DIR_DUP)
	$(CC) $(CFLAGS) -c -o $@ $<

$(LIBFT):
	@if [ ! -d "libft" ]; then git clone https://github.com/LaurinUB/libft; fi
	@cd libft && make && make clean

$(MLX42):
	@if [ ! -d "MLX42" ]; then git clone https://github.com/codam-coding-college/MLX42.git; fi
	@cd MLX42 && make

clean:
	@rm -rf $(OBJ)

fclean: clean
	@rm -rf $(NAME)

libclean:
	@rm -rf ./libft
	@rm -rf ./MLX42
re: fclean all

.PHONY: all clean fclean re
