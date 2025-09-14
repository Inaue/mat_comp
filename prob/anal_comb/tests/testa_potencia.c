/**
 * @file   testa_potencia.c
 * @brief  Testes para o calculo de potenciacao
 * @author Inaue Ferreira da Silva
 * @date   2025-09-13
 */

#include <stdio.h>
#include <stdlib.h>
#include "../include/contagem.h"

int main()
{
	printf("teste 1: %i\n", potencia(0, 0)  == 1);
	printf("teste 2: %i\n", potencia(45, 0) == 1);
	printf("teste 3: %i\n", potencia(2, 10) == 1024);
	printf("teste 4: %i\n", potencia(0, 10) == 0);

	exit(EXIT_SUCCESS);
}
