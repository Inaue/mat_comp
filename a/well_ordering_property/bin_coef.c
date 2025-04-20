/**
 * @file   bin_coef.c
 * @brief  Calculo de coeficientes binomiais.
 * @author Inaue Ferreira da Silva
 * @date   20-05-2025
 */

#include <stdio.h>

#define SUCESSO 0

typedef unsigned long long ull;

int main     ();
ull prod_i   (ull a, ull b);
ull fatorial (ull n);
ull bin_coef (ull a, ull b);

/**
 * @brief  Rotina Principal.
 * @return Código de erro da execução.
 *
 * Rotina Principal do aplicativo, recebe
 * a e b pra calcular ( a b )
 */

int main()
{
	ull a, b;

	scanf("%llu", &a);
	scanf("%llu", &b);

	printf("%llu\n", bin_coef(a, b));

	return SUCESSO;
}

/**
 * @brief  funcao de calcular produtorio de a ate b da expressa i
 * @param  a limite inferior
 * @param  b limite superior
 * @return produto resultante
 */

ull prod_i(ull a, ull b)
{
	ull produto = 1;

	for(ull i = a; i <= b; ++i)
		produto *= i;

	return produto;
}

/**
 * @brief  funcao de calcular fatorial de n
 * @param  n valor de n
 * @return produto resultante
 */

ull fatorial(ull n) { return prod_i(1, n); }

/**
 * @brief  funcao de calcular coeficiente binomial (a b)
 * @param  a valor de a
 * @param  b valor de b
 * @return coeficiente resultante
 */
ull bin_coef(ull a, ull b)
{
	if(a == b || a == 0 || b == 0)
		return 1;

	if(a < b)
	{
		a = a ^ b;
		b = a ^ b;
		a = a ^ b;
	}

	b = b >= a - b ? b : a - b;

	return prod_i(b + 1, a) / fatorial(a - b);
}

