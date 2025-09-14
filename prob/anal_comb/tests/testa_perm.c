/**
 * @file   testa_perm.c
 * @brief  Testes para a contagem de permutacoes
 * @author Inaue Ferreira da Silva
 * @date   2025-09-13
 */

#include <stdio.h>
#include <stdlib.h>
#include "../include/contagem.h"

int main()
{
	printf("teste 1: %i\n", perm(0, 0)  == 1);
	printf("teste 2: %i\n", perm(0, 1)  == 0);
	printf("teste 3: %i\n", perm(5, 1)  == 5);
	printf("teste 4: %i\n", perm(10, 5) == 30240);
	printf("teste 5: %i\n", perm(4, 4)  == 24);

	exit(EXIT_SUCCESS);
}
