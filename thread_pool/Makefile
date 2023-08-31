SRC_DIR=src/
HDR_DIR=hdr/
BIN_DIR=bin/

CC=gcc
DEPFLAGS=-MD -MP
CFLAGS=-Wall -Werror -Wextra -Wshadow -pthread -lpthread -pedantic -I . $(DEPFLAGS)

SRC=$(wildcard $(SRC_DIR)*.c)
HDR=$(wildcard $(HDR_DIR)*.d)

HDR_D=$(patsubst %.c, $(BIN_DIR)%.d, $(notdir $(SRC)))
OBJ=$(patsubst %.c, $(BIN_DIR)%.o, $(notdir $(SRC)))
BIN=$(BIN_DIR)main

all: $(BIN)

debug: CFLAGS += -DDEBUG -g
debug: $(BIN)

$(BIN): $(OBJ)
	$(CC) $(CFLAGS) -o $@ $^

$(BIN_DIR)%.o: $(SRC_DIR)%.c $(HDR)
	$(CC) $(CFLAGS) -c -o $@ $<

run_with_valgrind:
	valgrind --enable-debuginfod=no --leak-check=full --show-leak-kinds=all --errors-for-leak-kinds=all --track-origins=yes -s --verbose --log-file=valile=valgrind_out.txt ./bin/main

clean:
	rm -rf $(HDR_D) $(OBJ) $(BIN)

clean_o:
	rm -rf .cache compile_commands.json
