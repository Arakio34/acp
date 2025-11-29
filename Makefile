CC = gcc
FLAGS =  -g -lm -Wall
OBJECT = main.o matrice.o 
BIN =  main

all:
	$(CC) $(FLAGS) -c main.c
	$(CC) $(FLAGS) -c matrice.c
	$(CC) $(FLAGS) $(OBJECT) -o $(BIN)
	./main
