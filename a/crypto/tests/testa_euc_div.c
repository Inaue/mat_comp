/**
 * @file   testa_euc_div.c
 * @brief  Testes para divisao euclidiana.
 * @author Inaue Ferreira da Silva
 * @date   01-07-2025
 */

#include <stdio.h>
#include <stdlib.h>
#include "../include/arit_mod.h"

int main()
{
	ll quociente, resto;

	euclidian_div(263431985301, 809875266, &quociente, &resto);
	printf("teste 1: %i\n", quociente == 325 && resto == 222523851);
	euclidian_div(1057401457177, 573944653, &quociente, &resto);
	printf("teste 2: %i\n", quociente == 1842 && resto == 195406351);
	euclidian_div(101235230344, 132506846, &quociente, &resto);
	printf("teste 3: %i\n", quociente == 764 && resto == 0);
	
	euclidian_div(0, 235, &quociente, &resto);
	printf("teste 4: %i\n", quociente == 0 && resto == 0);
	euclidian_div(34345, 1, &quociente, &resto);
	printf("teste 5: %i\n", quociente == 34345 && resto == 0);
	euclidian_div(-3, -2, &quociente, &resto);
	printf("teste 6: %i\n", quociente == 2 && resto == 1);

	exit(EXIT_SUCCESS);
}

