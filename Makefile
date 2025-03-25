# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: danalvar <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/03/18 17:59:29 by danalvar          #+#    #+#              #
#    Updated: 2025/03/18 19:53:32 by danalvar         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Project name
NAME = push_swap

# Comiling rules
CC = cc
CFLAGS = -Wall -Wextra -Werror -g

# Libft files
LIBFT_DIR = ./libft
LIBFT = $(LIBFT_DIR)/libft.a

# SRC files
SRC_DIR = src/
SRCS = push_swap.c node.c parsing.c temp_utils.c utils.c operations.c stack.c
HEADER = push_swap.h
OBJS = $(addprefix $(SRC_DIR), $(SRCS:.c=.o))

# Make Rules
all: $(NAME)

$(LIBFT):
	make -C $(LIBFT_DIR)
	make -C $(LIBFT_DIR) bonus

$(NAME): $(OBJS) $(LIBFT) Makefile
	$(CC) $(CFLAGS) $(OBJS) -L$(LIBFT_DIR) -lft

clean: 
	make -C $(LIBFT_DIR) clean
	rm -f $(OBJS)

f fclean: clean
	make -C $(LIBFT_DIR) fclean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
