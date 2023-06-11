# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dcordoba <dcordoba@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/01 23:22:51 by dcordoba          #+#    #+#              #
#    Updated: 2023/06/11 18:56:53 by dcordoba         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME := libftprintf.a
LIBFT_NAME := libft.a


#----------------------#
#      BUILD VARS      #
#----------------------#
# SRC_DIR     src directory c files
# BUILD_DIR   build directory
# INC_DIR     header file locations
#
# SRCS        source files
# OBJECTS     object files
# DEPS        dependency files
# BONUS       source files for bonus
# BONUS_OBJ   bonus object files
# DEPS_BONUS  bonus dependency files
#
# CC          compiler
# CFLAGS      compiler flags
# CPPFLAGS    preprocessor flags
SRC_DIR := src/
BUILD_DIR := .build/
INC_DIR := include/ \
	include/libft/include
LIBFT_DIR := include/libft/
LIBFT_NAME := $(LIBFT_NAME:%=$(LIBFT_DIR)%)
SRCS := ft_printf.c ft_print_char.c ft_prints.c \
		ft_print_u.c ft_printnb.c ft_print_hex.c ft_print_p.c
SRCS := $(SRCS:%=$(SRC_DIR)%)
OBJECTS := $(SRCS:$(SRC_DIR)%.c=$(BUILD_DIR)%.o)
DEPS := $(OBJECTS:.o=.d)
CC := cc
CFLAGS := -Wall -Werror -Wextra
CPPFLAGS := $(addprefix -I,$(INC_DIR)) -MMD -MP

#----------------------------------------------#
#                  SHELL CMD                   #
#----------------------------------------------#
# RM        			force remove files
# DIR_DUP   			duplicate directory tree
# RMF					force remove files + dir
RM := rm -f
RMF := rm -rf
DIR_DUP = mkdir -p $(@D)
MAKEFLAGS += --no-print-directory
NC = \033[39m
AZUL = \033[36m

#----------------------------------------------#
#                  BUILD RULES                 #
#----------------------------------------------#
# all             default goal
# callforstatus   make all goals checking status
# $(NAME)         linking .o -> binary
# %.o             compilation .c -> .o
# clean           remove .o
# fclean          remove .o + binary
# re              remake default goal
# .PHONY	
# $@ expands to the target name
# $< expands to the first dependency
# $^ expands to the complete list of dependencies

all: $(NAME) callforstatus

$(NAME): $(OBJECTS) $(LIBFT_NAME)
	@cp $(LIBFT_NAME) $(dir $(NAME))
	@ar crs $(NAME) $(OBJECTS)
	$(info 🗃️ Packing $(NAME) done!)
-include $(DEPS)

$(LIBFT_NAME):
	@$(MAKE) bonus -C $(LIBFT_DIR)
-include $(DEPS)
	
$(BUILD_DIR)%.o: $(SRC_DIR)%.c
	@$(DIR_DUP)
	@$(CC) $(CFLAGS) $(CPPFLAGS) -c -o $@ $<
	@echo "$(AZUL)Compile 📂$(NC) $(notdir $<) -> $(notdir $@)"

clean:
	$(RMF) $(BUILD_DIR)
	make fclean -C $(LIBFT_DIR)
	$(info 🧹 Object files from $(NAME) deleted sucesfully!)
	
fclean: clean
	$(RM) *.a
	$(info 🧹 Library files $(NAME) && $(notdir $(LIBFT_NAME)) removed succesfully!)
	
re: fclean all

callforstatus:
	@$(MAKE) bonus -C $(LIBFT_DIR) --silent
	@$(MAKE) -C . $(NAME) --silent

.PHONY: all clean fclean re
.SILENT: clean fclean
