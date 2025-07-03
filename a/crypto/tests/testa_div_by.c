/**
 * @file   testa_div_by.c
 * @brief  Testes para divisibilidade
 * @author Inaue Ferreira da Silva
 * @date   01-07-2025
 */

#include <stdio.h>
#include <stdlib.h>
#include "../include/arit_mod.h"

int main()
{
	printf("teste 1: %i\n", divisible_by(-1139168702315, 485786227));
	printf("teste 2: %i\n", !divisible_by(12203926060, 642311706));
	printf("teste 3: %i\n", divisible_by(1108074185688, 376639764));

	printf("teste 4: %i\n", divisible_by(0, 354));
	printf("teste 5: %i\n", divisible_by(23472349, 1));
	printf("teste 6: %i\n", !divisible_by(1, 984834924));

	exit(EXIT_SUCCESS);
}

