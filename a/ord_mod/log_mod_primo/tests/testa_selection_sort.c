/**
 * @file   testa_selection_sort.c
 * @brief  Testes para o selection sort.
 * @author Inaue Ferreira da Silva
 * @date   20-03-2025
 */

#include <stdio.h>
#include <stdlib.h>
#include "../include/ordenacoes.h"

char cmp_int   (void* a, void* b);
char cmp_char  (void* a, void* b);
char cmp_float (void* a, void* b);

int main()
{
	info_tipo t_int   = { &cmp_int, sizeof(int) };
	info_tipo t_float = { &cmp_float, sizeof(float) };
	info_tipo t_char  = { &cmp_char, sizeof(char) };

	int   vi [5]  = { 5, 4, 3, 2, 1 };
	float vf [8]  = { 5.2, 0.0, 67.05, -13.123, 40.4, -34.5, 1.1, 1.1 };
	char  vc [10] = "fleyzvpqna";

	printf("teste 1: %i\n", esta_ordenado(vi, 5, &t_int)   == 0);
	printf("teste 2: %i\n", esta_ordenado(vf, 8, &t_float) == 0);
	printf("teste 3: %i\n", esta_ordenado(vc, 10, &t_char) == 0);

	selection_sort(vi, 5, &t_int);
	selection_sort(vf, 8, &t_float);
	selection_sort(vc, 10, &t_char);

	printf("teste 4: %i\n", esta_ordenado(vi, 5, &t_int)   == 1);
	printf("teste 5: %i\n", esta_ordenado(vf, 8, &t_float) == 1);
	printf("teste 6: %i\n", esta_ordenado(vc, 10, &t_char) == 1);

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

char cmp_char(void* a, void* b)
{
	if(*(char*)a > *(char*)b)
		return -1;

	if(*(char*)a < *(char*)b)
		return +1;

	return 0;
}

char cmp_float(void* a, void* b)
{
	if(*(float*)a > *(float*)b)
		return -1;

	if(*(float*)a < *(float*)b)
		return +1;

	return 0;
}

