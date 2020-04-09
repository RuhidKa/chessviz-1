CC=gcc
CFLAGS=-c -Wall
EXECUTABLE=bin/chess.html
SOURSES=src/main.c src/board_print_html.c src/board.c
OBJECTSS=$(SOURSES:.c=.o)
OBJECTS=$(patsubst src/%,build/%,$(OBJECTSS))

all: $(SOURCES) $(EXECUTABLE)
$(EXECUTABLE): $(OBJECTS)
	$(CC) $(OBJECTS) -o $@
build/%.o: src/%.c
	$(CC) $(CFLAGS) $< -o $@
.PHONY: clean
clean:
	rm -rf build/*.o bin/*.html src/*.o
