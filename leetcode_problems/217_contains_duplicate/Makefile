BIN_DIR=./bin/

CC=gcc
DEPFLAGS=-MD -MP
CFLAGS=-Wall -Werror -Wextra -pedantic -I . $(DEPFLAGS)
LDFLAGS=-lm

SRC=$(wildcard *.c)
OBJ=$(patsubst %.c, %.o, $(SRC))
BIN=$(BIN_DIR)main

all: $(BIN)

debug: CFLAGS += -DDEBUG -g
debug: $(BIN)

$(BIN): $(OBJ)
	$(CC) $(CFLAGS) -o $@ $^ $(LDFLAGS)

%.o: %.c
	$(CC) $(CFLAGS) -c -o $@ $< $(LDFLAGS)

clean:
	rm -rf $(OBJ) $(BIN)
