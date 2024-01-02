CC=gcc
CFLAGS=-Wall -Werror -Wextra

SRC=$(wildcard *.c)
BIN=$(patsubst %.c, %, $(SRC))

all: $(BIN)

debug: CFLAGS += -DDEBUG -g
debug: $(BIN)

clean:
	rm -rf $(BIN)
