#ifndef FATORACAO_H
#define FATORACAO_H

#include <stdbool.h>

#define VERDADEIRO (1 == 1)
#define FALSO      !VERDADEIRO

unsigned long long fac_fermat (unsigned long long numero_a_fatorar);
unsigned long long fac_euler  (unsigned long long numero_a_fatorar);

bool               eh_quadrado_perfeito (unsigned long long numero_a_verificar);
unsigned long long mdc                  (unsigned long long numero_1, unsigned long long numero_2);

#endif
