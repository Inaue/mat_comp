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
ALL_OBJ = $(OBJ)/contagem.o
TESTES  = $(BIN)/testa_mul $(BIN)/testa_fac $(BIN)/testa_perm \
	  $(BIN)/testa_coef_mult $(BIN)/testa_coef_bin $(BIN)/testa_potencia

# Alvos
all: 	
	#$(BIN)/
testes: $(TESTES)

# $(BIN)/rsa_guess: $(SRC)/rsa_guess.c $(ALL_OBJ)
# 	$(CC) $(FLAGS) -o $(BIN)/rsa_guess $(SRC)/rsa_guess.c $(OBJ)/*.o $(LFLAGS)

$(OBJ)/contagem.o: $(SRC)/contagem.c $(INCLUDE)/contagem.h
	$(CC) $(FLAGS) -o $(OBJ)/contagem.o -c $(SRC)/contagem.c

$(BIN)/testa_mul: $(TESTS)/testa_mul.c $(OBJ)/contagem.o
	$(CC) $(FLAGS) -o $(BIN)/testa_mul $(TESTS)/testa_mul.c $(OBJ)/contagem.o $(LFLAGS)

$(BIN)/testa_fac: $(TESTS)/testa_fac.c $(OBJ)/contagem.o
	$(CC) $(FLAGS) -o $(BIN)/testa_fac $(TESTS)/testa_fac.c $(OBJ)/contagem.o $(LFLAGS)

$(BIN)/testa_perm: $(TESTS)/testa_perm.c $(OBJ)/contagem.o
	$(CC) $(FLAGS) -o $(BIN)/testa_perm $(TESTS)/testa_perm.c $(OBJ)/contagem.o $(LFLAGS)

$(BIN)/testa_coef_mult: $(TESTS)/testa_coef_mult.c $(OBJ)/contagem.o
	$(CC) $(FLAGS) -o $(BIN)/testa_coef_mult $(TESTS)/testa_coef_mult.c $(OBJ)/contagem.o $(LFLAGS)

$(BIN)/testa_coef_bin: $(TESTS)/testa_coef_bin.c $(OBJ)/contagem.o
	$(CC) $(FLAGS) -o $(BIN)/testa_coef_bin $(TESTS)/testa_coef_bin.c $(OBJ)/contagem.o $(LFLAGS)

$(BIN)/testa_potencia: $(TESTS)/testa_potencia.c $(OBJ)/contagem.o
	$(CC) $(FLAGS) -o $(BIN)/testa_potencia $(TESTS)/testa_potencia.c $(OBJ)/contagem.o $(LFLAGS)

clean_testes:
	rm -f $(BIN)/testa_*

clean:
	rm -f $(OBJ)/*.o
	rm -f $(BIN)/*
