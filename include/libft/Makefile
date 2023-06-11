# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dcordoba <dcordoba@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/01 23:22:51 by dcordoba          #+#    #+#              #
#    Updated: 2023/06/11 18:57:40 by dcordoba         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME := libft.a
NAME_BONUS = .bonus

#----------------------#
#      BUILD VARS      #
#----------------------#
# SRC_DIR     src directory c files
# BUILD_DIR   build directory
# INC_DIR        header file locations
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
INC_DIR := include/
SRCS := ft_isalpha.c ft_isascii.c ft_isdigit.c ft_isprint.c ft_isalnum.c \
		ft_strlen.c ft_strlcpy.c ft_strncmp.c ft_strlcat.c ft_strchr.c ft_strrchr.c \
		ft_strnstr.c ft_tolower.c ft_toupper.c ft_atoi.c ft_memset.c \
		ft_bzero.c ft_memcpy.c ft_memmove.c ft_memchr.c ft_memcmp.c ft_calloc.c \
		ft_strdup.c ft_substr.c ft_strjoin.c ft_strtrim.c ft_split.c ft_itoa.c \
		ft_strmapi.c ft_striteri.c ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c \
		ft_putnbr_fd.c
SRCS := $(SRCS:%=$(SRC_DIR)%)
OBJECTS := $(SRCS:$(SRC_DIR)%.c=$(BUILD_DIR)%.o)
DEPS := $(OBJECTS:.o=.d)
BONUS := ft_lstnew_bonus.c ft_lstadd_front_bonus.c ft_lstsize_bonus.c ft_lstlast_bonus.c \
		ft_lstadd_back_bonus.c ft_lstdelone_bonus.c ft_lstclear_bonus.c ft_lstiter_bonus.c ft_lstmap_bonus.c
BONUS := $(BONUS:%=$(SRC_DIR)%)
BONUS_OBJ := $(BONUS:$(SRC_DIR)%.c=$(BUILD_DIR)%.o)
DEPS_BONUS := $(BONUS_OBJ:.o=.d)
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

#----------------------------------------------#
#                  BUILD RULES                 #
#----------------------------------------------#
# all       default goal
# $(NAME)   linking .o -> binary
# %.o       compilation .c -> .o
# bonus     bonus goal
# clean     remove .o
# fclean    remove .o + binary
# re        remake default goal
# rebonus   remake bonus goal
# .PHONY	
# $@ expands to the target name
# $< expands to the first dependency
# $^ expands to the complete list of dependencies

all: $(NAME)

$(NAME): $(OBJECTS)
	@ar rcs $(NAME) $(OBJECTS)
	$(info 🗃️ Packing $(NAME) done!)
	
$(BUILD_DIR)%.o: $(SRC_DIR)%.c
	@$(DIR_DUP)
	@$(CC) $(CFLAGS) $(CPPFLAGS) -c -o $@ $<
	$(info Compile 📂 $(notdir $<) -> $(notdir $@))
-include $(DEPS) 

bonus: $(NAME_BONUS)

$(NAME_BONUS): $(BONUS_OBJ) $(OBJECTS)
	@ar rcs $(NAME) $^
	$(info 🗃️ Packing $(NAME) done!)
	@touch .bonus
-include $(DEPS_BONUS)

clean:
	@$(RMF) $(BUILD_DIR)
	$(info 🧹 Object files from $(NAME) deleted sucesfully!)
	
fclean: clean
	@$(RM) $(NAME) $(NAME_BONUS)
	$(info 🧹 Library file $(NAME) deleted succesfully!)
	
re: fclean all

rebonus: fclean bonus

.PHONY: all clean fclean re rebonus
