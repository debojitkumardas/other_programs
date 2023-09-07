SRC_DIR=src/
HDR_DIR=hdr/
IMGUI_DIR=imgui/
BIN_DIR=bin/

CXX=g++
DEPFLAGS=-MD -MP
CXXFLAGS=-Wall -Werror -Wextra -Wshadow -Wunreachable-code -Wformat -pedantic-errors -std=c++17 -I . -I$(IMGUI_DIR) -I$(IMGUI_DIR)backends $(DEPFLAGS)  # -Weffc++ -Wconversion
LDFLAGS=-lGL -lglfw -lGLEW -lpthread -ldl


SRC=$(wildcard $(SRC_DIR)*.cpp)
HDR=$(wildcard $(HDR_DIR)*.hpp)

# imgui files *********************************************************************
SRC += $(wildcard $(IMGUI_DIR)*.cpp)
SRC += $(wildcard $(IMGUI_DIR)backends/*.cpp)
# SRC += $(IMGUI_DIR)/imgui.cpp $(IMGUI_DIR)/imgui_demo.cpp $(IMGUI_DIR)/imgui_draw.cpp $(IMGUI_DIR)/imgui_tables.cpp $(IMGUI_DIR)/imgui_widgets.cpp
# SRC += $(IMGUI_DIR)/backends/imgui_impl_glfw.cpp $(IMGUI_DIR)/backends/imgui_impl_opengl3.cpp
HDR += $(wildcard $(IMGUI_DIR)*.h)
HDR += $(wildcard $(IMGUI_DIR)backends/*.h)
# *********************************************************************************

HDR_D=$(patsubst %.cpp, $(BIN_DIR)%.d, $(notdir $(SRC)))
OBJ=$(patsubst %.cpp, $(BIN_DIR)%.o, $(notdir $(SRC)))
BIN=$(BIN_DIR)main

all: $(BIN)

debug: CXXFLAGS += -DDEBUG -ggdb
debug: $(BIN)

release: CXXFLAGS += -O2 -DNDEBUG
release: $(BIN)

$(BIN): $(OBJ)
	$(CXX) $(CXXFLAGS) -o $@ $^ $(LDFLAGS)

$(BIN_DIR)%.o: $(SRC_DIR)%.cpp $(HDR)
	$(CXX) $(CXXFLAGS) -c -o $@ $< $(LDFLAGS)

$(BIN_DIR)%.o: $(IMGUI_DIR)%.cpp $(HDR)
	$(CXX) $(CXXFLAGS) -c -o $@ $< $(LDFLAGS)

$(BIN_DIR)%.o: $(IMGUI_DIR)backends/%.cpp $(HDR)
	$(CXX) $(CXXFLAGS) -c -o $@ $< $(LDFLAGS)

run_with_valgrind:
	valgrind --enable-debuginfod=no --leak-check=full --show-leak-kinds=all --errors-for-leak-kinds=all --track-origins=yes -s --verbose --log-file=valile=valgrind_out.txt ./bin/main

clean:
	rm -rf $(HDR_D) $(OBJ) $(BIN)

clean_o:
	rm -rf .cache compile_commands.json
