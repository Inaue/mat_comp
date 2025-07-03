/**
 * @file   testa_euc_div.c
 * @brief  Testes para calculo da funcao phi de Euler.
 * @author Inaue Ferreira da Silva
 * @date   01-07-2025
 */

#include <stdio.h>
#include <stdlib.h>
#include "../include/arit_mod.h"

int main()
{
	printf("teste 1: %i\n", phi(7) == 6);
	printf("teste 2: %i\n", phi(2401) == 2058);
	printf("teste 3: %i\n", phi(143) == 120);

	printf("teste 4: %i\n", phi(1) == 0);
	printf("teste 5: %i\n", phi(0) == 0);
	printf("teste 6: %i\n", phi(2) == 1);
	
	exit(EXIT_SUCCESS);
}
