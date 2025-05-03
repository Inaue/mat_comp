/**
 * @file   mul_mod.c
 * @brief  Multiplicacao modular de inteiros.
 * @author Inaue Ferreira da Silva
 * @date   03-05-2025
 */

#include <stdio.h>

typedef unsigned long long ull;
typedef long long          ll;

/**
 * @brief  Rotina Principal.
 * @return Código de erro da execução.
 *
 * Rotina Principal do aplicativo, recebe
 * a e b e modulo e retorna a * b (mod n).
 */

int main()
{
	ll a, b, modulo;

	scanf("%lli", &a);
	scanf("%lli", &b);
	scanf("%lli", &modulo);

	printf("%lli\n", (((a * b) % modulo) + modulo) % modulo);

	return 0;
}

