# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: grocca <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/05/30 20:03:02 by grocca            #+#    #+#              #
#    Updated: 2026/05/30 20:29:14 by grocca           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= libftprintf.a
CC	= cc
CFLAGS	= -Wall -Wextra -Werror -I.

SRCS	=	ft_printf.c \
	ft_putchar_fd.c \
	ft_hexstr.c \
	ft_putnbr_fd.c \
	ft_putunsign_fd.c \
	ft_putpoint_fd.c \
	ft_putstr_fd.c \
	ft_toupper.c \
	ft_strlen.c

OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	ar rcs $(NAME) $(OBJS)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
