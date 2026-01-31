# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: brouane <brouane@student.1337.ma>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/01/08 21:41:29 by brouane           #+#    #+#              #
#    Updated: 2026/01/31 21:49:07 by brouane          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC      = cc
CFLAGS  = -Wall -Wextra -Werror
RM      = rm -f

NAME    = push_swap

SRCS    = ft_atoi.c \
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

NAME_BONUS = checker

SRCS_BONUS = checker.c \
             error_checker.c \
             extended_functions.c \
             external_functions.c \
             freedom.c \
             ft_atoi.c \
             ft_lstadd_back.c \
             ft_print.c \
             internal_functions.c \
             push.c \
             rotate.c \
             reverse_rotate.c \
             swap.c \
             split_them.c \
             checker_utils.c \
             get_next_line.c \
             get_next_line_utils.c

OBJS_BONUS = $(SRCS_BONUS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

bonus: $(NAME_BONUS)

$(NAME_BONUS): $(OBJS_BONUS)
	$(CC) $(CFLAGS) $(OBJS_BONUS) -o $(NAME_BONUS)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJS) $(OBJS_BONUS)

fclean: clean
	$(RM) $(NAME) $(NAME_BONUS)

re: fclean all

re_bonus: fclean bonus

.PHONY: all clean fclean re bonus re_bonus
