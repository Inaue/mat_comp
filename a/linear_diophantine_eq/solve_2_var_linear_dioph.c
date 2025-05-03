/**
 * @file   solve_2_var_linear_dioph.c
 * @brief  Aplicativo de resolver equacao linear diofantina de 2 variaveis.
 * @author Inaue Ferreira da Silva
 * @date   02-05-2025
 */

#include <stdio.h>

#define SUCESSO 0

typedef long long ll;

int  main            ();
void linear_comb_gcd (ll a, ll b, ll * coef_a, ll * coef_b);
int divisible_by     (ll dividend, ll divisor);

/**
 * @brief  Rotina Principal.
 * @return Código de erro da execução.
 *
 * Rotina Principal do aplicativo, recebe
 * coeficientes a e b e termo independente
 * n e imprime uma solucao se existir.
 */

int main()
{
	ll a, b, n, coef_a, coef_b;

	scanf("%lli", &a);
	scanf("%lli", &b);
	scanf("%lli", &n);

	linear_comb_gcd(a, b, &coef_a, &coef_b);

	ll mdc = coef_a * a + coef_b * b;

	if(divisible_by(n, mdc))
	{
		ll fator = n / mdc;

		printf("%lli %lli\n", coef_a * fator, coef_b * fator);
	}

	return SUCESSO;
}

void linear_comb_gcd(ll a, ll b, ll * coef_a, ll * coef_b)
{
	if(b == 0)
	{
		*coef_a = 1;
		*coef_b = 0;
	}
	else
	{
		ll tmp_a, tmp_b, quociente;

		quociente = a / b;
		linear_comb_gcd(b, a % b, &tmp_a, &tmp_b);
		*coef_a = tmp_b;
		*coef_b = tmp_a - quociente * tmp_b;
	}
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

