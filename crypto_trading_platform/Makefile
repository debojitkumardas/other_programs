SRC_DIR=./src/
BIN_DIR=./bin/

CXX=g++
DEPFLAGS=-MD -MP
CXXFLAGS=-Wall -Werror -Wextra -Wconversion -Wshadow -Wunreachable-code -pedantic -std=c++17 -I . $(DEPFLAGS)

SRC=$(wildcard $(SRC_DIR)*.cpp)
HDR=$(patsubst %.cpp, $(BIN_DIR)%.d, $(notdir $(SRC)))
OBJ=$(patsubst %.cpp, $(BIN_DIR)%.o, $(notdir $(SRC)))
BIN=$(BIN_DIR)main

all: $(BIN)

debug: CXXFLAGS += -DDEBUG -g
debug: $(BIN)

$(BIN): $(OBJ)
	$(CXX) $(CXXFLAGS) -o $@ $^

$(BIN_DIR)%.o: $(SRC_DIR)%.cpp
	$(CXX) $(CXXFLAGS) -c -o $@ $<

run_with_valgrind:
	valgrind --enable-debuginfod=no --leak-check=full --show-leak-kinds=all --errors-for-leak-kinds=all --track-origins=yes -s --verbose --log-file=valile=valgrind_out.txt ./bin/main

clean:
	rm -rf $(HDR) $(OBJ) $(BIN)

clean_o:
	rm -rf .cache compile_commands.json
