CC = clang
CFLAGS = -std=c11 -Wall -Wextra -Werror -Wpedantic
INCLUDES = -Iinc

SRC_DIR = src
OBJ_DIR = obj
INC_DIR = inc

SRC_FILES = $(wildcard $(SRC_DIR)/*.c)
OBJ_FILES = $(patsubst $(SRC_DIR)/%.c, $(OBJ_DIR)/%.o, $(SRC_FILES))
LIB_NAME = libmx.a

all: $(LIB_NAME)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c | $(OBJ_DIR)
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

$(LIB_NAME): $(OBJ_FILES)
	ar rcs $(LIB_NAME) $(OBJ_FILES)

clean:
	rm -rf $(OBJ_DIR)
	rm -f $(LIB_NAME)

uninstall: clean
	rm -f $(LIB_NAME)

delete:
	rm -f $(LIB_NAME)

reinstall: uninstall all

.PHONY: all clean uninstall reinstall delete
