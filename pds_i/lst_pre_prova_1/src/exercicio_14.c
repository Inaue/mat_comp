#include <stdio.h>
#include "../lib/vetores.h"
#include "../lib/ordenacoes.h"

#define SUCESSO 0
#define NUMEROS 3

int main(int argc, char** argv);

int main(int argc, char** argv)
{
    double numeros_a_ordenar[NUMEROS] = { 0.0 };
    
    le_vetor_lf(numeros_a_ordenar, NUMEROS);

    bubble_sort_lf(numeros_a_ordenar, NUMEROS);

    printa_vetor_lf(numeros_a_ordenar, NUMEROS);
    putc('\n', stdout);

	return SUCESSO;
}

int max(int a, int b, int c)
{
    if((a >= b) && (a >= c))

        return a;
    
    else if((b >= a) && (b >= c))

        return b;
    
    else

        return c;
}
