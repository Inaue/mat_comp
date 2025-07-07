/**
 * @file   testa_eh_raiz_prim.c
 * @brief  Testes para verificar se numero eh ou nao raiz primitiva.
 * @author Inaue Ferreira da Silva
 * @date   01-07-2025
 */

#include <stdio.h>
#include <stdlib.h>
#include "../include/arit_mod.h"

int main()
{
	printf("teste 1: %i\n", !eh_raiz_prim(9, 7));
	printf("teste 2: %i\n", eh_raiz_prim(2, 11));
	printf("teste 3: %i\n", !eh_raiz_prim(846, 77));
	printf("teste 4: %i\n", eh_raiz_prim(3, 5));
	printf("teste 5: %i\n", !eh_raiz_prim(1, 89234));
	printf("teste 6: %i\n", !eh_raiz_prim(0, 2308401));
	
	exit(EXIT_SUCCESS);
}
