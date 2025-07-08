/**
 * @file   testa_eh_raiz_prim_phi.c
 * @brief  Testes para verificar se numero eh ou nao raiz prim_phiitiva.
 * @author Inaue Ferreira da Silva
 * @date   07-07-2025
 */

#include <stdio.h>
#include <stdlib.h>
#include "../include/arit_mod.h"

int main()
{
	printf("teste 1: %i\n", !eh_raiz_prim_phi(9, 7, phi(7)));
	printf("teste 2: %i\n", eh_raiz_prim_phi(2, 11, phi(11)));
	printf("teste 3: %i\n", !eh_raiz_prim_phi(846, 77, phi(77)));
	printf("teste 4: %i\n", eh_raiz_prim_phi(3, 5, phi(5)));
	printf("teste 5: %i\n", !eh_raiz_prim_phi(1, 89234, phi(89234)));
	printf("teste 6: %i\n", !eh_raiz_prim_phi(0, 2308401, phi(2308401)));
	
	exit(EXIT_SUCCESS);
}
