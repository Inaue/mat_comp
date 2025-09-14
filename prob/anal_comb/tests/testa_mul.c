/**
 * @file   testa_mul.c
 * @brief  Testes para o principio fundamental da contagem
 * @author Inaue Ferreira da Silva
 * @date   2025-09-13
 */

#include <stdio.h>
#include <stdlib.h>
#include "../include/contagem.h"

int main()
{
	ull p1[1] = { 491 };
	ull p2[2] = { 50, 10 };
	ull p3[3] = { 3, 4, 5 };
	ull p4[3] = { 3, 0, 5 };

	printf("teste 1: %i\n", mul(0, p1)   == 1);
	printf("teste 2: %i\n", mul(5, NULL) == 1);
	printf("teste 3: %i\n", mul(1, p1)   == 491);
	printf("teste 4: %i\n", mul(2, p2)   == 500);
	printf("teste 5: %i\n", mul(3, p3)   == 60);
	printf("teste 6: %i\n", mul(3, p4)   == 0);

	exit(EXIT_SUCCESS);
}
