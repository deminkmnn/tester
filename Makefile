NAME = libmx.a

SRC_DIR = src
OBJ_DIR = obj
INC_DIR = inc

FLAGS = -std=c11 -Wall -Wextra -Werror -Wpedantic

LIBMX_DIR = ./libmx


.PHONY: all install uninstall clean reinstall

all: install clean

install:
	@make -C $(LIBMX_DIR)
	@clang $(FLAGS) -I $(INC_DIR) $(SRC_DIR)/*.c -L $(LIBMX_DIR) -lmx -o pathfinder

uninstall: clean
	@rm -rf $(NAME)
	@rm -rf $(OBJ_DIR)
	@rm -rf pathfinder
	@make uninstall -C $(LIBMX_DIR)

clean:
	@rm -rf $(OBJ_DIR)

reinstall: all
