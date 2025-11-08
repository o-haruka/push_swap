# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: homura <homura@student.42tokyo.jp>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/11/08 17:49:33 by homura            #+#    #+#              #
#    Updated: 2025/11/08 17:49:35 by homura           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= push_swap

CC			= cc
CFLAGS		= -Wall -Werror -Wextra -g

SRC_PATH	= srcs
SRC			= main.c \
			operations.c \
			error.c \
			free.c \
			stack_utils.c \
			parse.c \
			sort_utils.c \
			radix_sort.c \


SRCS		= $(addprefix $(SRC_PATH)/, $(SRC))

OBJ_PATH	= obj
OBJ 		= $(SRC:.c=.o)
OBJS		= $(addprefix $(OBJ_PATH)/, $(OBJ))

INC_PATH	= includes
INC			= push_swap.h
INCS		= $(addprefix $(INC_PATH)/, $(INC))

LIB_PATH	= libft
LIB			= libft.a
LIBS		= $(addprefix $(LIB_PATH)/, $(LIB))

RM			= rm -f

all : $(NAME)

$(NAME) : $(OBJS)
	@ make -C $(LIB_PATH)
	@ $(CC) $(CFLAGS) -o $(NAME) $(OBJS) $(LIBS)

$(OBJ_PATH)/%.o: $(SRC_PATH)/%.c $(INCS)
	@ mkdir -p $(OBJ_PATH)
	@ $(CC) $(CFLAGS) -o $@ -c $< -I $(INCS)

clean:
	@ make clean -C $(LIB_PATH)
	@ $(RM) $(OBJS)
	@ $(RM) -r $(OBJ_PATH)

fclean: clean
	@ make fclean -C $(LIB_PATH)
	@ $(RM) $(NAME)
	

re: fclean all

tester: all
	@ bash shell_script/test.sh

leaks: all
	@ leaks -atExit -- ./push_swap 3 2 1 5 9 0

.PHONY : all clean fclean re