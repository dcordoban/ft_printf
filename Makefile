# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dcordoba <dcordoba@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/28 21:32:00 by dcordoba          #+#    #+#              #
#    Updated: 2023/06/04 11:50:56 by dcordoba         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NC = \033[39m
AZUL = \033[36m
ROJO = \033[31m
MAGENTA = \033[35m

CC = cc
NAME = libftprintf.a
SRCS = ft_printf.c ft_print_char.c ft_prints.c \
		ft_print_u.c ft_printnb.c ft_print_hex.c ft_print_p.c
CFLAG = -Wall -Werror -Wextra
DEPS = ft_printf.h
OBJECTS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME):$(OBJECTS)
	@echo "$(MAGENTA)Linkeando 🔗\n $(NC)$^\n"
	@ar rc $(NAME) $^

%.o: %.c $(DEPS)
	@$(CC) $(CFLAGS) -c $< -o $@
	@echo "$(AZUL)Compilando 📂$(NC) $< -> $@"

clean:
	@/bin/rm -f $(OBJECTS)
	@echo "$(ROJO)Borrando objetos...🧹$(NC)\n$(OBJECTS)\n"

fclean: clean
	@/bin/rm -f $(NAME)
	@echo "$(ROJO)Borrando libreria...🧹$(NC)\n$(NAME)\n"

re: fclean all

.PHONY: all clean fclean re
