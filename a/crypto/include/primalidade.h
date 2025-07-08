#ifndef PRIMALIDADE_H
#define PRIMALIDADE_H

#include <stdbool.h>
#include "../include/arit_mod.h"

void crivo_de_eratostenes(unsigned short limite_superior, bool eh_primo[]);
void crivo_segmentado(unsigned limite_superior, unsigned lista_dos_primos[], unsigned short *primos_descobertos, unsigned short maximo_de_primos);
bool school(ull numero_a_verificar);
bool little_fermat(ull numero_a_verificar, ull quantidade_de_testes);
bool miller_rabin(ull numero_a_verificar, ull quantidade_de_testes);
bool solovay_strassen(ull numero_a_verificar, ull quantidade_de_testes);

void primos_no_intervalo(unsigned limite_inferior, unsigned limite_superior, unsigned primos_anteriores[], unsigned short quantidade_de_primos_anteriores, bool eh_primo[]);
bool teste_de_miller(ull numero_a_verificar, ull fator_impar);

#endif
