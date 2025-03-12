# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jaizpuru <jaizpuru@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/27 16:36:18 by jaizpuru          #+#    #+#              #
#    Updated: 2022/11/28 18:53:22 by jaizpuru         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME = fractol

MLIB = libmlx.a

LIBFT_LIB = libft.a

PRINTF_LIB = libftprintf.a

LIBFT_DIR = libft/

LIB_DIR = miniLibX/

PRINTF_DIR = ft_printf/

C_DIR = .

RM = rm

MV = mv

RM_FLAGS = -rf

UTILS2 = -g3 -v

CC = cc

UTILS = julia.c \
	image.c \
	keys.c \
	mandelbrot.c \
	main.c
	
OBJS = $(UTILS:.c=.o)

FLAGS = -Wall -Wextra -Werror


all: $(NAME)

$(OBJS): $(UTILS)
	$(CC) $(FLAGS) -c $^

$(NAME): $(OBJS) $(LIB_DIR) $(LIBFT_DIR) $(PRINTF_DIR)
	make -C $(LIB_DIR) all
	make -C $(LIBFT_DIR) all
	make -C $(PRINTF_DIR) all
	$(MV) $(LIB_DIR)$(MLIB) $(C_DIR)
	$(MV) $(LIBFT_DIR)$(LIBFT_LIB) $(C_DIR)
	$(MV) $(PRINTF_DIR)$(PRINTF_LIB) $(C_DIR)
	$(CC) $(FLAGS) $(LIBFT_LIB) $(PRINTF_LIB) $(MLIB) -L . -lmlx -framework OpenGL -framework AppKit -o $(NAME) $(OBJS)

clean:
	make -C $(LIB_DIR) clean
	make -C $(LIBFT_DIR) clean
	make -C $(PRINTF_DIR) clean
	$(RM) $(RM_FLAGS) $(MLIB)
	$(RM) $(RM_FLAGS) $(PRINTF_LIB)
	$(RM) $(RM_FLAGS) $(LIBFT_LIB)
	$(RM) $(RM_FLAGS) $(OBJS)

fclean: clean
	$(RM) $(RM_FLAGS) $(NAME)

re: fclean all

.PHONY : all clean fclean re
