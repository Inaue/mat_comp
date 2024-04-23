#include <stdio.h>
#include "../lib/vetores.h"

#define SUCESSO 0
#define NUMEROS 5

int main(int argc, char** argv);
int max(int a, int b, int c);

int main(int argc, char** argv)
{
    double maior_numero = 0.0, numeros_a_comparar[NUMEROS] = { 0.0 };
    
    le_vetor_lf(numeros_a_comparar, NUMEROS);

    maior_numero = max(numeros_a_comparar[0], numeros_a_comparar[1], numeros_a_comparar[2]);
    maior_numero = max(maior_numero, numeros_a_comparar[3], numeros_a_comparar[4]);

    printf("%g\n", maior_numero);

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
