/**
 * @file   testa_coef_bin.c
 * @brief  Testes para o calculo de coeficientes binomiais
 * @author Inaue Ferreira da Silva
 * @date   2025-09-13
 */

#include <stdio.h>
#include <stdlib.h>
#include "../include/contagem.h"

int main()
{
	printf("teste 1: %i\n", coef_bin(50, 24) == coef_bin(50, 50 - 24));
	printf("teste 2: %i\n", coef_bin(0, 0)    == 1);
	printf("teste 3: %i\n", coef_bin(0, 1)    == 0);
	printf("teste 4: %i\n", coef_bin(3, 0)    == 1);
	printf("teste 5: %i\n", coef_bin(10, 5)   == 252);

	exit(EXIT_SUCCESS);
}
