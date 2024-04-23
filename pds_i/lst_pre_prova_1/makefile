# Compiler and Flags
CC = gcc
CFLAGS = -g -Wall

# Source and Object Files
SRC_01 = ./src/exercicio_01.c ./src/vetores.c
SRC_02 = ./src/exercicio_02.c ./src/financas.c
SRC_03 = ./src/exercicio_03.c ./src/financas.c
SRC_04 = ./src/exercicio_04.c ./src/financas.c
SRC_05 = ./src/exercicio_05.c ./src/financas.c
SRC_06 = ./src/exercicio_06.c ./src/financas.c
SRC_07 = ./src/exercicio_07.c
SRC_08 = ./src/exercicio_08.c ./src/geometria.c
SRC_09 = ./src/exercicio_09.c ./src/geometria.c
SRC_10 = ./src/exercicio_10.c ./src/estatisticas.c ./src/vetores.c
SRC_11 = ./src/exercicio_11.c ./src/estatisticas.c ./src/vetores.c
SRC_12 = ./src/exercicio_12.c ./src/estatisticas.c ./src/vetores.c
SRC_13 = ./src/exercicio_13.c ./src/vetores.c
SRC_14 = ./src/exercicio_14.c ./src/vetores.c ./src/ordenacoes.c
SRC_15 = ./src/exercicio_15.c ./src/vetores.c ./src/ordenacoes.c
SRC_16 = ./src/exercicio_16.c
SRC_17 = ./src/exercicio_17.c ./src/vetores.c ./src/ordenacoes.c
SRC_18 = ./src/exercicio_18.c
SRC_19 = ./src/exercicio_19.c
SRC_20 = ./src/exercicio_20.c ./src/vetores.c
SRC_21 = ./src/exercicio_21.c ./src/vetores.c
SRC_22 = ./src/exercicio_22.c ./src/vetores.c
SRC_23 = ./src/exercicio_23.c ./src/vetores.c
SRC_24 = ./src/exercicio_24.c ./src/vetores.c
SRC_25 = ./src/exercicio_25.c ./src/vetores.c
SRC_26 = ./src/exercicio_26.c ./src/vetores.c
SRC_27 = ./src/exercicio_27.c ./src/vetores.c

OBJ_01 = $(SRC_01:.c=.o)
OBJ_02 = $(SRC_02:.c=.o)
OBJ_03 = $(SRC_03:.c=.o)
OBJ_04 = $(SRC_04:.c=.o)
OBJ_05 = $(SRC_05:.c=.o)
OBJ_06 = $(SRC_06:.c=.o)
OBJ_07 = $(SRC_07:.c=.o)
OBJ_08 = $(SRC_08:.c=.o)
OBJ_09 = $(SRC_09:.c=.o)
OBJ_10 = $(SRC_10:.c=.o)
OBJ_11 = $(SRC_11:.c=.o)
OBJ_12 = $(SRC_12:.c=.o)
OBJ_13 = $(SRC_13:.c=.o)
OBJ_14 = $(SRC_14:.c=.o)
OBJ_15 = $(SRC_15:.c=.o)
OBJ_16 = $(SRC_16:.c=.o)
OBJ_17 = $(SRC_17:.c=.o)
OBJ_18 = $(SRC_18:.c=.o)
OBJ_19 = $(SRC_19:.c=.o)
OBJ_20 = $(SRC_20:.c=.o)
OBJ_21 = $(SRC_21:.c=.o)
OBJ_22 = $(SRC_22:.c=.o)
OBJ_23 = $(SRC_23:.c=.o)
OBJ_24 = $(SRC_24:.c=.o)
OBJ_25 = $(SRC_25:.c=.o)
OBJ_26 = $(SRC_26:.c=.o)
OBJ_27 = $(SRC_27:.c=.o)

ALL_OBJ  = $(OBJ_01) $(OBJ_02) $(OBJ_03) $(OBJ_04) $(OBJ_05) \
	       $(OBJ_06) $(OBJ_07) $(OBJ_08) $(OBJ_09) $(OBJ_10) \
		   $(OBJ_11) $(OBJ_12) $(OBJ_13) $(OBJ_14) $(OBJ_15) \
		   $(OBJ_16) $(OBJ_17) $(OBJ_18) $(OBJ_19) $(OBJ_20) \
		   $(OBJ_21) $(OBJ_22) $(OBJ_23) $(OBJ_24) $(OBJ_25) \
		   $(OBJ_26) $(OBJ_27)

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
NAME_10 = exercicio_10
NAME_11 = exercicio_11
NAME_12 = exercicio_12
NAME_13 = exercicio_13
NAME_14 = exercicio_14
NAME_15 = exercicio_15
NAME_16 = exercicio_16
NAME_17 = exercicio_17
NAME_18 = exercicio_18
NAME_19 = exercicio_19
NAME_20 = exercicio_20
NAME_21 = exercicio_21
NAME_22 = exercicio_22
NAME_23 = exercicio_23
NAME_24 = exercicio_24
NAME_25 = exercicio_25
NAME_26 = exercicio_26
NAME_27 = exercicio_27

ALL_EXE = $(NAME_01) $(NAME_02) $(NAME_03) $(NAME_04) $(NAME_05) \
          $(NAME_06) $(NAME_07) $(NAME_08) $(NAME_09) $(NAME_10) \
		  $(NAME_11) $(NAME_12) $(NAME_13) $(NAME_14) $(NAME_15) \
		  $(NAME_16) $(NAME_17) $(NAME_18) $(NAME_19) $(NAME_20) \
		  $(NAME_21) $(NAME_22) $(NAME_23) $(NAME_24) $(NAME_25) \
		  $(NAME_26) $(NAME_27)

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

$(NAME_10): $(OBJ_10)
	$(CC) $(CFLAGS) $(LDFLAGS) -o $(NAME_10) $^ -lm

$(NAME_11): $(OBJ_11)
	$(CC) $(CFLAGS) $(LDFLAGS) -o $(NAME_11) $^ -lm

$(NAME_12): $(OBJ_12)
	$(CC) $(CFLAGS) $(LDFLAGS) -o $(NAME_12) $^ -lm

$(NAME_13): $(OBJ_13)
	$(CC) $(CFLAGS) $(LDFLAGS) -o $(NAME_13) $^ -lm

$(NAME_14): $(OBJ_14)
	$(CC) $(CFLAGS) $(LDFLAGS) -o $(NAME_14) $^ -lm

$(NAME_15): $(OBJ_15)
	$(CC) $(CFLAGS) $(LDFLAGS) -o $(NAME_15) $^ -lm

$(NAME_16): $(OBJ_16)
	$(CC) $(CFLAGS) $(LDFLAGS) -o $(NAME_16) $^ -lm

$(NAME_17): $(OBJ_17)
	$(CC) $(CFLAGS) $(LDFLAGS) -o $(NAME_17) $^ -lm

$(NAME_18): $(OBJ_18)
	$(CC) $(CFLAGS) $(LDFLAGS) -o $(NAME_18) $^ -lm

$(NAME_19): $(OBJ_19)
	$(CC) $(CFLAGS) $(LDFLAGS) -o $(NAME_19) $^ -lm

$(NAME_20): $(OBJ_20)
	$(CC) $(CFLAGS) $(LDFLAGS) -o $(NAME_20) $^ -lm

$(NAME_21): $(OBJ_21)
	$(CC) $(CFLAGS) $(LDFLAGS) -o $(NAME_21) $^ -lm

$(NAME_22): $(OBJ_22)
	$(CC) $(CFLAGS) $(LDFLAGS) -o $(NAME_22) $^ -lm

$(NAME_23): $(OBJ_23)
	$(CC) $(CFLAGS) $(LDFLAGS) -o $(NAME_23) $^ -lm

$(NAME_24): $(OBJ_24)
	$(CC) $(CFLAGS) $(LDFLAGS) -o $(NAME_24) $^ -lm

$(NAME_25): $(OBJ_25)
	$(CC) $(CFLAGS) $(LDFLAGS) -o $(NAME_25) $^ -lm

$(NAME_26): $(OBJ_26)
	$(CC) $(CFLAGS) $(LDFLAGS) -o $(NAME_26) $^ -lm

$(NAME_27): $(OBJ_27)
	$(CC) $(CFLAGS) $(LDFLAGS) -o $(NAME_27) $^ -lm

clean_obj:
	rm -f $(ALL_OBJ)

clean_exe:
	rm -f $(ALL_EXE)

clean:
	rm -f $(ALL_OBJ)
	
	rm -f $(ALL_EXE)
