/**
 * @file   testa_mul_mod.c
 * @brief  Testes para multiplicacao modular.
 * @author Inaue Ferreira da Silva
 * @date   01-07-2025
 */

#include <stdio.h>
#include <stdlib.h>
#include "../include/arit_mod.h"

int main()
{
	printf("teste 1: %i\n", mul_mod(-839408297, -880295661, 637090892) == 298235209);
	printf("teste 2: %i\n", mul_mod(666304022, 479912167, 338009195) == 139528879);
	printf("teste 3: %i\n", mul_mod(-560732635, 86342102, 77970010) == 13048720);

	printf("teste 4: %i\n", mul_mod(1, 354, 1000) == 354);
	printf("teste 5: %i\n", mul_mod(2342351, 0, 54) == 0);
	printf("teste 6: %i\n", mul_mod(-1, +1, 54) == (54-1));

	exit(EXIT_SUCCESS);
}

