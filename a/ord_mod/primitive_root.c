/**
 * @file   primitive_root.c
 * @brief  Descoberta das raizes primitivas de n
 * @author Inaue Ferreira da Silva
 * @date   22-05-2025
 */

#include <stdio.h>

#define VERDADEIRO (1 == 1)
#define FALSO      !VERDADEIRO

typedef unsigned long long ull;

int main ();

ull gcd (ull a, ull b);
ull min (ull a, ull b);
ull max (ull a, ull b);

ull  phi          (ull numero);
ull  ord_mod      (ull numero, ull modulo);
char eh_raiz_prim (ull numero, ull modulo);

ull phi(ull numero)
{
	ull invertiveis = 0;

	for(ull i = 1; i < numero; ++i)
	{
		if(gcd(i, numero) == 1)
			++invertiveis;
	}

	return invertiveis;
}

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

char eh_raiz_prim(ull numero, ull modulo)
{
	if(gcd(numero, modulo) != 1)
		return FALSO;

	return ord_mod(numero, modulo) == phi(modulo);
}

/**
 * @brief  Rotina Principal.
 * @return Código de erro da execução.
 *
 * Rotina Principal do aplicativo, recebe
 * modulo e imprime suas raizes primitivas.
 */

int main()
{
	ull modulo;

	scanf("%llu", &modulo);

	for(ull numero = 1; numero < modulo; ++numero)
	{
		if(eh_raiz_prim(numero, modulo))
			printf("%llu\n", numero);
	}

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

