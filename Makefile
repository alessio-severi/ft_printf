# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aseveri <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/05/13 00:01:23 by aseveri           #+#    #+#              #
#    Updated: 2026/05/13 01:13:20 by aseveri          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	  = libftprintf.a

SRC		  = src/ft_printf.c \
			src/ft_printf_utils.c \
			src/ft_print_number.c \
			src/ft_print_text.c

OBJ		   = $(SRC:.c=.o)
CC		   = cc
CFLAGS	   = -Wall -Wextra -Werror -I includes
RM		   = rm -f

all: $(NAME)

$(NAME): $(OBJ)
	ar rcs $(NAME) $(OBJ)

src/%.o: src/%.c includes/ft_printf.h
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	${RM} $(OBJ)

fclean: clean
	${RM} $(NAME)

re: fclean all

.PHONY: all clean fclean re
