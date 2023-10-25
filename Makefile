# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: juandrie <juandrie@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/07/24 18:34:33 by julietteand       #+#    #+#              #
#    Updated: 2023/10/24 14:43:09 by juandrie         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Compiler and flags
CC = cc
CFLAGS = -Wall -Werror -Wextra -g3

# Directories
SRC_DIR = src/
OBJ_DIR = obj/
INC_DIR = includes/
MLX_DIR = minilibx-linux/
LIBFT_DIR = Libft/

# Nom du programme
NAME = so_long

# Source files
SRC = controls.c\
					errors.c\
					graphics.c\
					map.c\
					so_long.c\
					clean.c\
					move.c\
					walls.c\
					place_graphics.c\
					utils.c\
					flood_fill.c\

# Chemins complets
OBJ = $(addprefix $(OBJ_DIR), $(SRC:.c=.o))

LIBFT = $(LIBFT_DIR)/libft.a

# Inclusion des bibliothèques et des headers
MLX = $(MLX_DIR)/libmlx_Linux.a
FRAMEWORKS = -lXext -lX11 -lm

all: $(NAME)

$(NAME): $(LIBFT) $(OBJ)
	make -C $(MLX_DIR)
	$(CC) $(CFLAGS) $(OBJ) -L./$(LIBFT_DIR) -L./minilibx-linux -lft -lmlx -o $(NAME) $(FRAMEWORKS) -I/$(INC_DIR)

$(OBJ_DIR)%.o: $(SRC_DIR)%.c
	@mkdir -p $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@ -I./$(INC_DIR) -I./minilibx-linux

$(LIBFT):
	$(MAKE) -C $(LIBFT_DIR)

$(MLX):
	$(MAKE) -C $(MLX_DIR)

clean:
	rm -rf $(OBJ_DIR)
	$(MAKE) -C $(MLX_DIR) clean
	$(MAKE) -C $(LIBFT_DIR) fclean

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
