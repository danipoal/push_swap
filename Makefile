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
NAME = push_swap.out

# Compiling rules
CC = cc
CFLAGS = -Wall -Wextra -Werror -g

# Libft files
LIBFT_DIR = ./libft
LIBFT = $(LIBFT_DIR)/libft.a

# SRC files
SRC_DIR = src/
SRCS = push_swap.c node.c parsing.c temp_utils.c utils.c operations.c stack.c swap.c push.c rotate.c reverse_rotate.c short_cases.c radix.c radix_utils.c timsort.c timsort_utils.c timsort_moves_exec.c timsort_moves_proc.c
HEADER = push_swap.h
OBJS = $(addprefix $(SRC_DIR), $(SRCS:.c=.o))

# Make Rules
all: $(NAME)

$(LIBFT):
	@echo "[*] Compiling Libft..."
	@make -C $(LIBFT_DIR) > /dev/null
	@echo "[✓] Libft compiled."

$(NAME): $(OBJS) $(LIBFT) Makefile
	@echo "[*] Compiling $(NAME)..."
	@$(CC) $(CFLAGS) $(OBJS) -L$(LIBFT_DIR) -lft -o $(NAME) > /dev/null
	@echo "[✓] Compilation of $(NAME) completed."

clean: 
	@echo "[-] Cleaning object files..."
	@make -C $(LIBFT_DIR) clean > /dev/null
	@rm -f $(OBJS)
	@echo "[✓] Cleanup done."

f fclean: clean
	@echo "[-] Removing executable..."
	@make -C $(LIBFT_DIR) fclean > /dev/null
	@rm -f $(NAME)
	@echo "[✓] Executable removed."

re: fclean all

.PHONY: all clean fclean re f
