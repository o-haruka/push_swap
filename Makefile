# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: homura <homura@student.42tokyo.jp>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/11/08 17:49:33 by homura            #+#    #+#              #
#    Updated: 2025/11/13 18:49:37 by homura           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= push_swap

CC			= cc
CFLAGS		= -Wall -Werror -Wextra -g

SRC_PATH	= srcs
SRC			= main.c \
			operation_push.c \
			operation_rotate.c \
			operation_rrotate.c \
			operation_swap.c \
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
	@ $(CC) $(CFLAGS) -o $@ -c $< -I $(INC_PATH)

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

random: all
	@ if [ -z "$(NUM)" ]; then \
		echo "使用法: make random NUM=数値の個数"; \
		echo "例: make random NUM=5"; \
		exit 1; \
	fi; \
	RANGE=$$(($(NUM) * 3)); \
	if [ $$RANGE -lt 1000 ]; then RANGE=1000; fi; \
	if command -v shuf > /dev/null 2>&1; then \
		ARG=$$(shuf -i 0-$$RANGE -n $(NUM) | tr '\n' ' '); \
	elif command -v jot > /dev/null 2>&1; then \
		ARG=$$(seq 0 $$RANGE | sort -R | head -$(NUM) | tr '\n' ' '); \
	else \
		RANGE_SIZE=$$RANGE; \
		if [ $$RANGE_SIZE -lt 100 ]; then RANGE_SIZE=100; fi; \
		ARG=""; \
		COUNT=0; \
		while [ $$COUNT -lt $(NUM) ]; do \
			NUM_VAL=$$((RANDOM % $$RANGE_SIZE)); \
			if ! echo "$$ARG" | grep -q "\b$$NUM_VAL\b"; then \
				ARG="$$ARG $$NUM_VAL"; \
				COUNT=$$((COUNT + 1)); \
			fi; \
		done; \
		ARG=$$(echo $$ARG | xargs); \
	fi; \
	echo "テスト中: $$ARG"; \
	if command -v ./checker_linux > /dev/null 2>&1; then \
		echo "結果:"; \
		echo "$$ARG" | xargs ./push_swap | ./checker_linux $$ARG; \
	elif command -v ./checker_Mac > /dev/null 2>&1; then \
		echo "結果:"; \
		echo "$$ARG" | xargs ./push_swap | ./checker_Mac $$ARG; \
	elif command -v ./checker > /dev/null 2>&1; then \
		echo "結果:"; \
		echo "$$ARG" | xargs ./push_swap | ./checker $$ARG; \
	else \
		echo "checkerが見つかりません。push_swapのみ実行:"; \
		echo "$$ARG" | xargs ./push_swap; \
	fi

.PHONY : all clean fclean re random