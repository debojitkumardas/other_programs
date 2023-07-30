BIN_DIR=./bin/

CXX=g++
CXXFLAGS=-Wall -Werror -Wextra -Wconversion -Wshadow -Wunreachable-code -pedantic -g -std=c++17

SRC=$(wildcard *.cpp)
OBJ=$(patsubst %.cpp, %.o, $(SRC))
BIN=$(BIN_DIR)main

all: $(BIN)

$(BIN): $(OBJ)
	$(CXX) $(CXXFLAGS) -o $@ $^

%.o: %cpp
	$(CXX) $(CXXFLAGS) -c -o $@ $<

clean:
	rm -rf $(OBJ) $(BIN)
