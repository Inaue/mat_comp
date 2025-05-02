/**
 * @file   gcd.c
 * @brief  Aplicativo de calcular mdc
 * @author Inaue Ferreira da Silva
 * @date   02-05-2025
 */

#include <stdio.h>

#define SUCESSO 0

typedef unsigned long long ull;

int main ();
ull gcd (ull a, ull b);
ull min (ull a, ull b);
ull max (ull a, ull b);

/**
 * @brief  Rotina Principal.
 * @return Código de erro da execução.
 *
 * Rotina Principal do aplicativo, recebe
 * a e b e imprime seu mdc.
 */

int main()
{
	ull a, b;

	scanf("%llu", &a);
	scanf("%llu", &b);

	printf("%llu\n", gcd(a, b));

	return SUCESSO;
}

ull gcd (ull a, ull b)
{
	if(a == b)
		return a;

	if(a & 1)
	{
		if(b & 1)
			return gcd(max(a, b) - min(a, b), min(a, b));

		if(b == 0)
			return a;

		return gcd(a, b >> 1);
	}

	if(a == 0)
		return b;

	if(b & 1)
		return gcd(a >> 1, b);

	return gcd(a >> 1, b >> 1) << 1;
}

ull min(ull a, ull b) { return a < b ? a : b; }
ull max(ull a, ull b) { return a > b ? a : b; }

