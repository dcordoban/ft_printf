# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: david <david@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/28 21:32:00 by dcordoba          #+#    #+#              #
#    Updated: 2023/06/01 12:59:49 by david            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NC = \033[39m
AZUL = \033[36m
ROJO = \033[31m
MAGENTA = \033[35m

CC = cc
NAME = tests.out
SRCS = ft_printf.h ft_printf.c ft_print_char.c ft_prints.c \
	ft_print_u.c ft_printnb.c ft_print_hex.c
CFLAG = -Wall -Werror -Wextra
DEPS = ft_printf.h
OBJECTS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME):
	@$(CC) $(CFLAGS) $(SRCS) -o $(NAME)
	@echo "$(AZUL)Compilando 📂$(NC) $(SRCS)"
	@echo chmod +x $(NAME)
	@echo "$(MAGENTA)Ejecutable ✅$(NC) $(NAME)"


clean:
	@/bin/rm -f $(NAME)
	@echo "$(ROJO)Borrando ejecutable...🧹$(NC)\n$(NAME)\n"

fclean: clean
	@/bin/rm -f $(NAME)
	@echo "$(ROJO)Borrando ejecutable...🧹$(NC)\n$(NAME)\n"

re: fclean all

.PHONY: all clean fclean re
