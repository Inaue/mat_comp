/**
 * @file   buscas.h
 * @brief  Cabecalho para algoritmos de busca.
 * @author Inaue Ferreira da Silva
 * @date   20-03-2025
 */

#include "../include/uteis.h"

#ifndef BUSCAS_H
#define BUSCAS_H

typedef int (*search_arr_fn) (void* vetor, unsigned short tamanho, void* elemento, info_tipo* tipo);

/*< Funcoes de busca */

int arr_linear_search (void* vetor, unsigned short tamanho, void* elemento, info_tipo* tipo);
int arr_bin_search    (void* vetor, unsigned short tamanho, void* elemento, info_tipo* tipo);

#endif

