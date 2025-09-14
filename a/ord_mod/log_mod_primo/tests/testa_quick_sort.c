/**
 * @file   testa_quick_sort.c
 * @brief  Testes para o quick sort.
 * @author Inaue Ferreira da Silva
 * @date   2025-09-13
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../include/ordenacoes.h"

char cmp_int   (void* a, void* b);
char cmp_char  (void* a, void* b);
char cmp_float (void* a, void* b);
int  num_int   (void* v);
int  num_float (void* v);
int  num_char  (void* v);

int main()
{
	info_tipo t_int   = { sizeof(int), &cmp_int, &num_int };
	info_tipo t_float = { sizeof(float), &cmp_float, &num_float };
	info_tipo t_char  = { sizeof(char), &cmp_char, &num_char };

	int   vi [5]  = { 5, 4, 3, 2, 1 };
	float vf [8]  = { 5.2, 0.0, 67.05, -13.123, 40.4, -34.5, 1.1, 1.1 };
	char  vc [10] = "fleyzvpqna";

	int   vi_cp [5];
	float vf_cp [8];
	char  vc_cp [10];

	memcpy(vi_cp, vi, 5 * sizeof(int));
	memcpy(vf_cp, vf, 8 * sizeof(float));
	memcpy(vc_cp, vc, 10 * sizeof(char));

	printf("teste 1: %i\n", esta_ordenado(vi, 5, &t_int)   == 0);
	printf("teste 2: %i\n", esta_ordenado(vf, 8, &t_float) == 0);
	printf("teste 3: %i\n", esta_ordenado(vc, 10, &t_char) == 0);

	quick_sort(vi, 5, &t_int);
	quick_sort(vf, 8, &t_float);
	quick_sort(vc, 10, &t_char);

	printf("teste 4: %i\n", esta_ordenado(vi, 5, &t_int)   == 1);
	printf("teste 5: %i\n", esta_ordenado(vf, 8, &t_float) == 1);
	printf("teste 6: %i\n", esta_ordenado(vc, 10, &t_char) == 1);

	printf("teste 7: %i\n", eh_permutacao(vi, vi_cp, 5, &t_int));
	printf("teste 8: %i\n", eh_permutacao(vf, vf_cp, 8, &t_float));
	printf("teste 9: %i\n", eh_permutacao(vc, vc_cp, 10, &t_char));

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

int num_int(void* v)
{
	return (int)(*(unsigned short*)v);
}

int num_float(void* v)
{
	return (int)(*(float*)v);
}

int num_char(void* v)
{
	return (int)(*(char*)v);
}
