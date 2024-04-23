#include <stdio.h>
#include "../lib/vetores.h"

#define SUCESSO 0
#define NUMEROS 10

int main(int argc, char** argv);

int main(int argc, char** argv)
{
    int tamanho_do_vetor = NUMEROS;
    int numeros_a_deslocar[NUMEROS] = { 0 };
    
    le_vetor_i(numeros_a_deslocar, tamanho_do_vetor);

    deslocar_para_a_esquerda_vetor_i(numeros_a_deslocar, tamanho_do_vetor--);

    printa_vetor_i(numeros_a_deslocar, tamanho_do_vetor);
    putchar('\n');

	return SUCESSO;
}
