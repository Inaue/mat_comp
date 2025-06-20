/**
 * @file   ordenacoes.h
 * @brief  Cabecalho para algoritmos de ordenacao.
 * @author Inaue Ferreira da Silva
 * @date   18-03-2025
 */

#ifndef ORDENACOES_H
#define ORDENACOES_H

/*< Definicao de tipos */

#ifndef INFO_TIPO
#define INFO_TIPO

typedef char (*cmp_fn) (void* valor_1, void* valor_2);

typedef struct
{
	cmp_fn cmp;
	size_t tamanho;
}
info_tipo;

#endif

typedef void (*sort_fn) (void* vetor, unsigned short tamanho, info_tipo* tipo);

/*< Funcoes auxiliares */

char esta_ordenado (void* vetor, unsigned short tamanho, info_tipo* tipo);

/*< Funcoes de ordenacao */

void insertion_sort   (void* vetor, unsigned short tamanho, info_tipo* tipo);
void selection_sort   (void* vetor, unsigned short tamanho, info_tipo* tipo);
void merge_sort       (void* vetor, unsigned short tamanho, info_tipo* tipo);
void bubble_sort      (void* vetor, unsigned short tamanho, info_tipo* tipo);
void shell_sort       (void* vetor, unsigned short tamanho, info_tipo* tipo);
void quick_sort       (void* vetor, unsigned short tamanho, info_tipo* tipo);
void quick_sort_3_ins (void* vetor, unsigned short tamanho, info_tipo* tipo, unsigned short min_part_size);
void counting_sort    (unsigned short vetor[], unsigned short tamanho);

#endif
