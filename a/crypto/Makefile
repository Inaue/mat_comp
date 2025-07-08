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
ALL_OBJ = $(OBJ)/primalidade.o $(OBJ)/arit_mod.o $(OBJ)/criptografias.o \
	  $(OBJ)/cliente.o $(OBJ)/servidor.o 
TESTES  = $(BIN)/testa_add_mod $(BIN)/testa_sub_mod $(BIN)/testa_mul_mod \
	  $(BIN)/testa_exp_mod $(BIN)/testa_div_by $(BIN)/testa_euc_div \
	  $(BIN)/testa_gcd $(BIN)/testa_linear_comb_gcd $(BIN)/testa_phi \
	  $(BIN)/testa_ord_mod $(BIN)/testa_eh_raiz_prim $(BIN)/testa_simbolo_de_jacobi \
	  $(BIN)/testa_eh_raiz_prim_phi $(BIN)/testa_encontra_menor_raiz_prim \

# Alvos
all: $(BIN)/rsa_guess $(BIN)/cliente_d_h $(BIN)/servidor_d_h
testes: $(TESTES)

$(BIN)/rsa_guess: $(SRC)/rsa_guess.c $(ALL_OBJ)
	$(CC) $(FLAGS) -o $(BIN)/rsa_guess $(SRC)/rsa_guess.c $(OBJ)/*.o $(LFLAGS)

$(BIN)/cliente_d_h: $(SRC)/cliente_d_h.c $(ALL_OBJ)
	$(CC) $(FLAGS) -o $(BIN)/cliente_d_h $(SRC)/cliente_d_h.c $(OBJ)/*.o $(LFLAGS)

$(BIN)/servidor_d_h: $(SRC)/servidor_d_h.c $(ALL_OBJ)
	$(CC) $(FLAGS) -o $(BIN)/servidor_d_h $(SRC)/servidor_d_h.c $(OBJ)/*.o $(LFLAGS)

$(OBJ)/arit_mod.o: $(SRC)/arit_mod.c $(INCLUDE)/arit_mod.h
	$(CC) $(FLAGS) -o $(OBJ)/arit_mod.o -c $(SRC)/arit_mod.c

$(OBJ)/primalidade.o: $(SRC)/primalidade.c $(INCLUDE)/primalidade.h
	$(CC) $(FLAGS) -o $(OBJ)/primalidade.o -c $(SRC)/primalidade.c

$(OBJ)/criptografias.o: $(SRC)/criptografias.c $(INCLUDE)/criptografias.h
	$(CC) $(FLAGS) -o $(OBJ)/criptografias.o -c $(SRC)/criptografias.c

$(OBJ)/cliente.o: $(SRC)/cliente.c $(INCLUDE)/cliente.h
	$(CC) $(FLAGS) -o $(OBJ)/cliente.o -c $(SRC)/cliente.c

$(OBJ)/servidor.o: $(SRC)/servidor.c $(INCLUDE)/servidor.h
	$(CC) $(FLAGS) -o $(OBJ)/servidor.o -c $(SRC)/servidor.c

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

$(BIN)/testa_eh_raiz_prim_phi: $(TESTS)/testa_eh_raiz_prim_phi.c $(OBJ)/arit_mod.o
	$(CC) $(FLAGS) -o $(BIN)/testa_eh_raiz_prim_phi $(TESTS)/testa_eh_raiz_prim_phi.c $(OBJ)/arit_mod.o $(LFLAGS)

$(BIN)/testa_encontra_menor_raiz_prim: $(TESTS)/testa_encontra_menor_raiz_prim.c $(OBJ)/arit_mod.o
	$(CC) $(FLAGS) -o $(BIN)/testa_encontra_menor_raiz_prim $(TESTS)/testa_encontra_menor_raiz_prim.c $(OBJ)/arit_mod.o $(LFLAGS)

clean_testes:
	rm -f $(BIN)/testa_*

clean:
	rm -f $(OBJ)/*.o
	rm -f $(BIN)/*
