/**
 * @file   ordenacoes.h
 * @brief  Cabecalho para algoritmos de ordenacao.
 * @author Inaue Ferreira da Silva
 * @date   18-03-2025
 */

#include "../include/uteis.h"

#ifndef ORDENACOES_H
#define ORDENACOES_H

/*< Definicao de tipos */

typedef void (*sort_fn) (void* vetor, unsigned short tamanho, info_tipo* tipo);

/*< Funcoes auxiliares */

char esta_ordenado (void* vetor, unsigned short tamanho, info_tipo* tipo);
char eh_permutacao (void* vetor_1, void* vetor_2, unsigned short tamanho, info_tipo* tipo);

/*< Funcoes de ordenacao */

void insertion_sort   (void* vetor, unsigned short tamanho, info_tipo* tipo);
void selection_sort   (void* vetor, unsigned short tamanho, info_tipo* tipo);
void merge_sort       (void* vetor, unsigned short tamanho, info_tipo* tipo);
void bubble_sort      (void* vetor, unsigned short tamanho, info_tipo* tipo);
void shell_sort       (void* vetor, unsigned short tamanho, info_tipo* tipo);
void quick_sort       (void* vetor, unsigned short tamanho, info_tipo* tipo);
void counting_sort    (void* vetor, unsigned short tamanho, info_tipo* tipo);
void radix_sort       (void* vetor, unsigned short tamanho, info_tipo* tipos[], unsigned short total_de_tipos, sort_fn ordena);
void quick_sort_3_ins (void* vetor, unsigned short tamanho, info_tipo* tipo, unsigned short min_part_size);

#endif
