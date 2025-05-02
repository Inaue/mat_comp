/**
 * @file   dec_2_balanced_ternary.c
 * @brief  Conversor de decimal pa ternario balanceado.
 * @author Inaue Ferreira da Silva
 * @date   02-05-2025
 */

#include <stdio.h>
#include <math.h>

#define SUCESSO 0

typedef long long ll;

int  main                           ();
void imprima_em_ternario_balanceado (ll numero);
void divide                         (ll dividendo, ll divisor, ll * quociente, ll * resto);

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
		imprima_em_ternario_balanceado(dec);
		printf("\n");
	}

	return SUCESSO;
}

void divide(ll dividendo, ll divisor, ll * quociente, ll * resto)
{
	*quociente = divisor < 0 ? ceil(1. * dividendo / divisor) : floor(1. * dividendo / divisor);
	*resto     = dividendo - divisor * *quociente;
}

void imprima_em_ternario_balanceado(ll numero)
{
	ll quociente, resto;

	divide(numero, 3, &quociente, &resto);

	if(resto == 2)
	{
		resto = -1;
		++quociente;
	}

	if(numero != 0)
	{
		imprima_em_ternario_balanceado(quociente);
		printf("%lli ", resto);
	}
}

