# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nmattera <nmattera@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/07/07 10:42:54 by nmattera          #+#    #+#              #
#    Updated: 2022/08/04 16:22:17 by nmattera         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# name
NAME		=	fractol

# compiler
CC			=	gcc
CFLAGS		=	-Wall -Wextra -Werror -g

# mlx
MLX_PATH	=	mlx/
MLX_NAME	=	libmlx.a
MLX			=	$(MLX_PATH)$(MLX_NAME)

# libft
LIBFT_PATH	= libft/
LIBFT_NAME	= libft.a
LIBFT		= $(LIBFT_PATH)$(LIBFT_NAME)

# includes
INCLUDES	=	-I ./mlx/\
				-I ./libft/\
				-I ./includes/

# programmes
SRC_PATH 	=	src/
SRC			=	fractol.c fractol_utils.c fractol_event.c fractol_init.c fractol_data.c fractol_calc.c fractol_exit.c fractol_color.c fractol_message.c
SRCS		=	$(addprefix $(SRC_PATH), $(SRC))

# executables
OBJ_PATH	=	obj/
OBJ			=	$(SRC:.c=.o)
OBJS 		=	$(addprefix $(OBJ_PATH), $(OBJ))

all: $(MLX) $(LIBFT) $(NAME)

$(OBJ_PATH)%.o: $(SRC_PATH)%.c
	@$(CC) -c $< -o $@ $(INCLUDES)

$(OBJS): $(OBJ_PATH)

$(OBJ_PATH):
	@mkdir $(OBJ_PATH)

$(MLX):
	@echo "MlX..."
	@make -sC $(MLX_PATH)

$(LIBFT):
	@echo "libft..."
	@make -sC $(LIBFT_PATH)

${NAME}: ${OBJS}
	@echo "Fractol..."
	@$(CC) $(CFLAGS) -o $(NAME) $(OBJS) $(MLX) $(LIBFT) $(INCLUDES) -lXext -lX11 -lm 
	@echo "Fractol Compiled!"

clean:
	@echo ".o files removed"
	@rm -rf $(OBJ_PATH)
	@make clean -C $(MLX_PATH)
	@make clean -C $(LIBFT_PATH)

fclean: clean
	@echo "fractol removed"
	@rm -f $(NAME)
	@rm -f $(LIBFT_PATH)$(LIBFT_NAME)
	@echo "Deleting EVERYTHING!\n"

re: fclean all

.PHONY: all clean fclean re
