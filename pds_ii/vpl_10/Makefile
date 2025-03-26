.DEFAULT_GOAL = all

TARGET  = main
SOURCES = $(wildcard src/*.c src/*.cpp)
OBJECTS = $(patsubst src%,obj%, $(patsubst %.c,%.o, $(patsubst %.cpp,%.o,$(SOURCES))))

INCLUDE = -I./include
LIBPATH =
LIBS    =

FLAGS    = -Wall -pedantic -g
CCFLAGS  = $(FLAGS) -std=c99
CXXFLAGS = $(FLAGS) -std=c++11

CC  = gcc
CXX = g++

all: $(OBJECTS)
#	$(CC) $(CCFLAGS) $(INCLUDE) $(OBJECTS) -o bin/$(TARGET) $(LIBPATH) $(LIBS)
	$(CXX) $(CXXFLAGS) $(INCLUDE) $(OBJECTS) -o bin/$(TARGET) $(LIBPATH) $(LIBS)

%.o: ../src/%.c
	$(CC) $(CCFLAGS) $(INCLUDE) -c $< -o $@

%.o: ../src/%.cpp
	$(CXX) $(CXXFLAGS) $(INCLUDE) -c $< -o $@

run: all
	./bin/$(TARGET)

clean:
	rm -rf obj/*
	rm -rf bin/*
