/**
 * @file   lcm_from_factorization.c
 * @brief  Encontra mmc a partir de fatoracao.
 * @author Inaue Ferreira da Silva
 * @date   02-05-2025
 */

#include <stdio.h>
#include <stdlib.h>

#define SUCESSO 0

typedef unsigned long long ull;
typedef unsigned long      ul;
typedef unsigned short     us;

int main ();
ull max  (ull a, ull b);

/**
 * @brief  Rotina Principal.
 * @return Código de erro da execução.
 *
 * Rotina Principal do aplicativo, recebe
 * total de primos, primos, expoentes e
 * imprime o mmc.
 */

int main()
{
	us n;
	ul * primos;
	us * expoentes_1, * expoentes_2;

	scanf("%hu", &n);

	primos      = (ul *) malloc(sizeof(ul) * n);
	expoentes_1 = (us *) malloc(sizeof(us) * n);
	expoentes_2 = (us *) malloc(sizeof(us) * n);

	for(ul i = 0; i < n; ++i)
		scanf("%lu", &primos[i]);

	for(ul i = 0; i < n; ++i)
		scanf("%hu", &expoentes_1[i]);

	for(ul i = 0; i < n; ++i)
		scanf("%hu", &expoentes_2[i]);

	ull mmc = 1;

	for(us i = 0; i < n; ++i)
	{
		us expoente = max(expoentes_1[i], expoentes_2[i]);

		for(us e = 0; e < expoente; ++e)
			mmc *= primos[i];
	}

	printf("%llu\n", mmc);

	free(primos);
	free(expoentes_1);
	free(expoentes_2);

	return SUCESSO;
}

ull max(ull a, ull b) { return a > b ? a : b; }

