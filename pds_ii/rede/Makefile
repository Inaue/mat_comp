# Compilador e bandeiras
CXXC  = g++
FLAGS = -std=c++11 -I$(INCLUDE) -Wall -pedantic -g

# Diretorios
RAIZ    = .
BIN     = $(RAIZ)/bin
SRC     = $(RAIZ)/src
INCLUDE = $(RAIZ)/include
OBJ     = $(RAIZ)/obj
ALL_OBJ = $(OBJ)/Cliente.o $(OBJ)/Servidor.o

# Alvos
all: $(BIN)/cliente $(BIN)/servidor

$(BIN)/cliente: $(SRC)/cliente.cpp $(OBJ)/Cliente.o
	$(CXXC) $(FLAGS) -o $(BIN)/cliente $(SRC)/cliente.cpp $(OBJ)/Cliente.o

$(BIN)/servidor: $(SRC)/servidor.cpp $(OBJ)/Servidor.o
	$(CXXC) $(FLAGS) -o $(BIN)/servidor $(SRC)/servidor.cpp $(OBJ)/Servidor.o

$(OBJ)/Cliente.o: $(SRC)/Cliente.cpp $(INCLUDE)/Cliente.hpp
	$(CXXC) $(FLAGS) -o $(OBJ)/Cliente.o -c $(SRC)/Cliente.cpp

$(OBJ)/Servidor.o: $(SRC)/Servidor.cpp $(INCLUDE)/Servidor.hpp
	$(CXXC) $(FLAGS) -o $(OBJ)/Servidor.o -c $(SRC)/Servidor.cpp

clean:
	rm -rf obj/*
	rm -rf bin/*
