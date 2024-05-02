#ifndef PRIMALIDADE_H
#define PRIMALIDADE_H

#include <stdbool.h>

bool school(unsigned long long numero_a_verificar);
bool little_fermat(unsigned long long numero_a_verificar, unsigned long long quantidade_de_testes);
void crivo_de_eratostenes(unsigned long long limite_superior, bool eh_primo[]);

unsigned long long pow_mod(unsigned long long base, unsigned long long expoente, unsigned long long mod);

#endif