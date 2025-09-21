/**
 * @file   contagem.c
 * @brief  Implementacao de biblioteca pa analise combinatoria
 * @author Inaue Ferreira da Silva
 * @date   2025-09-13
 */

#include <stddef.h>
#include <stdlib.h>
#include <string.h>
#include "../include/contagem.h"
#include "../include/ordenacoes.h"

char cmp_ull (void* a, void* b);
int  num_ull (void* v);

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

	ull         contador           = 1;
	ull         fatorial           = 1;
	ull         multiplicador      = 1;
	ull       * divisoes_ordenadas = malloc(total_de_divisoes * sizeof(ull));
	info_tipo   t_ull              = { sizeof(ull), &cmp_ull, &num_ull };

	memcpy(divisoes_ordenadas, divisoes, total_de_divisoes * sizeof(ull));
	counting_sort(divisoes_ordenadas, total_de_divisoes, &t_ull);

	contador = perm(total, total - divisoes_ordenadas[total_de_divisoes - 1]);

	for (us d = 0; d < total_de_divisoes - 1; ++d) {
	
		while (multiplicador < divisoes_ordenadas[d]) { fatorial *= ++multiplicador; }
		contador /= fatorial;
	}

	free(divisoes_ordenadas);

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

char cmp_ull(void* a, void* b)
{
	if(*(ull*)a > *(ull*)b)
		return -1;

	if(*(ull*)a < *(ull*)b)
		return +1;

	return 0;
}

int num_ull(void* v)
{
	return (int)(*(ull*)v);
}

