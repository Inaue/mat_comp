/**
 * @file   testa_counting_sort.c
 * @brief  Testes para o counting sort.
 * @author Inaue Ferreira da Silva
 * @date   2025-09-13
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../include/ordenacoes.h"

char cmp_hu (void* a, void* b);
int  num_hu (void* v);

int main()
{
	info_tipo t_hu = { sizeof(unsigned short), &cmp_hu, &num_hu };

	unsigned short vhu_1 [5] = { 5, 4, 3, 2, 1 };
	unsigned short vhu_2 [9] = { 5, 4, 2, 3, 1, 3, 1, 4, 4 };

	unsigned short vhu_1_cp [5];
	unsigned short vhu_2_cp [9];

	memcpy(vhu_1_cp, vhu_1, 5 * sizeof(unsigned short));
	memcpy(vhu_2_cp, vhu_2, 9 * sizeof(unsigned short));

	printf("teste 1: %i\n", esta_ordenado(vhu_1, 5, &t_hu) == 0);
	printf("teste 2: %i\n", esta_ordenado(vhu_2, 9, &t_hu) == 0);

	counting_sort(vhu_1, 5, &t_hu);
	counting_sort(vhu_2, 9, &t_hu);

	printf("teste 3: %i\n", esta_ordenado(vhu_1, 5, &t_hu) == 1);
	printf("teste 4: %i\n", esta_ordenado(vhu_2, 9, &t_hu) == 1);

	printf("teste 5: %i\n", eh_permutacao(vhu_1, vhu_1_cp, 5, &t_hu));
	printf("teste 6: %i\n", eh_permutacao(vhu_2, vhu_2_cp, 9, &t_hu));

	exit(EXIT_SUCCESS);
}

char cmp_hu(void* a, void* b)
{
	if(*(unsigned short*)a > *(unsigned short*)b)
		return -1;

	if(*(unsigned short*)a < *(unsigned short*)b)
		return +1;

	return 0;
}

int num_hu(void* v)
{
	return (int)(*(unsigned short*)v);
}

