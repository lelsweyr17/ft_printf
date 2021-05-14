# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lelsweyr <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/12/01 18:59:41 by lelsweyr          #+#    #+#              #
#    Updated: 2020/12/01 18:59:42 by lelsweyr         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a
COMP = gcc -Wall -Wextra -Werror
INCL = parcer.h processing.h
FALES_C = parcer.c processing.c ft_itoa.c ft_strlen.c ft_printf.c int_cases.c \
	int_cases2.c parcer2.c ft_utoa.c processing_u_x_percent.c processing_p.c \
	processing_p2.c ft_bzero.c processing_char_str.c processing_char_str2.c

OBJ_C = $(FALES_C:.c=.o)

all: $(NAME)

$(NAME): $(OBJ_C)
	ar rc $(NAME) $(OBJ_C) $(INCL)

clean:
	rm -rf $(OBJ_C)

fclean: clean
	rm -rf $(NAME)

re: fclean all

main: re
	gcc main.c $(NAME)
	./a.out

.PHONY: all clean fclean re