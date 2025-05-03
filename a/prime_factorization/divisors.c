/**
 * @file   divisors.c
 * @brief  Divisores a partir de fatoracao.
 * @author Inaue Ferreira da Silva
 * @date   02-05-2025
 */

#include <stdio.h>
#include <stdlib.h>

#define SUCESSO 0

typedef unsigned long long ull;
typedef unsigned long      ul;
typedef unsigned short     us;

int  main ();
void imprima_divisores (ul divisores[], us expoentes[], us primo, ull divisor_parcial);

/**
 * @brief  Rotina Principal.
 * @return Código de erro da execução.
 *
 * Rotina Principal do aplicativo, recebe
 * total de primos, primos e expoente e
 * imprime os divisores do inteiro.
 */

int main()
{
	us n;
	ul * primos;
	us * expoentes;

	scanf("%hu", &n);

	primos    = (ul *) malloc(sizeof(ul) * n);
	expoentes = (us *) malloc(sizeof(us) * n);

	for(ul i = 0; i < n; ++i)
		scanf("%lu", &primos[i]);

	for(ul i = 0; i < n; ++i)
		scanf("%hu", &expoentes[i]);

	imprima_divisores(primos, expoentes, n - 1, 1);

	free(primos);
	free(expoentes);

	return SUCESSO;
}

void imprima_divisores (ul primos[], us expoentes[], us primo, ull divisor_parcial)
{
	if(primo == 0)
	{
		for(us e = 0; e <= expoentes[primo]; ++e, divisor_parcial *= primos[primo])
		{
			printf("%llu\n", divisor_parcial);
		}

		return;
	}

	for(us e = 0; e <= expoentes[primo]; ++e, divisor_parcial *= primos[primo])
	{
		imprima_divisores(primos, expoentes, primo - 1, divisor_parcial);
	}
}

