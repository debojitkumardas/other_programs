# https://stackoverflow.com/questions/38499760/make-use-pattern-rule-for-multiple-prerequisites-and-multiple-targets
# https://github.com/GoogleCloudPlatform/cpp-samples/blob/main/.clang-format
BIN_DIR=./bin/

CC=gcc
CFLAGS=-Wall -Werror -Wextra -g

SRC=$(wildcard *.c)
BIN=$(patsubst %.c, $(BIN_DIR)%, $(SRC))

all: $(BIN)

$(BIN_DIR)%: %.c
	$(CC) $(CFLAGS) -o $@ $<

clean:
	rm -rf $(BIN)
