/**
 * @file   testa_esta_ordenado.c
 * @brief  Testes para a funcao 'esta_ordenado'.
 * @author Inaue Ferreira da Silva
 * @date   2025-09-13
 */

#include <stdio.h>
#include <stdlib.h>
#include "../include/ordenacoes.h"

char cmp_int (void* a, void* b);
int  num_int (void* v);

int main()
{
	info_tipo t_int = { sizeof(int), &cmp_int, &num_int };

	int v1 [5] = { 1, 2, 3, 4, 5 };
	int v2 [5] = { 1, 2, 2, 7, 7 };
	int v3 [5] = { 9, 2, 3, 4, 5 };
	int v4 [5] = { 5, 4, 3, 2, 1 };
	int v5 [5] = { 0, 0, 0, 0, 0 };

	printf("teste 1: %i\n", esta_ordenado(v1, 5, &t_int) == 1);
	printf("teste 2: %i\n", esta_ordenado(v2, 5, &t_int) == 1);
	printf("teste 3: %i\n", esta_ordenado(v3, 5, &t_int) == 0);
	printf("teste 4: %i\n", esta_ordenado(v4, 5, &t_int) == 0);
	printf("teste 5: %i\n", esta_ordenado(v5, 5, &t_int) == 1);

	exit(EXIT_SUCCESS);
}

char cmp_int(void* a, void* b)
{
	if(*(int*)a > *(int*)b)
		return -1;

	if(*(int*)a < *(int*)b)
		return +1;

	return 0;
}

int num_int(void* v)
{
	return (int)(*(unsigned short*)v);
}

