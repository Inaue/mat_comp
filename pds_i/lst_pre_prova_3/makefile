# Compiler and Flags
CC = gcc
CFLAGS = -g -Wall

# Source and Object Files
SRC_01 = ./src/exercicio_01.c
SRC_02 = ./src/exercicio_02.c
SRC_03 = ./src/exercicio_03.c
SRC_04 = ./src/exercicio_04.c
SRC_05 = ./src/exercicio_05.c
SRC_06 = ./src/exercicio_06.c
SRC_07 = ./src/exercicio_07.c
SRC_08 = ./src/exercicio_08.c
SRC_09 = ./src/exercicio_09.c

OBJ_01 = $(SRC_01:.c=.o)
OBJ_02 = $(SRC_02:.c=.o)
OBJ_03 = $(SRC_03:.c=.o)
OBJ_04 = $(SRC_04:.c=.o)
OBJ_05 = $(SRC_05:.c=.o)
OBJ_06 = $(SRC_06:.c=.o)
OBJ_07 = $(SRC_07:.c=.o)
OBJ_08 = $(SRC_08:.c=.o)
OBJ_09 = $(SRC_09:.c=.o)

ALL_OBJ  = $(OBJ_01) $(OBJ_02) $(OBJ_03) $(OBJ_04) $(OBJ_05) \
           $(OBJ_06) $(OBJ_07) $(OBJ_08) $(OBJ_09)

# Library Paths and Flags
LIBDIR = ./lib
LDFLAGS = -L$(LIBDIR)

# Executable Name
NAME_01 = exercicio_01
NAME_02 = exercicio_02
NAME_03 = exercicio_03
NAME_04 = exercicio_04
NAME_05 = exercicio_05
NAME_06 = exercicio_06
NAME_07 = exercicio_07
NAME_08 = exercicio_08
NAME_09 = exercicio_09

ALL_EXE = $(NAME_01) $(NAME_02) $(NAME_03) $(NAME_04) $(NAME_05) \
          $(NAME_06) $(NAME_07) $(NAME_08) $(NAME_09)

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

$(NAME_05): $(OBJ_05)
	$(CC) $(CFLAGS) $(LDFLAGS) -o $(NAME_05) $^ -lm

$(NAME_06): $(OBJ_06)
	$(CC) $(CFLAGS) $(LDFLAGS) -o $(NAME_06) $^ -lm

$(NAME_07): $(OBJ_07)
	$(CC) $(CFLAGS) $(LDFLAGS) -o $(NAME_07) $^ -lm

$(NAME_08): $(OBJ_08)
	$(CC) $(CFLAGS) $(LDFLAGS) -o $(NAME_08) $^ -lm

$(NAME_09): $(OBJ_09)
	$(CC) $(CFLAGS) $(LDFLAGS) -o $(NAME_09) $^ -lm

clean_obj:
	rm -f $(ALL_OBJ)

clean_exe:
	rm -f $(ALL_EXE)

clean:
	rm -f $(ALL_OBJ)
	
	rm -f $(ALL_EXE)
