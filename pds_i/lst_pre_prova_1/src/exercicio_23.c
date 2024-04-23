#include <stdio.h>
#include "../lib/vetores.h"

#define SUCESSO 0
#define NUMEROS 10

int main(int argc, char** argv);

int main(int argc, char** argv)
{
    int indice = 0, quantidade_de_maiores = 0;
    double x = 0;
    double numeros_a_vasculhar[NUMEROS] = { 0 }, numeros_maiores_que_x[NUMEROS] = { 0 };
    
    le_vetor_lf(numeros_a_vasculhar, NUMEROS);
    scanf("%lf", &x);

    for(indice = 0; indice < NUMEROS; indice++)
    {
        if(numeros_a_vasculhar[indice] > x)
        {
            numeros_maiores_que_x[quantidade_de_maiores++] = numeros_a_vasculhar[indice];
        }
    }

    printa_vetor_lf(numeros_maiores_que_x, quantidade_de_maiores);
    putchar('\n');

	return SUCESSO;
}
