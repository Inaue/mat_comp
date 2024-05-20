#include "../lib/ordenacoes.h"

void bubble_sort_lf(double v_ordenar[], int tamanho)
{
    int limitador = 0, indice_de_troca = 0;

    for(limitador = tamanho - 1; limitador > 0; limitador--)
    {
        for(indice_de_troca = 0; indice_de_troca < limitador; indice_de_troca++)
        {
            if(v_ordenar[indice_de_troca] > v_ordenar[indice_de_troca + 1])
            {
                trocar_elementos_lf(v_ordenar, indice_de_troca, indice_de_troca + 1);
            }
        }
    }
}

void trocar_elementos_lf(double v_manipular[], int indice_1, int indice_2)
{
	if(indice_1 != indice_2)
	{
		v_manipular[indice_1] += v_manipular[indice_2];
        v_manipular[indice_2]  = v_manipular[indice_1] - v_manipular[indice_2];
        v_manipular[indice_1] -= v_manipular[indice_2];
	}
}
