/**
 * @file   division.c
 * @brief  Executar divisao euclidiana.
 * @author Inaue Ferreira da Silva
 * @date   01-05-2025
 */

#include <stdio.h>
#include <math.h>

#define SUCESSO 0

typedef long long ll;

int main ();

/**
 * @brief  Rotina Principal.
 * @return Código de erro da execução.
 *
 * Rotina Principal do aplicativo, recebe
 * a e b e divide a por b.
 */

int main()
{
	ll a, b, q, r;

	scanf("%lli", &a);
	scanf("%lli", &b);

	q = b < 0 ? ceil(1. * a / b) : floor(1. * a / b);
	r = a - b * q;

	printf("%lli\n", q);
	printf("%lli\n", r);

	return SUCESSO;
}

