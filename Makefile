# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: brouane <brouane@student.1337.ma>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/01/08 21:41:29 by brouane           #+#    #+#              #
#    Updated: 2026/01/20 18:45:31 by brouane          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME    = push_swap

CC      = cc
CFLAGS  = -Wall -Wextra -Werror
RM      = rm -f

SRCS	= ft_atoi.c \
		  error_checker.c \
		  extended_functions.c \
		  external_functions.c \
		  freedom.c \
		  ft_lstadd_back.c \
		  ft_print.c \
		  internal_functions.c \
		  operations_manager.c \
		  push.c \
		  push_back_to_a.c \
		  push_from_a.c \
		  push_to_b.c \
		  push_swap.c \
		  rotate.c \
		  reverse_rotate.c \
		  split_them.c \
		  swap.c \
		  three_sorter.c


OBJS    = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(OBJS)
# 	$(CC) $(OBJS) -o $(NAME)

%.o: %.c push_swap.h
	$(CC) -c $< -o $@

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
