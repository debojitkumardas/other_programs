BIN_DIR=./bin/

CXX=g++
CXXFLAGS=-Wall -Werror -Wextra -Wpedantic -g -std=c++17

SRC=$(wildcard *.cpp)
OBJ=$(patsubst %.cpp, %.o, $(SRC))
BIN=$(BIN_DIR)main

all: $(BIN)

$(BIN): $(OBJ)
	$(CXX) $(CXXFLAGS) -o $@ $^

%.o: %.c
	$(CXX) $(CXXFLAGS) -c -o $@ $^

clean:
	rm -rf $(BIN) $(OBJ)
