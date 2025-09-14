/**
 * @file   uteis.h
 * @brief  Cabecalho para algoritmos uteis em diversas bibliotecas
 * @author Inaue Ferreira da Silva
 * @date   2025-09-13
 */

#include <stdlib.h>

/*< Definicao de tipos */

#ifndef INFO_TIPO
#define INFO_TIPO

typedef char (*cmp_fn) (void* valor_1, void* valor_2);
typedef int  (*num_fn) (void* valor);

typedef struct
{
	size_t tamanho;
	cmp_fn cmp;
	num_fn num;
}
info_tipo;

#endif

#ifndef UTEIS_H
#define UTEIS_H

/*< Constantes */

#define NAO_ENCONTRADO -1

/*< Funcoes Auxiliares */

void * em   (void* vetor, unsigned short i, info_tipo* tipo);
void   swap (void* valor_1, void* valor_2, info_tipo* tipo);

#endif

