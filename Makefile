
NAME = minishell
SRC_DIR		:= src builtin read_line
INC_DIR		:= includes
HEAD		:= $(INC_DIR)/shell.h
LIB_DIR		:= libft
LIB_HEAD	:= $(LIB_DIR)/libft.h
#SYS			:= $(shell uname -s)

SRC := $(foreach DIR,$(SRC_DIR), $(wildcard $(DIR)/*.c))

#ifeq ($(SYS), Linux)
#SRC := $(foreach DIR,$(SRC_DIR), $(wildcard $(DIR)/*.c))
#endif
#ifeq ($(SYS), Darwin)
#	SRC := src/cmd_manipulation.c src/env_ops.c src/error_handling.c \
#	 	src/exec_cmd_ops.c src/expansions.c \
#		src/init_env.c src/path_ops.c src/shell.c
#endif

#OBJS		:= $(foreach DIR,$(SRC_DIR), $(wildcard $(DIR)/*.o))
CFLAGS		:= -Wall -Wextra -Werror
OFLAGS		:= -O3
INCL		:= -I $(LIB_DIR) -I $(HEAD)
LIB			:= -L $(LIB_DIR) -lft -ltermcap

.PHONY: all
all : $(NAME)

$(NAME) : $(SRC) $(HEAD) $(LIB_HEAD)
	@echo $(SYS)
	@make -C $(LIB_DIR)
	clang $(CFLAGS) $(OFLAGS) $(SRC) -I $(LIB_DIR) -I $(INC_DIR) $(LIB) -o $@

clean:
	@make -C $(LIB_DIR) clean
	@echo  "Object files removed!"

fclean: clean
	@make -C $(LIB_DIR) fclean
	@rm -f $(NAME)
	@echo "Binary files has been removed!"

re: fclean all
