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
ALL_OBJ = $(OBJ)/primalidade.o $(OBJ)/arit_mod.o
TESTES  = $(BIN)/testa_add_mod $(BIN)/testa_sub_mod $(BIN)/testa_mul_mod \
	  $(BIN)/testa_exp_mod $(BIN)/testa_div_by $(BIN)/testa_euc_div \
	  $(BIN)/testa_gcd $(BIN)/testa_linear_comb_gcd $(BIN)/testa_phi \
	  $(BIN)/testa_ord_mod $(BIN)/testa_eh_raiz_prim $(BIN)/testa_simbolo_de_jacobi \

# Alvos
all: $(BIN)/rsa_guess
testes: $(TESTES)

$(BIN)/rsa_guess: $(SRC)/rsa_guess.c $(ALL_OBJ)
	$(CC) $(FLAGS) -o $(BIN)/rsa_guess $(SRC)/rsa_guess.c $(OBJ)/*.o $(LFLAGS)

$(OBJ)/arit_mod.o: $(SRC)/arit_mod.c $(INCLUDE)/arit_mod.h
	$(CC) $(FLAGS) -o $(OBJ)/arit_mod.o -c $(SRC)/arit_mod.c

$(OBJ)/primalidade.o: $(SRC)/primalidade.c $(INCLUDE)/primalidade.h
	$(CC) $(FLAGS) -o $(OBJ)/primalidade.o -c $(SRC)/primalidade.c

$(BIN)/testa_add_mod: $(TESTS)/testa_add_mod.c $(OBJ)/arit_mod.o
	$(CC) $(FLAGS) -o $(BIN)/testa_add_mod $(TESTS)/testa_add_mod.c $(OBJ)/arit_mod.o $(LFLAGS)

$(BIN)/testa_sub_mod: $(TESTS)/testa_sub_mod.c $(OBJ)/arit_mod.o
	$(CC) $(FLAGS) -o $(BIN)/testa_sub_mod $(TESTS)/testa_sub_mod.c $(OBJ)/arit_mod.o $(LFLAGS)

$(BIN)/testa_mul_mod: $(TESTS)/testa_mul_mod.c $(OBJ)/arit_mod.o
	$(CC) $(FLAGS) -o $(BIN)/testa_mul_mod $(TESTS)/testa_mul_mod.c $(OBJ)/arit_mod.o $(LFLAGS)

$(BIN)/testa_exp_mod: $(TESTS)/testa_exp_mod.c $(OBJ)/arit_mod.o
	$(CC) $(FLAGS) -o $(BIN)/testa_exp_mod $(TESTS)/testa_exp_mod.c $(OBJ)/arit_mod.o $(LFLAGS)

$(BIN)/testa_div_by: $(TESTS)/testa_div_by.c $(OBJ)/arit_mod.o
	$(CC) $(FLAGS) -o $(BIN)/testa_div_by $(TESTS)/testa_div_by.c $(OBJ)/arit_mod.o $(LFLAGS)

$(BIN)/testa_euc_div: $(TESTS)/testa_euc_div.c $(OBJ)/arit_mod.o
	$(CC) $(FLAGS) -o $(BIN)/testa_euc_div $(TESTS)/testa_euc_div.c $(OBJ)/arit_mod.o $(LFLAGS)

$(BIN)/testa_gcd: $(TESTS)/testa_gcd.c $(OBJ)/arit_mod.o
	$(CC) $(FLAGS) -o $(BIN)/testa_gcd $(TESTS)/testa_gcd.c $(OBJ)/arit_mod.o $(LFLAGS)

$(BIN)/testa_linear_comb_gcd: $(TESTS)/testa_linear_comb_gcd.c $(OBJ)/arit_mod.o
	$(CC) $(FLAGS) -o $(BIN)/testa_linear_comb_gcd $(TESTS)/testa_linear_comb_gcd.c $(OBJ)/arit_mod.o $(LFLAGS)

$(BIN)/testa_phi: $(TESTS)/testa_phi.c $(OBJ)/arit_mod.o
	$(CC) $(FLAGS) -o $(BIN)/testa_phi $(TESTS)/testa_phi.c $(OBJ)/arit_mod.o $(LFLAGS)

$(BIN)/testa_ord_mod: $(TESTS)/testa_ord_mod.c $(OBJ)/arit_mod.o
	$(CC) $(FLAGS) -o $(BIN)/testa_ord_mod $(TESTS)/testa_ord_mod.c $(OBJ)/arit_mod.o $(LFLAGS)

$(BIN)/testa_eh_raiz_prim: $(TESTS)/testa_eh_raiz_prim.c $(OBJ)/arit_mod.o
	$(CC) $(FLAGS) -o $(BIN)/testa_eh_raiz_prim $(TESTS)/testa_eh_raiz_prim.c $(OBJ)/arit_mod.o $(LFLAGS)

$(BIN)/testa_simbolo_de_jacobi: $(TESTS)/testa_simbolo_de_jacobi.c $(OBJ)/arit_mod.o
	$(CC) $(FLAGS) -o $(BIN)/testa_simbolo_de_jacobi $(TESTS)/testa_simbolo_de_jacobi.c $(OBJ)/arit_mod.o $(LFLAGS)

clean_testes:
	rm -f $(BIN)/testa_*

clean:
	rm -f $(OBJ)/*.o
	rm -f $(BIN)/*
