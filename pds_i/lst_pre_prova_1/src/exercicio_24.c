#include <stdio.h>
#include "../lib/vetores.h"

#define SUCESSO 0
#define NUMEROS 10

int main(int argc, char** argv);

int main(int argc, char** argv)
{
    int tamanho_do_vetor = 0, posicao_inserir_elemento = 0;
    double x = 0;
    double numeros_do_vetor[NUMEROS] = { 0 };
    
    scanf("%d", &tamanho_do_vetor);
    le_vetor_lf(numeros_do_vetor, tamanho_do_vetor);
    scanf("%lf", &x);

    inserir_elemento_vetor_lf(numeros_do_vetor, tamanho_do_vetor++, posicao_inserir_elemento, x);

    printa_vetor_lf(numeros_do_vetor, tamanho_do_vetor);
    putchar('\n');

	return SUCESSO;
}
