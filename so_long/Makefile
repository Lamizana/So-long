# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: alamizan <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/10 10:11:13 by alamizan          #+#    #+#              #
#    Updated: 2023/01/23 08:02:50 by alamizan         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #
NAME = so_long
NAME2 = solong_bonus

SRC = main.c\
	  ft_inits.c\
	  ft_parsing.c\
	  ft_parse_road.c\
	  ft_errors.c\
	  ft_display.c\
	  ft_move.c\
	  ft_event_move.c\
	  so_long_utils.c

BONUS = ./so_long_bonus/main_bonus.c\
		./so_long_bonus/so_long_utils_bonus.c\
		./so_long_bonus/ft_inits_bonus.c\
		./so_long_bonus/ft_parsing_bonus.c\
		./so_long_bonus/ft_parse_road_bonus.c\
		./so_long_bonus/ft_errors_bonus.c\
		./so_long_bonus/ft_display_bonus.c\
		./so_long_bonus/ft_move_bonus.c\
		./so_long_bonus/ft_handle_bonus.c\
		./so_long_bonus/ft_event_move_bonus.c

GNL = ./gnl/get_next_line.c\
	  ./gnl/get_next_line_utils.c

CFLAGS = -Wall -Werror -Wextra -g

%.o: %.c
	clang $(CFLAGS) -I/usr/include -Imlx_linux -c $< -o $@

OBJ = $(SRC:.c=.o)
OBJ_GNL = $(GNL:.c=.o)
OBJ_BONUS = $(BONUS:.c=.o)

all : $(NAME)

$(NAME): $(OBJ) $(OBJ_GNL) 
	clang $(CFLAGS) $(OBJ) $(OBJ_GNL) -Lmlx_linux mlx_linux/libmlx.a -lXext -lX11 -lm -lz -o $(NAME)

$(NAME2): $(OBJ_BONUS) $(OBJ_GNL)
	clang $(CFLAGS) $(OBJ_BONUS) $(OBJ_GNL) -Lmlx_linux mlx_linux/libmlx.a -lXext -lX11 -lm -lz -o $(NAME2)

clean:
	/bin/rm -f $(OBJ) $(OBJ_GNL) $(OBJ_BONUS)
fclean: clean
	/bin/rm -f $(NAME) $(NAME2)

re: fclean all

bonus: $(NAME2) 

.PHONY: all clean fclean re bonus
