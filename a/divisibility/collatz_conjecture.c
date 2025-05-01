/**
 * @file   collatz_conjecture.c
 * @brief  Sequencia da conjectura de Collatz.
 * @author Inaue Ferreira da Silva
 * @date   01-05-2025
 */

#include <stdio.h>

#define SUCESSO 0

typedef unsigned long long ull;

int main ();

/**
 * @brief  Rotina Principal.
 * @return Código de erro da execução.
 *
 * Rotina Principal do aplicativo, recebe
 * termo inicial e imprime termos ate 1.
 */

int main()
{
	ull n;

	scanf("%llu", &n);

	if(n == 0)
	{
		return SUCESSO;
	}

	while(n != 1)
	{
		n = n & 1 ? 3 * n + 1 : n >> 1;

		printf("%llu\n", n);
	}
	
	return SUCESSO;
}

