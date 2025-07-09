/**
 * @file   pollards_rho.c
 * @brief  Algoritmo de fatoracao Rho de Pollard.
 * @author Inaue Ferreira da Silva
 * @date   08-07-2025
 */

#include <stdio.h>

#define SUCESSO 0

typedef unsigned long long ull;
typedef ull (*poly) (ull x, ull mod);

int main         ();
ull pollards_rho (poly p, ull numero_a_fatorar, ull x0);
ull g            (ull x, ull mod);

ull gcd (ull a, ull b);
ull min (ull a, ull b);
ull max (ull a, ull b);

/**
 * @brief  Rotina Principal.
 * @return Código de erro da execução.
 *
 * Rotina Principal do aplicativo, recebe
 * numero, parametro inicial e
 * imprime fatoracao parcial.
 */

int main()
{
	ull n, x0, fator;

	scanf("%llu", &n);
	scanf("%llu", &x0);

	fator = pollards_rho(&g, n, x0);

	printf("%llu = %llu x %llu\n", n, fator, n / fator);

	return SUCESSO;
}

ull pollards_rho(poly p, ull numero_a_fatorar, ull x0)
{
	ull tartaruga = x0, lebre = x0, fator = 1;

	while(fator == 1)
	{
		tartaruga = (*p)(tartaruga, numero_a_fatorar);
		lebre     = (*p)((*p)(lebre, numero_a_fatorar), numero_a_fatorar);
		fator     = gcd(max(tartaruga, lebre) - min(tartaruga, lebre), numero_a_fatorar);
	}

	return fator;
}

ull g(ull x, ull mod) { return ((x * x) + 1) % mod; }

/**
 * @brief  funcao de calcular mdc
 * @param  a primeiro numero
 * @param  b segundo numero
 * @return mdc
 */

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
