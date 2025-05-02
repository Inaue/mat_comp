/**
 * @file   bin_2_dec.c
 * @brief  Conversor de binario positivo pa decimal.
 * @author Inaue Ferreira da Silva
 * @date   01-05-2025
 */

#include <stdio.h>

#define SUCESSO 0

typedef unsigned long long ull;

int main ();

/**
 * @brief  Rotina Principal.
 * @return Código de erro da execução.
 *
 * Rotina Principal do aplicativo, recebe
 * binario e imprime decimal.
 */

int main()
{
	ull bin;

	scanf("%llb", &bin);

	printf("%llu\n", bin);
	
	return SUCESSO;
}

