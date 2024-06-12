# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tbezerra <tbezerra@student.42porto.com>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/05/27 14:05:29 by tbezerra          #+#    #+#              #
#    Updated: 2024/06/12 18:53:26 by tbezerra         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
HEADER = ./
MAKE = make -C
CC = cc
LIBFT = ./libft/libft.a
CFLAGS = -Wall -Werror -Wextra

SRCS = main.c t_stack.c command.c utis.c command_a.c command_b.c command_ab.c\
		big_sort.c

OBJS = ${SRCS:.c=.o}

all: $(NAME)

$(LIBFT):
	$(MAKE) ./libft

$(NAME): $(OBJS) $(LIBFT)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS) $(LIBFT)

%.o: %.c
	$(CC) $(CFLAGS) -I$(HEADER) -c $(SRCS)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean $(NAME)
