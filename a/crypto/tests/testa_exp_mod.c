/**
 * @file   testa_exp_mod.c
 * @brief  Testes para exponenciacao modular.
 * @author Inaue Ferreira da Silva
 * @date   01-07-2025
 */

#include <stdio.h>
#include <stdlib.h>
#include "../include/arit_mod.h"

int main()
{
	printf("teste 1: %i\n", exp_mod_ull(2309875, 6, 7) == 1);
	printf("teste 2: %i\n", exp_mod_ull(1298332, 11, 23) == (23-1));
	printf("teste 3: %i\n", exp_mod_ull(218394, 2357953, 97) == 47);

	printf("teste 4: %i\n", exp_mod_ull(0, 354, 1000) == 0);
	printf("teste 5: %i\n", exp_mod_ull((54-1), 2359, 54) == (54-1));
	printf("teste 6: %i\n", exp_mod_ull(1, 325355, 54) == 1);

	printf("teste 7: %i\n", exp_mod_ll(-1, 2359, 54) == -1);
	printf("teste 8: %i\n", exp_mod_ll(218394, 2357953, 97) == 47);

	exit(EXIT_SUCCESS);
}

