/**
 * @file   buscas.c
 * @brief  Implementacao de algoritmos de busca.
 * @author Inaue Ferreira da Silva
 * @date   20-03-2025
 */

#include <stdlib.h>
#include "../include/buscas.h"

/*< Funcoes auxiliares */

void * em_busca (void* vetor, unsigned short i, info_tipo* tipo);

/*< Funcoes de busca */

int arr_linear_search(void* vetor, unsigned short tamanho, void* elemento, info_tipo* tipo)
{
	unsigned short i;

	for(i = 0; i < tamanho; ++i)
	{
		if((*tipo->cmp)(em_busca(vetor, i, tipo), elemento) == 0)
		{
			return i;
		}
	}

	return NAO_ENCONTRADO;
}

void * em_busca(void* vetor, unsigned short i, info_tipo* tipo)
{
	return (void*) ((size_t)vetor + tipo->tamanho * i);
}

int arr_bin_search(void* vetor, unsigned short tamanho, void* elemento, info_tipo* tipo)
{
	if(tamanho == 1)
	{
		if((*tipo->cmp)(vetor, elemento) == 0)
		{
			return 0;
		}
		else
		{
			return NAO_ENCONTRADO;
		}
	}

	unsigned short meio      = tamanho >> 1;
	char           resultado = (*tipo->cmp)(em_busca(vetor, meio, tipo), elemento);
	int            indice;

	if(resultado == 0)
	{
		return meio;
	}
	else if(resultado < 0)
	{
		indice = arr_bin_search(vetor, meio, elemento, tipo);

		if(indice == NAO_ENCONTRADO)
		{
			return NAO_ENCONTRADO;
		}
	}
	else
	{
		indice = arr_bin_search(em_busca(vetor, meio + 1, tipo), tamanho - meio, elemento, tipo);

		if(indice == NAO_ENCONTRADO)
		{
			return NAO_ENCONTRADO;
		}

		indice += meio + 1;
	}

	return indice;
}
