# Compilador e bandeiras
CC    = gcc
FLAGS = -I$(INCLUDE) -Wall -pedantic -g

# Diretorios
RAIZ    = .
BIN     = $(RAIZ)/bin
INCLUDE = $(RAIZ)/include
OBJ     = $(RAIZ)/obj
SRC     = $(RAIZ)/src
TESTS   = $(RAIZ)/tests
ALL_OBJ = $(OBJ)/ordenacoes.o $(OBJ)/buscas.o $(OBJ)/uteis.o
TESTES  = $(BIN)/testa_esta_ordenado $(BIN)/testa_insertion_sort \
		  $(BIN)/testa_selection_sort $(BIN)/testa_merge_sort \
		  $(BIN)/testa_bubble_sort $(BIN)/testa_counting_sort \
		  $(BIN)/testa_quick_sort $(BIN)/testa_quick_sort_3_ins \
		  $(BIN)/testa_radix_sort \
		  $(BIN)/testa_arr_linear_search $(BIN)/testa_arr_bin_search \
		  $(BIN)/testa_eh_permutacao

# Alvos
all: $(BIN)/log_mod_primo

$(BIN)/log_mod_primo: $(SRC)/main.c $(ALL_OBJ)
	$(CC) $(FLAGS) -o $(BIN)/log_mod_primo $(SRC)/main.c $(OBJ)/*.o -lm

testes: $(TESTES)

$(OBJ)/buscas.o: $(SRC)/buscas.c $(INCLUDE)/buscas.h
	$(CC) $(FLAGS) -o $(OBJ)/buscas.o -c $(SRC)/buscas.c

$(OBJ)/uteis.o: $(SRC)/uteis.c $(INCLUDE)/uteis.h
	$(CC) $(FLAGS) -o $(OBJ)/uteis.o -c $(SRC)/uteis.c

$(OBJ)/ordenacoes.o: $(SRC)/ordenacoes.c $(INCLUDE)/ordenacoes.h
	$(CC) $(FLAGS) -o $(OBJ)/ordenacoes.o -c $(SRC)/ordenacoes.c

$(BIN)/testa_esta_ordenado: $(TESTS)/testa_esta_ordenado.c $(OBJ)/ordenacoes.o $(OBJ)/uteis.o
	$(CC) $(FLAGS) -o $(BIN)/testa_esta_ordenado $(TESTS)/testa_esta_ordenado.c $(OBJ)/ordenacoes.o $(OBJ)/uteis.o

$(BIN)/testa_eh_permutacao: $(TESTS)/testa_eh_permutacao.c $(OBJ)/ordenacoes.o $(OBJ)/uteis.o
	$(CC) $(FLAGS) -o $(BIN)/testa_eh_permutacao $(TESTS)/testa_eh_permutacao.c $(OBJ)/ordenacoes.o $(OBJ)/uteis.o

$(BIN)/testa_insertion_sort: $(TESTS)/testa_insertion_sort.c $(OBJ)/ordenacoes.o $(OBJ)/uteis.o
	$(CC) $(FLAGS) -o $(BIN)/testa_insertion_sort $(TESTS)/testa_insertion_sort.c $(OBJ)/ordenacoes.o $(OBJ)/uteis.o

$(BIN)/testa_selection_sort: $(TESTS)/testa_selection_sort.c $(OBJ)/ordenacoes.o $(OBJ)/uteis.o
	$(CC) $(FLAGS) -o $(BIN)/testa_selection_sort $(TESTS)/testa_selection_sort.c $(OBJ)/ordenacoes.o $(OBJ)/uteis.o

$(BIN)/testa_merge_sort: $(TESTS)/testa_merge_sort.c $(OBJ)/ordenacoes.o $(OBJ)/uteis.o
	$(CC) $(FLAGS) -o $(BIN)/testa_merge_sort $(TESTS)/testa_merge_sort.c $(OBJ)/ordenacoes.o $(OBJ)/uteis.o

$(BIN)/testa_bubble_sort: $(TESTS)/testa_bubble_sort.c $(OBJ)/ordenacoes.o $(OBJ)/uteis.o
	$(CC) $(FLAGS) -o $(BIN)/testa_bubble_sort $(TESTS)/testa_bubble_sort.c $(OBJ)/ordenacoes.o $(OBJ)/uteis.o

$(BIN)/testa_counting_sort: $(TESTS)/testa_counting_sort.c $(OBJ)/ordenacoes.o $(OBJ)/uteis.o
	$(CC) $(FLAGS) -o $(BIN)/testa_counting_sort $(TESTS)/testa_counting_sort.c $(OBJ)/ordenacoes.o $(OBJ)/uteis.o

$(BIN)/testa_radix_sort: $(TESTS)/testa_radix_sort.c $(OBJ)/ordenacoes.o $(OBJ)/uteis.o
	$(CC) $(FLAGS) -o $(BIN)/testa_radix_sort $(TESTS)/testa_radix_sort.c $(OBJ)/ordenacoes.o $(OBJ)/uteis.o

$(BIN)/testa_quick_sort: $(TESTS)/testa_quick_sort.c $(OBJ)/ordenacoes.o $(OBJ)/uteis.o
	$(CC) $(FLAGS) -o $(BIN)/testa_quick_sort $(TESTS)/testa_quick_sort.c $(OBJ)/ordenacoes.o $(OBJ)/uteis.o

$(BIN)/testa_quick_sort_3_ins: $(TESTS)/testa_quick_sort_3_ins.c $(OBJ)/ordenacoes.o $(OBJ)/uteis.o
	$(CC) $(FLAGS) -o $(BIN)/testa_quick_sort_3_ins $(TESTS)/testa_quick_sort_3_ins.c $(OBJ)/ordenacoes.o $(OBJ)/uteis.o

$(BIN)/testa_arr_linear_search: $(TESTS)/testa_arr_linear_search.c $(OBJ)/buscas.o $(OBJ)/uteis.o
	$(CC) $(FLAGS) -o $(BIN)/testa_arr_linear_search $(TESTS)/testa_arr_linear_search.c $(OBJ)/buscas.o $(OBJ)/uteis.o

$(BIN)/testa_arr_bin_search: $(TESTS)/testa_arr_bin_search.c $(OBJ)/buscas.o $(OBJ)/uteis.o
	$(CC) $(FLAGS) -o $(BIN)/testa_arr_bin_search $(TESTS)/testa_arr_bin_search.c $(OBJ)/buscas.o $(OBJ)/uteis.o

clean_obj:
	rm -f $(OBJ)/*.o

clean_bin:
	rm -f $(BIN)/*

clean:
	rm -f $(OBJ)/*.o
	rm -f $(BIN)/*
