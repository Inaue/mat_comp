/**
 * @file   testa_euc_div.c
 * @brief  Testes para calculo da ordem de um numero modulo outro.
 * @author Inaue Ferreira da Silva
 * @date   01-07-2025
 */

#include <stdio.h>
#include <stdlib.h>
#include "../include/arit_mod.h"

int main()
{
	printf("teste 1: %i\n", ord_mod(9, 7) == 3);
	printf("teste 2: %i\n", ord_mod(2, 11) == 10);
	printf("teste 3: %i\n", ord_mod(846, 77) == 2);
	printf("teste 4: %i\n", ord_mod(16, 561) == 10);
	printf("teste 5: %i\n", ord_mod(3, 5) == 4);
	
	printf("teste 6: %i\n", ord_mod(1, 89234) == 1);
	
	exit(EXIT_SUCCESS);
}
