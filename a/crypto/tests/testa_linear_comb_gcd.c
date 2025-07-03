/**
 * @file   testa_euc_div.c
 * @brief  Testes para calculo de mdc.
 * @author Inaue Ferreira da Silva
 * @date   01-07-2025
 */

#include <stdio.h>
#include <stdlib.h>
#include "../include/arit_mod.h"

int main()
{
	ll coef_a, coef_b;

	linear_comb_gcd(48, 18, &coef_a, &coef_b);
	printf("teste 1: %i\n", coef_a == -1 && coef_b == 3);
	linear_comb_gcd(84, 524, &coef_a, &coef_b);
	printf("teste 2: %i\n", coef_a == 25 && coef_b == -4);
	linear_comb_gcd(35, 143, &coef_a, &coef_b);
	printf("teste 3: %i\n", coef_a == -49 && coef_b == 12);
	
	linear_comb_gcd(48, 0, &coef_a, &coef_b);
	printf("teste 4: %i\n", coef_a == 1 && coef_b == 0);
	linear_comb_gcd(3242543, 1, &coef_a, &coef_b);
	printf("teste 5: %i\n", coef_a == 0 && coef_b == 1);
	linear_comb_gcd(0, 0, &coef_a, &coef_b);
	printf("teste 6: %i\n", coef_a == 1 && coef_b == 0);

	exit(EXIT_SUCCESS);
}
