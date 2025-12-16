/**
 * @file   mkgen.c
 * @brief  Aplicativo de gerar Makefile
 * @author Inaue Ferreira da Silva
 * @date   2025-12-16
 */

/*< Cabecalhos da Biblioteca Padrao do C */

#include <stdio.h>
#include <string.h>
#include <stdint.h>

/*< Cabecalhos Externos */


/*< Constantes */

#define SUCESSO 0

/*< Tipos */


/*< Rotinas */

int main (int argc, char * argv []);

/**
 * @brief  Rotina principal do aplicativo
 *
 * @param  argc Quantidade de argumentos
 * @param  argv Argumentos
 *
 * @return codigo de erro de execucao, 0 = execucao bem-sucedida
 */
int main (int argc, char * argv []) {

	char apps       [100];
	char modelos    [100];
	char estruturas [100];
	char buffer     [100];

	const char * comeco [] = {
	
		"# Compilador e bandeiras",
		"CC    = gcc",
		"FLAGS = -I$(INCLUDE) -Wall -pedantic -g",
		"# Diretorios",
		"RAIZ    = .",
		"BIN     = $(RAIZ)/bin",
		"INCLUDE = $(RAIZ)/include",
		"OBJ     = $(RAIZ)/obj",
		"SRC     = $(RAIZ)/src",
		"",
		"# Objetos",
		NULL,
	};

	const char * meio [] = {

		"",
		"# Limpeza",
		"clean:",
		"	rm -rf $(BIN) $(OBJ)",
		"",
		"# Diretorios",
		"$(BIN):",
		"	mkdir $(BIN)",
		"",
		"$(OBJ):",
		"	mkdir $(OBJ)",
		"",
		NULL,
	};

	fgets(apps, 100, stdin);
	apps[strlen(apps) - 1] = '\0';

	fgets(modelos, 100, stdin);
	modelos[strlen(modelos) - 1] = '\0';

	fgets(estruturas, 100, stdin);
	estruturas[strlen(estruturas) - 1] = '\0';

	for (uint8_t i = 0; comeco[i]; ++i) {
	
		printf("%s\n", comeco[i]);
	}

	printf("MODELO_OBJ     =");

	strcpy(buffer, modelos);
	char * modelo = strtok(buffer, " ");

	while(modelo) {

		printf(" $(OBJ)/%s.o", modelo);
		modelo = strtok(NULL, " ");
	}

	fputc('\n', stdout);

	printf("ESTRUTURAS_OBJ =");

	strcpy(buffer, estruturas);
	char * estrutura = strtok(buffer, " ");

	while(estrutura) {

		printf(" $(OBJ)/%s.o", estrutura);
		estrutura = strtok(NULL, " ");
	}

	fputc('\n', stdout);
	fputc('\n', stdout);
	printf("# Alvos\n");
	printf("# Todos\n");
	printf("all:");

	strcpy(buffer, apps);
	char * app = strtok(buffer, " ");

	while(app) {

		printf(" $(BIN)/%s", app);
		app = strtok(NULL, " ");
	}

	fputc('\n', stdout);

	for (uint8_t i = 0; meio[i]; ++i) {
	
		printf("%s\n", meio[i]);
	}

	strcpy(buffer, apps);
	app = strtok(buffer, " ");
	printf("# Aplicativos\n");

	while(app) {

		printf("$(BIN)/%s: $(SRC)/%s.c $(MODELO_OBJ) $(ESTRUTURAS_OBJ) $(BIN)\n", app, app);
		printf("	$(CC) $(FLAGS) -o $(BIN)/%s $(SRC)/%s.c $(MODELO_OBJ) $(ESTRUTURAS_OBJ)\n", app, app);
		fputc('\n', stdout);
		app = strtok(NULL, " ");
	}

	strcpy(buffer, modelos);
	modelo = strtok(buffer, " ");
	printf("# Modelos\n");

	while(modelo) {

		printf("$(OBJ)/%s.o: $(SRC)/%s.c $(INCLUDE)/%s.h $(OBJ)\n", modelo, modelo, modelo);
		printf("	$(CC) $(FLAGS) -o $(OBJ)/%s.o -c $(SRC)/%s.c\n", modelo, modelo);
		fputc('\n', stdout);
		modelo = strtok(NULL, " ");
	}

	strcpy(buffer, estruturas);
	estrutura = strtok(buffer, " ");
	printf("# Estruturas\n");

	while(estrutura) {

		printf("$(OBJ)/%s.o: $(SRC)/%s.c $(INCLUDE)/%s.h $(OBJ)\n", estrutura, estrutura, estrutura);
		printf("	$(CC) $(FLAGS) -o $(OBJ)/%s.o -c $(SRC)/%s.c\n", estrutura, estrutura);
		fputc('\n', stdout);
		estrutura = strtok(NULL, " ");
	}
	
	return SUCESSO;
}

