/**
 * @file   testa_gcd.c
 * @brief  Testes para calculo de mdc.
 * @author Inaue Ferreira da Silva
 * @date   01-07-2025
 */

#include <stdio.h>
#include <stdlib.h>
#include "../include/arit_mod.h"

int main()
{
	printf("teste 1: %i\n", gcd(48, 18) == 6);
	printf("teste 2: %i\n", gcd(84, 524) == 4);
	printf("teste 3: %i\n", gcd(35, 143) == 1);
	
	printf("teste 4: %i\n", gcd(48, 0) == 48);
	printf("teste 5: %i\n", gcd(1, 3242543) == 1);
	printf("teste 6: %i\n", gcd(0, 0) == 0);

	exit(EXIT_SUCCESS);
}
