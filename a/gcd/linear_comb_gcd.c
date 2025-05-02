/**
 * @file   linear_comb_gcd.c
 * @brief  Aplicativo de expressar mdc como combinacao linear de dois inteiros.
 * @author Inaue Ferreira da Silva
 * @date   02-05-2025
 */

#include <stdio.h>

#define SUCESSO 0

typedef long long ll;

int  main            ();
void linear_comb_gcd (ll a, ll b, ll * coef_a, ll * coef_b);

/**
 * @brief  Rotina Principal.
 * @return Código de erro da execução.
 *
 * Rotina Principal do aplicativo, recebe
 * a e b e imprime seus respectivos coeficientes.
 */

int main()
{
	ll a, b, coef_a, coef_b;

	scanf("%lli", &a);
	scanf("%lli", &b);

	linear_comb_gcd(a, b, &coef_a, &coef_b);

	printf("%lli %lli\n", coef_a, coef_b);

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

