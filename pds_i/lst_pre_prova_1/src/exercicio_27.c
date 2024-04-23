#include <stdio.h>
#include "../lib/vetores.h"

#define SUCESSO      0
#define TAMANHO_DE_R 5
#define TAMANHO_DE_S 10
#define TAMANHO_DE_X 5

int main(int argc, char** argv);

int main(int argc, char** argv)
{
    int indice = 0, indice_de_busca_em_r = ELEMENTO_NAO_ENCONTRADO, indice_de_busca_em_x = ELEMENTO_NAO_ENCONTRADO;
    int tamanho_de_x = 0;
    double r[TAMANHO_DE_R] = { 0 }, s[TAMANHO_DE_R] = { 0 }, x[TAMANHO_DE_X] = { 0 };
    
    le_vetor_lf(r, TAMANHO_DE_R);
    le_vetor_lf(s, TAMANHO_DE_S);

    for(indice = 0; indice < TAMANHO_DE_S; indice++)
    {
        indice_de_busca_em_r = procura_no_vetor_lf(r, TAMANHO_DE_R, s[indice]);
        indice_de_busca_em_x = procura_no_vetor_lf(x, tamanho_de_x, s[indice]);

        if(indice_de_busca_em_r != ELEMENTO_NAO_ENCONTRADO && indice_de_busca_em_x == ELEMENTO_NAO_ENCONTRADO)
        {
            inserir_elemento_vetor_lf(x, tamanho_de_x++, 0, s[indice]);
        }
    }

    printa_vetor_lf(x, tamanho_de_x);
    putchar('\n');

	return SUCESSO;
}
