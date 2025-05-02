/**
 * @file   cantor_expansion.c
 * @brief  Expansao de Cantor.
 * @author Inaue Ferreira da Silva
 * @date   02-05-2025
 */

#include <stdio.h>

#define SUCESSO 0

typedef unsigned long long ull;

int  main                       ();
void imprima_expansao_de_cantor (ull numero);

/**
 * @brief  Rotina Principal.
 * @return Código de erro da execução.
 *
 * Rotina Principal do aplicativo, recebe
 * n e imprime sua expansao de Cantor.
 */

int main()
{
	ull n;

	scanf("%llu", &n);

	if(n == 0)
		printf("0\n");
	else
	{
		imprima_expansao_de_cantor(n);
		printf("\n");
	}

	return SUCESSO;
}

void imprima_expansao_de_cantor(ull numero)
{
	static ull divisor = 1;

	if(numero == 0) return;

	++divisor;
	imprima_expansao_de_cantor(numero / divisor);
	printf("%llu ", numero % divisor);
	--divisor;
}

