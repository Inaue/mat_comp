/**
 * @file   buscas.h
 * @brief  Cabecalho para algoritmos de busca.
 * @author Inaue Ferreira da Silva
 * @date   20-03-2025
 */

#ifndef BUSCAS_H
#define BUSCAS_H

/*< Constantes */

#define NAO_ENCONTRADO -1

/*< Definicao de tipos */

#ifndef INFO_TIPO
#define INFO_TIPO

typedef void (*cpy_fn) (void* origem, void* destino);
typedef char (*cmp_fn) (void* valor_1, void* valor_2);

typedef struct
{
	cmp_fn cmp;
	size_t tamanho;
}
info_tipo;

#endif

typedef int (*search_arr_fn) (void* vetor, unsigned short tamanho, void* elemento, info_tipo* tipo);

/*< Funcoes de busca */

int arr_linear_search (void* vetor, unsigned short tamanho, void* elemento, info_tipo* tipo);
int arr_bin_search    (void* vetor, unsigned short tamanho, void* elemento, info_tipo* tipo);

#endif
