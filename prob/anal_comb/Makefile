# Compilador e bandeiras
CC     = gcc
FLAGS  = -I$(INCLUDE) -Wall -pedantic -g
LFLAGS = -lm

# Diretorios
RAIZ    = .
BIN     = $(RAIZ)/bin
INCLUDE = $(RAIZ)/include
OBJ     = $(RAIZ)/obj
SRC     = $(RAIZ)/src
TESTS   = $(RAIZ)/tests
ALL_OBJ = $(OBJ)/contagem.o $(OBJ)/uteis.o $(OBJ)/ordenacoes.o
CON_OBJ = $(OBJ)/contagem.o $(OBJ)/uteis.o $(OBJ)/ordenacoes.o
TESTES  = $(BIN)/testa_mul $(BIN)/testa_fac $(BIN)/testa_perm \
	  $(BIN)/testa_coef_mult $(BIN)/testa_coef_bin $(BIN)/testa_potencia

# Alvos
all: $(BIN)/main

testes: $(TESTES)

$(BIN)/main: $(SRC)/main.c $(ALL_OBJ)
	$(CC) $(FLAGS) -o $(BIN)/main $(SRC)/main.c $(OBJ)/*.o $(LFLAGS)

$(OBJ)/contagem.o: $(SRC)/contagem.c $(INCLUDE)/contagem.h
	$(CC) $(FLAGS) -o $(OBJ)/contagem.o -c $(SRC)/contagem.c

$(OBJ)/ordenacoes.o: $(SRC)/ordenacoes.c $(INCLUDE)/ordenacoes.h
	$(CC) $(FLAGS) -o $(OBJ)/ordenacoes.o -c $(SRC)/ordenacoes.c

$(OBJ)/uteis.o: $(SRC)/uteis.c $(INCLUDE)/uteis.h
	$(CC) $(FLAGS) -o $(OBJ)/uteis.o -c $(SRC)/uteis.c

$(BIN)/testa_mul: $(TESTS)/testa_mul.c $(CON_OBJ)
	$(CC) $(FLAGS) -o $(BIN)/testa_mul $(TESTS)/testa_mul.c $(CON_OBJ) $(LFLAGS)

$(BIN)/testa_fac: $(TESTS)/testa_fac.c $(CON_OBJ)
	$(CC) $(FLAGS) -o $(BIN)/testa_fac $(TESTS)/testa_fac.c $(CON_OBJ) $(LFLAGS)

$(BIN)/testa_perm: $(TESTS)/testa_perm.c $(CON_OBJ)
	$(CC) $(FLAGS) -o $(BIN)/testa_perm $(TESTS)/testa_perm.c $(CON_OBJ) $(LFLAGS)

$(BIN)/testa_coef_mult: $(TESTS)/testa_coef_mult.c $(CON_OBJ)
	$(CC) $(FLAGS) -o $(BIN)/testa_coef_mult $(TESTS)/testa_coef_mult.c $(CON_OBJ) $(LFLAGS)

$(BIN)/testa_coef_bin: $(TESTS)/testa_coef_bin.c $(CON_OBJ)
	$(CC) $(FLAGS) -o $(BIN)/testa_coef_bin $(TESTS)/testa_coef_bin.c $(CON_OBJ) $(LFLAGS)

$(BIN)/testa_potencia: $(TESTS)/testa_potencia.c $(CON_OBJ)
	$(CC) $(FLAGS) -o $(BIN)/testa_potencia $(TESTS)/testa_potencia.c $(CON_OBJ) $(LFLAGS)

clean_testes:
	rm -f $(BIN)/testa_*

clean:
	rm -f $(OBJ)/*.o
	rm -f $(BIN)/*
