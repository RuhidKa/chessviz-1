CC=g++
CFLAGS=-c -Wall -MP -MMD -std=c++11
EXECUTABLE=bin/chess.out
SOURSES=src/main.cpp src/board_print_html.cpp src/board.cpp src/figure.cpp src/check.cpp
OBJECTSS=$(SOURSES:.cpp=.out)
OBJECTS=$(patsubst src/%,build/%,$(OBJECTSS))

all: $(SOURCES) $(EXECUTABLE) bin/chess.html
bin/chess.html: $(EXECUTABLE)
	./bin/chess.out
$(EXECUTABLE): $(OBJECTS)
	$(CC) $(OBJECTS) -o $@
build/%.out: src/%.cpp
	$(CC) $(CFLAGS) $< -o $@
.PHONY: clean
clean:
	rm -rf build/*.out bin/*.html src/*.out bin/*.out build/*.d
start:
	./bin/chess.out
