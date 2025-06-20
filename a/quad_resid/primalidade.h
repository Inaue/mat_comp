#ifndef PRIMALIDADE_H
#define PRIMALIDADE_H

#include <stdbool.h>

void crivo_de_eratostenes(unsigned short limite_superior, bool eh_primo[]);
void crivo_segmentado(unsigned limite_superior, unsigned lista_dos_primos[], unsigned short *primos_descobertos, unsigned short maximo_de_primos);
bool school(unsigned long long numero_a_verificar);
bool little_fermat(unsigned long long numero_a_verificar, unsigned long long quantidade_de_testes);
bool miller_rabin(unsigned long long numero_a_verificar, unsigned long long quantidade_de_testes);
bool solovay_strassen(unsigned long long numero_a_verificar, unsigned long long quantidade_de_testes);

unsigned long long pow_mod(unsigned long long base, unsigned long long expoente, unsigned long long mod);
unsigned long long mdc(unsigned long long numero_1, unsigned long long numero_2);
void primos_no_intervalo(unsigned limite_inferior, unsigned limite_superior, unsigned primos_anteriores[], unsigned short quantidade_de_primos_anteriores, bool eh_primo[]);
bool teste_de_miller(unsigned long long numero_a_verificar, unsigned long long fator_impar);
char simbolo_de_jacobi(unsigned long long numerador, unsigned long long denominador);
char simbolo_de_legendre(unsigned long long numerador, unsigned long long denominador);

#endif