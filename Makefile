chess.html: build/chess.o
	./build/chess.o
build/chess.o: src/chess.c
	gcc -Wall -o build/chess.o src/chess.c
