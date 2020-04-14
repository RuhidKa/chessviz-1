CC=gcc
CFLAGS=-c -Wall -MP -MMD
EXECUTABLE=bin/chess.o
SOURSES=src/main.c src/board_print_html.c src/board.c src/figure.c
OBJECTSS=$(SOURSES:.c=.o)
OBJECTS=$(patsubst src/%,build/%,$(OBJECTSS))

all: $(SOURCES) $(EXECUTABLE) bin/chess.html
bin/chess.html: $(EXECUTABLE)
	./bin/chess.o
$(EXECUTABLE): $(OBJECTS)
	$(CC) $(OBJECTS) -o $@
build/%.o: src/%.c
	$(CC) $(CFLAGS) $< -o $@
.PHONY: clean
clean:
	rm -rf build/*.o bin/*.html src/*.o
