/**
 * @file   dec_2_bin.c
 * @brief  Conversor de decimal positivo pa binario.
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
 * decimal e imprime binario.
 */

int main()
{
	ull dec;

	scanf("%llu", &dec);

	printf("%llb\n", dec);
	
	return SUCESSO;
}

