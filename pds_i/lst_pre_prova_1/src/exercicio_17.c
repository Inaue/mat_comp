#include <stdio.h>
#include "../lib/vetores.h"
#include "../lib/ordenacoes.h"

#define SUCESSO 0
#define NUMEROS 3

int main(int argc, char** argv);

int main(int argc, char** argv)
{
    int i = 1;
    double numeros_a_ordenar[NUMEROS] = { 0.0 };
    
    scanf("%d", &i);
    le_vetor_lf(numeros_a_ordenar, NUMEROS);

    switch(i)
    {
        case 1:

            bubble_sort_lf(numeros_a_ordenar, NUMEROS);
            break;
        
        case 2:

            bubble_sort_lf(numeros_a_ordenar, NUMEROS);
            inverta_vetor_lf(numeros_a_ordenar, NUMEROS);
            break;
        
        case 3:

            bubble_sort_lf(numeros_a_ordenar, NUMEROS);
            trocar_elementos_lf(numeros_a_ordenar, 1, 2);
            break;
        
        default:

            printf("Erro: opcao invalida!\n");
            break;
    }

    printa_vetor_lf(numeros_a_ordenar, NUMEROS);
    putc('\n', stdout);

	return SUCESSO;
}
