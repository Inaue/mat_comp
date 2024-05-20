# Compiler and Flags
CC = gcc
CFLAGS = -g -Wall

# Source and Object Files
SRC_01 = ./src/exercicio_01.c
SRC_02 = ./src/exercicio_02.c ./src/vetores.c
SRC_03 = ./src/exercicio_03.c ./src/vetores.c
SRC_04 = ./src/exercicio_04.c ./src/vetores.c

OBJ_01 = $(SRC_01:.c=.o)
OBJ_02 = $(SRC_02:.c=.o)
OBJ_03 = $(SRC_03:.c=.o)
OBJ_04 = $(SRC_04:.c=.o)

ALL_OBJ  = $(OBJ_01) $(OBJ_02) $(OBJ_03) $(OBJ_04)

# Library Paths and Flags
LIBDIR = ./lib
LDFLAGS = -L$(LIBDIR)

# Executable Name
NAME_01 = exercicio_01
NAME_02 = exercicio_02
NAME_03 = exercicio_03
NAME_04 = exercicio_04

ALL_EXE = $(NAME_01) $(NAME_02) $(NAME_03) $(NAME_04)

# Targets

all: $(ALL_EXE)

$(NAME_01): $(OBJ_01)
	$(CC) $(CFLAGS) $(LDFLAGS) -o $(NAME_01) $^ -lm

$(NAME_02): $(OBJ_02)
	$(CC) $(CFLAGS) $(LDFLAGS) -o $(NAME_02) $^ -lm

$(NAME_03): $(OBJ_03)
	$(CC) $(CFLAGS) $(LDFLAGS) -o $(NAME_03) $^ -lm

$(NAME_04): $(OBJ_04)
	$(CC) $(CFLAGS) $(LDFLAGS) -o $(NAME_04) $^ -lm

clean_obj:
	rm -f $(ALL_OBJ)

clean_exe:
	rm -f $(ALL_EXE)

clean:
	rm -f $(ALL_OBJ)
	
	rm -f $(ALL_EXE)
