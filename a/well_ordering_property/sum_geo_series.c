/**
 * @file   sum_geo_series.c
 * @brief  Somador de termos de serie geometrica de 0 ate n.
 * @author Inaue Ferreira da Silva
 * @date   20-05-2025
 */

#include <stdio.h>
#include <math.h>

#define SUCESSO 0

int main ();

/**
 * @brief  Rotina Principal.
 * @return Código de erro da execução.
 *
 * Rotina Principal do aplicativo, recebe
 * termo inicial, razao e limite superior.
 */

int main()
{
	float a0, r, soma;
	unsigned char n;

	scanf("%f", &a0);
	scanf("%f", &r);
	scanf("%hhu", &n);

	soma = r == 1 ? a0 * (n + 1) : a0 * (powf(r, n+1) - 1) / (r - 1);

	printf("%f\n", soma);

	return SUCESSO;
}
 
