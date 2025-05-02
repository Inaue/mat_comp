/**
 * @file   bases_converter.c
 * @brief  Conversor de bases inteiras positivas.
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
 * as bases e o inteiro a converter n.
 */

int main()
{
	ull base_1, base_2, n, digito;

	scanf("%llu", &base_1);
	scanf("%llu", &base_2);
	scanf("%llu", &digito);

	n = digito;

	while(getchar() != '\n')
	{
		scanf("%llu", &digito);

		n = n * base_1 + digito;
	}

	ull potencia = 1;

	while(potencia <= n) potencia *= base_2;
	potencia /= base_2;
	
	while(potencia != 0)
	{
		printf("%llu ", n / potencia);
		n %= potencia;
		potencia /= base_2;
	}

	printf("\n");
	
	return SUCESSO;
}

