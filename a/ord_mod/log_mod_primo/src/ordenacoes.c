/**
 * @file   ordenacoes.c
 * @brief  Implementacao de algoritmos de ordenacao.
 * @author Inaue Ferreira da Silva
 * @date   12-05-2025
 */

#include <stdlib.h>
#include <string.h>
#include "../include/ordenacoes.h"
#include "../include/uteis.h"

/*< Funcoes auxiliares */

void   merge        (void* vetor, unsigned short meio, unsigned short tamanho, info_tipo* tipo);
void * mediana_de_3 (void* a, void* b, void* c, info_tipo* tipo);
void   particiona   (void* vetor, int tamanho, unsigned short *meio, info_tipo* tipo);
void   particiona_3 (void* vetor, int tamanho, unsigned short *meio, info_tipo* tipo);

/*< Funcoes de ordenacao */

void insertion_sort(void* vetor, unsigned short tamanho, info_tipo* tipo)
{
	void * chave = malloc(tipo->tamanho);

	if(chave == NULL)
		return;

	unsigned short i, j;

	for(i = 1; i < tamanho; ++i)
	{
		memcpy(chave, em(vetor, i, tipo), tipo->tamanho);
		j = i;

		while(j > 0 && (*tipo->cmp)(em(vetor, j - 1, tipo), chave) < 0)
		{
			memcpy(em(vetor, j, tipo), em(vetor, j - 1, tipo), tipo->tamanho);
			--j;
		}

		memcpy(em(vetor, j, tipo), chave, tipo->tamanho);
	}

	free(chave);
}

void selection_sort(void* vetor, unsigned short tamanho, info_tipo* tipo)
{
	unsigned short i, j, menor;

	for(i = 0; i < tamanho - 1; ++i)
	{
		menor = i;

		for(j = i + 1; j < tamanho; ++j)
		{
			if((*tipo->cmp)(em(vetor, j, tipo), em(vetor, menor, tipo)) > 0)
			{
				menor = j;
			}
		}

		swap(em(vetor, i, tipo), em(vetor, menor, tipo), tipo);
	}
}

char esta_ordenado(void* vetor, unsigned short tamanho, info_tipo* tipo)
{
	unsigned short i;

	for(i = 1; i < tamanho; ++i)
	{
		if(tipo->cmp(em(vetor, i - 1, tipo), em(vetor, i, tipo)) < 0)
		{
			return 0;
		}
	}

	return 1;
}

void merge_sort(void* vetor, unsigned short tamanho, info_tipo* tipo)
{
	if(tamanho <= 1)
		return;

	unsigned short meio = tamanho >> 1;
	
	merge_sort(vetor, meio, tipo);
	merge_sort(em(vetor, meio, tipo), tamanho - meio, tipo);
	merge(vetor, meio, tamanho, tipo);
}

void merge(void* vetor, unsigned short meio, unsigned short tamanho, info_tipo* tipo)
{
	void* auxiliar = malloc(tipo->tamanho * tamanho);

	if(auxiliar == NULL)
		return;

	unsigned short i = 0, j = meio, k = 0;

	while(i < meio && j < tamanho)
	{
		if((*tipo->cmp)(em(vetor, i, tipo), em(vetor, j, tipo)) < 0)
		{
			memcpy(em(auxiliar, k, tipo), em(vetor, j, tipo), tipo->tamanho);
			++j;
		}
		else
		{
			memcpy(em(auxiliar, k, tipo), em(vetor, i, tipo), tipo->tamanho);
			++i;
		}

		++k;
	}

	while(i < meio)
	{
		memcpy(em(auxiliar, k, tipo), em(vetor, i, tipo), tipo->tamanho);
		++i;
		++k;
	}

	while(j < tamanho)
	{
		memcpy(em(auxiliar, k, tipo), em(vetor, j, tipo), tipo->tamanho);
		++j;
		++k;
	}

	for(k = 0; k < tamanho; ++k)
	{
		memcpy(em(vetor, k, tipo), em(auxiliar, k, tipo), tipo->tamanho);
	}

	free(auxiliar);
}

void bubble_sort(void* vetor, unsigned short tamanho, info_tipo* tipo)
{
	unsigned short i, j;

	for(i = 0; i < tamanho - 1; ++i)
	{
		for(j = tamanho - 1; j > i; --j)
		{
			if((*tipo->cmp)(em(vetor, j, tipo), em(vetor, j - 1, tipo)) > 0)
				swap(em(vetor, j, tipo), em(vetor, j - 1, tipo), tipo);
		}
	}
}

void shell_sort(void* vetor, unsigned short tamanho, info_tipo* tipo)
{
	void * chave = malloc(tipo->tamanho);

	if(chave == NULL)
		return;

	short espacamento, i, j;

	for(espacamento = tamanho >> 1; espacamento > 0; espacamento = espacamento >> 1)
	{
		for(i = espacamento; i < tamanho; ++i)
		{
			memcpy(chave, em(vetor, i, tipo), tipo->tamanho);

			j = i;
			while(j >= espacamento && (*tipo->cmp)(em(vetor, j - espacamento, tipo), chave) < 0)
			{
				memcpy(em(vetor, j, tipo), em(vetor, j - espacamento, tipo), tipo->tamanho);
				--j;
			}
			
			memcpy(em(vetor, j, tipo), chave, tipo->tamanho);
		}
	}

	free(chave);
}

void counting_sort(void* vetor, unsigned short tamanho, info_tipo* tipo)
{
	if(tamanho == 0)
		return;

	unsigned short maximo = (*tipo->num)(em(vetor, 0, tipo));

	for(unsigned short i = 1; i < tamanho; ++i)
	{
		maximo = (*tipo->num)(em(vetor, i, tipo)) > maximo ? (*tipo->num)(em(vetor, i, tipo)) : maximo;
	}

	unsigned short * contagem = calloc(maximo + 1, sizeof(unsigned short));
	void           * auxiliar = malloc(tamanho * tipo->tamanho);

	if(contagem == NULL)
	{
		free(auxiliar);
		return;
	}
	else if(auxiliar == NULL)
	{
		free(contagem);
		return;
	}

	for(unsigned short i = 0; i < tamanho; ++i)
	{
		++contagem[(*tipo->num)(em(vetor, i, tipo))];
	}

	for(unsigned short i = 1; i <= maximo; ++i)
	{
		contagem[i] += contagem[i - 1];
	}

	memcpy(auxiliar, vetor, tamanho * tipo->tamanho);

	for (unsigned short i = tamanho; i > 0; --i) {

		--contagem[(*tipo->num)(em(auxiliar, i - 1, tipo))];
		memcpy(em(vetor, contagem[(*tipo->num)(em(auxiliar, i - 1, tipo))], tipo), em(auxiliar, i - 1, tipo), tipo->tamanho);
	}

	free(contagem);
	free(auxiliar);
}

void quick_sort(void* vetor, unsigned short tamanho, info_tipo* tipo)
{
	unsigned short meio;

	if(tamanho > 1)
	{
		particiona(vetor, tamanho, &meio, tipo);
		quick_sort(vetor, meio, tipo);
		quick_sort(em(vetor, meio, tipo), tamanho - meio, tipo);
	}
}

void quick_sort_3_ins(void* vetor, unsigned short tamanho, info_tipo* tipo, unsigned short min_part_size)
{
	unsigned short meio;

	if(tamanho > 1)
	{
		if(tamanho >= min_part_size)
		{
			particiona_3(vetor, tamanho, &meio, tipo);
			quick_sort_3_ins(vetor, meio, tipo, min_part_size);
			quick_sort_3_ins(em(vetor, meio, tipo), tamanho - meio, tipo, min_part_size);
		}
		else
		{
			insertion_sort(vetor, tamanho, tipo);
		}
	}
}

void particiona(void* vetor, int tamanho, unsigned short *meio, info_tipo* tipo)
{
	void*          pivo     = em(vetor, tamanho - 1, tipo);
	unsigned short auxiliar = 0;
	
	*meio = 0;

	for(auxiliar = 0; auxiliar < tamanho - 1; ++auxiliar)
	{
		if((*tipo->cmp)(em(vetor, auxiliar, tipo), pivo) >= 0)
		{
			swap(em(vetor, *meio, tipo), em(vetor, auxiliar, tipo), tipo);
			++(*meio);
		}
	}

	swap(em(vetor, *meio, tipo), em(vetor, tamanho - 1, tipo), tipo);
}

void particiona_3(void* vetor, int tamanho, unsigned short *meio, info_tipo* tipo)
{
	void* pivo = mediana_de_3(em(vetor, 0, tipo), em(vetor, tamanho - 1, tipo), em(vetor, tamanho >> 1, tipo), tipo);
	
	swap(em(vetor, tamanho - 1, tipo), pivo, tipo);
	pivo = em(vetor, tamanho - 1, tipo);
	
	unsigned short auxiliar = 0;
	
	*meio = 0;

	for(auxiliar = 0; auxiliar < tamanho - 1; ++auxiliar)
	{
		if((*tipo->cmp)(em(vetor, auxiliar, tipo), pivo) >= 0)
		{
			swap(em(vetor, *meio, tipo), em(vetor, auxiliar, tipo), tipo);
			++(*meio);
		}
	}

	swap(em(vetor, *meio, tipo), em(vetor, tamanho - 1, tipo), tipo);
}

void* mediana_de_3 (void* a, void* b, void* c, info_tipo* tipo)
{
    if ((*tipo->cmp)(a, b) > 0 && (*tipo->cmp)(b, c) > 0) return b;      // a <= b <= c
	if ((*tipo->cmp)(a, c) > 0 && (*tipo->cmp)(c, b) > 0) return c;  // a <= c <= b
	if ((*tipo->cmp)(b, a) > 0 && (*tipo->cmp)(a, c) > 0) return a;  // b <= a <= c
	if ((*tipo->cmp)(b, c) > 0 && (*tipo->cmp)(c, a) > 0) return c;  // b <= c <= a
	if ((*tipo->cmp)(c, a) > 0 && (*tipo->cmp)(a, b) > 0) return a;  // c <= a <= b
    return b;                                                            // c <= b <= a
}

char eh_permutacao(void* vetor_1, void* vetor_2, unsigned short tamanho, info_tipo* tipo)
{
	unsigned char* pareado = calloc(tamanho, tipo->tamanho);

	for(unsigned short i = 0; i < tamanho; ++i)
	{
		unsigned short j;

		for(j = 0; j < tamanho; ++j)
		{
			if((*tipo->cmp)(em(vetor_1, i, tipo), em(vetor_2, j, tipo)) == 0 && !pareado[j])
			{
				pareado[j] = 1;
				break;
			}
		}

		if(j == tamanho || !pareado[j])
		{
			free(pareado);

			return 0;
		}
	}

	free(pareado);

	return 1;
}

void radix_sort(void* vetor, unsigned short tamanho, info_tipo* tipos[], unsigned short total_de_tipos, sort_fn ordena)
{
	for (unsigned short i = total_de_tipos; i > 0; --i) {
	
		(*ordena)(vetor, tamanho, tipos[i - 1]);
	}
}

