/**
 * @file   testa_sub_mod.c
 * @brief  Testes para subtracao modular.
 * @author Inaue Ferreira da Silva
 * @date   01-07-2025
 */

#include <stdio.h>
#include <stdlib.h>
#include "../include/arit_mod.h"

int main()
{
	printf("teste 1: %i\n", sub_mod_ll(-839408297, -880295661, 637090892) == 40887364);
	printf("teste 2: %i\n", sub_mod_ll(666304022, 479912167, 338009195) == 186391855);
	printf("teste 3: %i\n", sub_mod_ll(-560732635, 86342102, 77970010) == -23314657);

	printf("teste 4: %i\n", sub_mod_ll(0, 354, 1000) == -354);
	printf("teste 5: %i\n", sub_mod_ll(0, 0, 54) == 0);
	printf("teste 6: %i\n", sub_mod_ll(-1, +1, 54) == -2);

	printf("teste 7: %i\n", sub_mod_ull(666304022, 479912167, 338009195) == 186391855);
	printf("teste 8: %i\n", sub_mod_ull(0, 0, 54) == 0);

	exit(EXIT_SUCCESS);
}

