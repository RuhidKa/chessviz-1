CC=g++
CFLAGS=-c -Wall -MP -MMD -std=c++17
TESTFLAGS=-I src -I test -c -Wall -std=c++17
EXECUTABLE=bin/chess.out
SOURSES=src/main.cpp src/board_print_html.cpp src/board.cpp src/figure.cpp src/check.cpp
OBJECTSS=$(SOURSES:.cpp=.out)
OBJECTS=$(patsubst src/%,build/src/%,$(OBJECTSS))
TESTEXECUTABLE=bin/Test.out
PREPROCESS=test/ctest.h
TESTSOURSESS=$(patsubst test/%,thirdparty/%,$(PREPROCESS))
TESTSOURSES=$(TESTSOURSESS:.h=.cpp)
TESTOBJECTSS=$(TESTSOURSES:.cpp=.out)
TESTOBJECTS=$(patsubst thirdparty/%,build/test/%,$(TESTOBJECTSS))
BUILDED=build/src/board_print_html.out build/src/figure.out build/src/board.out build/src/check.out
all: $(SOURCES) $(EXECUTABLE)
$(EXECUTABLE): $(OBJECTS)
	$(CC) $(OBJECTS) -o $@
	./bin/chess.out
build/src/%.out: src/%.cpp
	$(CC) $(CFLAGS) $< -o $@
.PHONY: clean test start
clean:
	rm -rf build/src/*
	rm -rf build/test/*
	rm -rf bin/*.out
	rm -rf bin/*.html
test: $(TESTSOURSES) $(TESTEXECUTABLE)
$(TESTSOURSES): $(PREPROCESS)
	cxxtestgen --error-printer -o $@ $<
$(TESTEXECUTABLE): $(TESTOBJECTS)
	$(CC)  $(TESTOBJECTS) $(BUILDED) -o $@
build/test/%.out: thirdparty/%.cpp
	$(CC) $(TESTFLAGS) $< -o $@
start:
	./bin/chess.out
