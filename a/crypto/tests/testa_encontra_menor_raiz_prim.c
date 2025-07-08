/**
 * @file   testa_encontra_menor_raiz_prim.c
 * @brief  Testes para encontrar menor raiz primitiva.
 * @author Inaue Ferreira da Silva
 * @date   07-07-2025
 */

#include <stdio.h>
#include <stdlib.h>
#include "../include/arit_mod.h"

int main()
{
	printf("teste 1: %i\n", encontra_menor_raiz_prim(7)     == 3);
	printf("teste 2: %i\n", encontra_menor_raiz_prim(23)    == 5);
	printf("teste 3: %i\n", encontra_menor_raiz_prim(41)    == 6);
	printf("teste 4: %i\n", encontra_menor_raiz_prim(83)    == 2);
	printf("teste 5: %i\n", encontra_menor_raiz_prim(101)   == 2);
	printf("teste 6: %i\n", encontra_menor_raiz_prim(10201) == 2);
	
	exit(EXIT_SUCCESS);
}
