# Compiler and Flags
CC = g++
CFLAGS = -std=c++11 -Wall

# Source and Object Files
SRC_01 = ./src/wordle.cpp

OBJ_01 = $(SRC_01:.cpp=.o)

ALL_OBJ  = $(OBJ_01)

# Library Paths and Flags
LIBDIR = ./lib
LDFLAGS = -L$(LIBDIR)

# Executable Name
NAME_01 = wordle

ALL_EXE = $(NAME_01)

# Targets

all: $(ALL_EXE)

$(NAME_01): $(OBJ_01)
	$(CC) $(CFLAGS) $(LDFLAGS) -o $(NAME_01) $^ -lm

clean_obj:
	rm -f $(ALL_OBJ)

clean_exe:
	rm -f $(ALL_EXE)

clean:
	rm -f $(ALL_OBJ)
	
	rm -f $(ALL_EXE)
