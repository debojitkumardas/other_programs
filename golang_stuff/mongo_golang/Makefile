PROJECT_NAME=mongo_golang

SRC_DIR=.
BIN_DIR=bin

GO=go

# SRC=$(SRC_DIR)/main.go
SRC=$(wildcard $(SRC_DIR)/*.go)
BIN=$(BIN_DIR)/$(PROJECT_NAME)

.PHONY: all build clean

all: build

build:
	@mkdir -p $(BIN_DIR)
	@$(GO) build -o $(BIN) $(SRC)

run: build
	@./$(BIN)

clean:
	@rm -rf $(BIN)
