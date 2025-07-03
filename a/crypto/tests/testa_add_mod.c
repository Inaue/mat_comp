/**
 * @file   testa_add_mod.c
 * @brief  Testes para adicao modular.
 * @author Inaue Ferreira da Silva
 * @date   01-07-2025
 */

#include <stdio.h>
#include <stdlib.h>
#include "../include/arit_mod.h"

int main()
{
	printf("teste 1: %i\n", add_mod(-839408297, -880295661, 637090892) == 191568718);
	printf("teste 2: %i\n", add_mod(666304022, 479912167, 338009195) == 132188604);
	printf("teste 3: %i\n", add_mod(-560732635, 86342102, 77970010) == 71399537);

	printf("teste 4: %i\n", add_mod(0, 354, 1000) == 354);
	printf("teste 5: %i\n", add_mod(0, 0, 54) == 0);
	printf("teste 6: %i\n", add_mod(-1, +1, 54) == 0);

	exit(EXIT_SUCCESS);
}

