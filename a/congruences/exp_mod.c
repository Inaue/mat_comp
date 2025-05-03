/**
 * @file   exp_mod.c
 * @brief  Exponenciacao modular de naturais.
 * @author Inaue Ferreira da Silva
 * @date   03-05-2025
 */

#include <stdio.h>

typedef unsigned long long ull;

ull exp_mod (ull base, ull expoente, ull modulo);

/**
 * @brief  operacao de potencia modulo n
 * @param  base     base
 * @param  expoente expoente
 * @param  modulo   modulo
 * @return resultado da operacao
 */

ull exp_mod (ull base, ull expoente, ull modulo)
{
	ull resultado = 1;

	while(expoente != 0)
	{
		if(expoente & 1)
			resultado = (resultado * base) % modulo;

		expoente = expoente >> 1;
		base = (base * base) % modulo;
	}

	return resultado;
}

/**
 * @brief  Rotina Principal.
 * @return Código de erro da execução.
 *
 * Rotina Principal do aplicativo, recebe
 * base, expoente e modulo e retorna a potencia.
 */

int main()
{
	ull base, expoente, modulo;

	scanf("%llu", &base);
	scanf("%llu", &expoente);
	scanf("%llu", &modulo);

	printf("%llu\n", exp_mod(base, expoente, modulo));

	return 0;
}
