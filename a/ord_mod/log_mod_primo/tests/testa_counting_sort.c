/**
 * @file   testa_bubble_sort.c
 * @brief  Testes para o bubble sort.
 * @author Inaue Ferreira da Silva
 * @date   20-03-2025
 */

#include <stdio.h>
#include <stdlib.h>
#include "../include/ordenacoes.h"

char cmp_hu (void* a, void* b);

int main()
{
	info_tipo t_hu = { &cmp_hu, sizeof(unsigned short) };

	unsigned short vhu_1 [] = { 5, 4, 3, 2, 1 };
	unsigned short vhu_2 [] = { 5, 4, 2, 3, 1, 3, 1, 4, 4 };

	printf("teste 1: %i\n", esta_ordenado(vhu_1, 5, &t_hu) == 0);
	printf("teste 2: %i\n", esta_ordenado(vhu_2, 9, &t_hu) == 0);

	bubble_sort(vhu_1, 5, &t_hu);
	bubble_sort(vhu_2, 9, &t_hu);

	printf("teste 3: %i\n", esta_ordenado(vhu_1, 5, &t_hu) == 1);
	printf("teste 4: %i\n", esta_ordenado(vhu_2, 9, &t_hu) == 1);

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

