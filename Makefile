chess.html: chess.o
	./chess.o
chess.o: chess.c
	gcc -Wall -o chess.o chess.c
