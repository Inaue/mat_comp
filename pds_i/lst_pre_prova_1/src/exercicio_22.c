#include <stdio.h>
#include "../lib/vetores.h"

#define SUCESSO 0
#define NUMEROS 10

int main(int argc, char** argv);

int main(int argc, char** argv)
{
    int indice = 0, x = 0;
    int numeros_a_vasculhar[NUMEROS] = { 0 };
    
    le_vetor_i(numeros_a_vasculhar, NUMEROS);
    scanf("%d", &x);

    indice = procura_no_vetor_i(numeros_a_vasculhar, NUMEROS, x);

    if(indice == ELEMENTO_NAO_ENCONTRADO)
    {
        printf("NAO ACHEI\n");
    }
    else
    {
        printf("ACHEI\n");
    }

	return SUCESSO;
}
