BIN_DIR=./bin/

CC=gcc
CFLAGS=-Wall -Werror -Wextra -Wpedantic -g

SRC=$(wildcard *.c)
OBJ=$(patsubst %.c, %.o, $(SRC))
BIN=$(BIN_DIR)generic_swap

all: $(BIN)

$(BIN): $(OBJ)
	$(CC) $(CFLAGS) -o $@ $^

%.o: %.c
	$(CC) $(CFLAGS) -c -o $@ $^

clean:
	rm -rf $(BIN)
