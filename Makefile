# Compiler and Linker settings
CC = gcc
CFLAGS = -Wall -std=c99

SRC = sudoku.c
OBJ = sudoku.o
OUT = sudoku.exe

all:
	$(CC) -o $(OUT) $(SRC) 
clean:
	del $(OUT)

# Run the program (optional)
run: $(OUT)
	$(OUT)
