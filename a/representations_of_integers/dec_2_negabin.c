/**
 * @file   dec_2_negabin.c
 * @brief  Conversor de decimal pa negabinario.
 * @author Inaue Ferreira da Silva
 * @date   02-05-2025
 */

#include <stdio.h>
#include <math.h>

#define SUCESSO 0

typedef long long ll;

int  main            ();
void imprima_na_base (ll base, ll numero);
void divide          (ll dividendo, ll divisor, ll * quociente, ll * resto);

/**
 * @brief  Rotina Principal.
 * @return Código de erro da execução.
 *
 * Rotina Principal do aplicativo, recebe
 * decimal e imprime negabinario.
 */

int main()
{
	ll dec;

	scanf("%lli", &dec);

	if(dec == 0)
		printf("0\n");
	else
	{
		imprima_na_base(-2, dec);
		printf("\n");
	}

	return SUCESSO;
}

void divide(ll dividendo, ll divisor, ll * quociente, ll * resto)
{
	*quociente = divisor < 0 ? ceil(1. * dividendo / divisor) : floor(1. * dividendo / divisor);
	*resto     = dividendo - divisor * *quociente;
}

void imprima_na_base(ll base, ll numero)
{
	ll quociente, resto;

	divide(numero, base, &quociente, &resto);

	if(numero != 0)
	{
		imprima_na_base(base, quociente);
		printf("%lli ", resto);
	}
}

