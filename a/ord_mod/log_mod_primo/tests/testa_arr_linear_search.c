/**
 * @file   testa_arr_linear_search.c
 * @brief  Testes para a busca linear em vetores.
 * @author Inaue Ferreira da Silva
 * @date   18-03-2025
 */

#include <stdio.h>
#include <stdlib.h>
#include "../include/buscas.h"

char cmp_int (void* a, void* b);

int main()
{
	info_tipo t_int = { &cmp_int, sizeof(int) };

	int v [5] = { 5, 4, 3, 2, 1 };
	int elemento_inexistente = 6;

	printf("teste 1: %i\n", arr_linear_search(v, 5, &v[4], &t_int) == 4);
	printf("teste 2: %i\n", arr_linear_search(v, 5, &v[3], &t_int) == 3);
	printf("teste 3: %i\n", arr_linear_search(v, 5, &v[2], &t_int) == 2);
	printf("teste 4: %i\n", arr_linear_search(v, 5, &v[1], &t_int) == 1);
	printf("teste 5: %i\n", arr_linear_search(v, 5, &v[0], &t_int) == 0);
	printf("teste 6: %i\n", arr_linear_search(v, 5, &elemento_inexistente, &t_int) == NAO_ENCONTRADO);

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
