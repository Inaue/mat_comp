/**
 * @file   testa_simbolo_de_jacobi.c
 * @brief  Testes para calculo de simbolo de jacobi.
 * @author Inaue Ferreira da Silva
 * @date   01-07-2025
 */

#include <stdio.h>
#include <stdlib.h>
#include "../include/arit_mod.h"

int main()
{
	printf("teste 1: %i\n", simbolo_de_jacobi(26, 25) == +1);
	printf("teste 2: %i\n", simbolo_de_jacobi(23, 55) == -1);
	printf("teste 3: %i\n", simbolo_de_jacobi(24, 19) == +1);
	printf("teste 4: %i\n", simbolo_de_jacobi(27, 15) ==  0);
	printf("teste 5: %i\n", simbolo_de_jacobi(0, 1)   == +1);
	printf("teste 6: %i\n", simbolo_de_jacobi(0, 17)  ==  0);

	exit(EXIT_SUCCESS);
}
