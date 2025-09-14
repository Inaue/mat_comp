/**
 * @file   testa_coef_mult.c
 * @brief  Testes para o calculo de coeficientes multinomiais
 * @author Inaue Ferreira da Silva
 * @date   2025-09-13
 */

#include <stdio.h>
#include <stdlib.h>
#include "../include/contagem.h"

int main()
{
	ull div1[3] = { 6, 2, 2 };
	ull div2[5] = { 1, 2, 3, 1, 1 };

	printf("teste 1: %i\n", coef_mult(10, 3, div1) == 1260);
	printf("teste 2: %i\n", coef_mult(8, 5, div2)  == 3360);
	printf("teste 3: %i\n", coef_mult(8, 3, div2)  == 0);
	printf("teste 4: %i\n", coef_mult(32, 0, div2) == 1);
	printf("teste 5: %i\n", coef_mult(0, 0, div2)  == 1);

	exit(EXIT_SUCCESS);
}
