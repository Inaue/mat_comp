#include <stdio.h>
#include "../lib/vetores.h"

#define SUCESSO 0
#define NUMEROS 10

int main(int argc, char** argv);

int main(int argc, char** argv)
{
    int tamanho_do_vetor = NUMEROS, indice_do_elemento_a_remover = 0;
    double numeros_a_deslocar[NUMEROS] = { 0 };
    
    le_vetor_lf(numeros_a_deslocar, tamanho_do_vetor);
    scanf("%d", &indice_do_elemento_a_remover);

    retirar_elemento_vetor_lf(numeros_a_deslocar, tamanho_do_vetor--, indice_do_elemento_a_remover);

    printa_vetor_lf(numeros_a_deslocar, tamanho_do_vetor);
    putchar('\n');

	return SUCESSO;
}
