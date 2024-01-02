PROJECT_NAME=rss_agg

SRC_DIR=src/$(PROJECT_NAME)
PKG_DIR=int_pkg
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
