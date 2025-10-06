NAME		= push_swap

CC			= cc
CFLAGS		= -Wall -Werror -Wextra -g

SRC_PATH	= srcs
SRC			= main.c \
			operations.c \
			error.c
			
# 				check_args.c \
# 				dock_init.c \
# 				error_message.c \
# 				free.c \
# 				push.c \
# 				put_args.c \
# 				put_stack.c \
# 				rev_rotate.c \
# 				rotate.c \
# 				sand_clock.c \
# 				sort_num.c \
# 				sort.c \
# 				swap.c \

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

# CHECK		= \033[32m[✔]\033[0m
# REMOVE		= \033[31m[✘]\033[0m
# BLUE		= \033[1;34m
# RESET		= \033[0m

all : $(NAME)

$(NAME) : $(OBJS)
	@ make -C $(LIB_PATH)
	@ $(CC) $(CFLAGS) -o $(NAME) $(OBJS) $(LIBS)
	@echo "$(CHECK) $(BLUE)Compiling push_swap... $(RESET)"

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
	@echo "$(REMOVE) $(BLUE)Remove push_swap... $(RESET)"

re: fclean all

tester: all
	@ bash shell_script/test.sh

visual: all
	@ bash shell_script/pain.sh

leaks: all
	@ leaks -atExit -- ./push_swap 3 2 1 5 9 0

.PHONY : all clean fclean re