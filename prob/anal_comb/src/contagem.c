/**
 * @file   contagem.c
 * @brief  Implementacao de biblioteca pa analise combinatoria
 * @author Inaue Ferreira da Silva
 * @date   2025-09-13
 */

#include <stddef.h>
#include "../include/contagem.h"

/**
 * @brief  aplicacao do principio fundamental da contagem
 * @param  eventos        total de eventos
 * @param  possibilidades total de possibilidades de cada evento
 * @return total de possibilidades de todos os eventos
 */

ull mul(us eventos, ull * possibilidades)
{
	if(eventos == 0 || possibilidades == NULL)
		return 1;

	ull contador = 1;

	for (us i = 0; i < eventos; ++i) {

		contador *= possibilidades[i];
	}

	return contador;
}

ull fac(ull n)
{
	ull contador;

	for (contador = 1; n > 1; contador *= n, --n);

	return contador;
}

ull perm(ull total, ull escolhidos)
{
	if(total < escolhidos)
		return 0;

	ull contador = 1;

	for (ull i = total; i > total - escolhidos; --i) {
	
		contador *= i;
	}

	return contador;
}

ull coef_mult(ull total, us total_de_divisoes, ull * divisoes)
{
	if(total_de_divisoes == 0 || divisoes == NULL)
		return 1;

	ull soma_das_dividoes = 0;

	for (us d = 0; d < total_de_divisoes; ++d) {
	
		soma_das_dividoes += divisoes[d];
	}

	if(soma_das_dividoes != total)
		return 0;

	ull contador = 1;

	contador = fac(total);

	for (us d = 0; d < total_de_divisoes; ++d) {
	
		contador /= fac(divisoes[d]);
	}

	return contador;
}

ull coef_bin(ull total, ull escolhidos)
{
	if(total < escolhidos)
		return 0;

	ull divisoes[2] = { escolhidos, total - escolhidos };

	return coef_mult(total, 2, divisoes);
}

ull potencia(ull base, uc expoente)
{
	ull contador = 1;

	for (; expoente > 0; contador *= base, --expoente);
	
	return contador;
}

