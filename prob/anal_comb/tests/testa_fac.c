/**
 * @file   testa_fac.c
 * @brief  Testes para o calculo de fatorial
 * @author Inaue Ferreira da Silva
 * @date   2025-09-13
 */

#include <stdio.h>
#include <stdlib.h>
#include "../include/contagem.h"

int main()
{
	printf("teste 1: %i\n", fac(0)  == 1);
	printf("teste 2: %i\n", fac(1)  == 1);
	printf("teste 3: %i\n", fac(2)  == 2);
	printf("teste 4: %i\n", fac(3)  == 6);
	printf("teste 5: %i\n", fac(10) == 3628800);

	exit(EXIT_SUCCESS);
}
