/**
 * @file   uteis.c
 * @brief  Implementacao de algoritmos auxiliares para outras bibliotecas.
 * @author Inaue Ferreira da Silva
 * @date   2025-09-13
 */

#include <string.h>
#include "../include/uteis.h"

void * em(void* vetor, unsigned short i, info_tipo* tipo)
{
	return (void*) ((size_t)vetor + tipo->tamanho * i);
}

void swap(void* valor_1, void* valor_2, info_tipo* tipo)
{
	void * temp = malloc(sizeof(tipo->tamanho));
	
	if(temp == NULL)
		return;

	memcpy(temp, valor_2, tipo->tamanho);
	memcpy(valor_2, valor_1, tipo->tamanho);
	memcpy(valor_1, temp, tipo->tamanho);

	free(temp);
}

