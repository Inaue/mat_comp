/**
 * @file   ord_mod.c
 * @brief  Ordem de a modulo n
 * @author Inaue Ferreira da Silva
 * @date   22-05-2025
 */

#include <stdio.h>

typedef unsigned long long ull;

int main ();

ull gcd (ull a, ull b);
ull min (ull a, ull b);
ull max (ull a, ull b);

ull ord_mod (ull numero, ull modulo);

ull ord_mod(ull numero, ull modulo)
{
	if(gcd(numero, modulo) != 1)
		return 0;

	ull resto, ordem;

	resto = numero % modulo;
	ordem = 1;

	while(resto != 1)
	{
		resto = (resto * numero) % modulo;
		++ordem;
	}

	return ordem;
}

/**
 * @brief  Rotina Principal.
 * @return Código de erro da execução.
 *
 * Rotina Principal do aplicativo, recebe
 * a e n e imprime a ordem de a modulo n.
 */

int main()
{
	ull a, n;

	scanf("%llu", &a);
	scanf("%llu", &n);

	printf("%llu\n", ord_mod(a, n));

	return 0;
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

