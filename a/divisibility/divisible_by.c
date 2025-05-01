/**
 * @file   divisible_by.c
 * @brief  Decidir se um inteiro eh divisivel por outro.
 * @author Inaue Ferreira da Silva
 * @date   01-05-2025
 */

#include <stdio.h>

#define SUCESSO 0

typedef long long ll;

int main         ();
int divisible_by (ll dividend, ll divisor);

/**
 * @brief  Rotina Principal.
 * @return Código de erro da execução.
 *
 * Rotina Principal do aplicativo, recebe
 * a e b pra decidir se a eh divisivel por b.
 */

int main()
{
	ll a, b;

	scanf("%lli", &a);
	scanf("%lli", &b);

	printf("%i\n", divisible_by(a, b));

	return SUCESSO;
}

/**
 * @brief  funcao de decidir se um inteiro divide outro.
 * @param  dividend dividendo
 * @param  divisor divisor
 * @return se eh divisivel ou nao
 */

int divisible_by(ll dividend, ll divisor)
{
	return (dividend / divisor) * divisor == dividend;
}

