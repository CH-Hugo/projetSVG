CC := gcc
FLAGS := -Wall -Werror -Wextra -std=c99

build:
	$(CC) $(FLAGS) -c main.c
	$(CC) $(FLAGS) -c html.c
	$(CC) $(FLAGS) -c sauvegarde.c
	$(CC) $(FLAGS) -c couleurs.c
	$(CC) $(FLAGS) -c creations.c
	$(CC) $(FLAGS) -c modifier.c
	$(CC) $(FLAGS) -c structures.c
	$(CC) $(FLAGS) -c supprimer.c
	$(CC) $(FLAGS) main.o html.o sauvegarde.o couleurs.o creations.o modifier.o structures.o supprimer.o -o main

clean:
	rm main.o
	rm html.o