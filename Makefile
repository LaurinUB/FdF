# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: luntiet- <luntiet-@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/28 17:07:30 by luntiet-          #+#    #+#              #
#    Updated: 2022/11/28 17:42:35 by luntiet-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

C = cc

CFLAGS = -Wall -Werror -Wextra

NAME = fdf

SRC = ./src/fdf.c \

OBJ = $(SRC:.c=.o)

LIBFT = ./libft/libft.a

all: $(NAME)

LSANLIB = /LeakSanitizer/liblsan.a
lsan: CFLAGS += -ILeakSanitizer -Wno-gnu-include-next
lsan: LINK_FLAGS += -LLeakSanitizer -llsan -lc++
lsan: fclean $(LSANLIB)
lsan: all

$(LSANLIB):
	@if [ ! -d "LeakSanitizer" ]; then git clone https://github.com/mhahnFr/LeakSanitizer.git; fi
	@$(MAKE) -C LeakSanitizer

$(NAME): $(LIBFT) $(OBJ)
	@$(CC) $(LINK_FLAGS) $(OBJ) $(LIBFT) -o $(NAME)

$(LIBFT):
	@git clone https://github.com/LaurinUB/libft
	@cd libft && make && make clean

clean:
	@rm -rf $(OBJ)

fclean: clean
	@rm -rf $(NAME)
	@rm -rf ./libft

re: fclean all

.PHONY: all clean fclean re
