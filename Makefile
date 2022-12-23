# SRC_DIR := src
# OBJ_DIR := lib
# BIN_DIR := bin # or . if you want it in the current directory
# EXE := $(BIN_DIR)/tuigol
#
# SRC := $(wildcard $(SRC_DIR)/*.c)
#
all: main.cpp
	g++ main.cpp -lncurses -o tuigol.out

clean:
	rm ./*.out
