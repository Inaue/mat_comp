#include "estatisticas.h"

double media_aritmetica_ponderada(const double dados[], const double pesos[], int tamanho)
{
    int i = 0;
    double numerador = 0.0, denominador = 0.0, media = 0.0;

    for (i = 0; i < tamanho; i++)
    {
        numerador   += dados[i] * pesos[i];
        denominador += pesos[i];
    }
    
    if(denominador == 0.0)
        
        media = 0.0;
    
    else

        media = numerador / denominador;

    return media;
}

double media_aritmetica_simples(const double dados[], int tamanho)
{
    int i = 0, denominador = tamanho;
    double numerador = 0.0, media = 0.0;

    for (i = 0; i < tamanho; i++)
    {
        numerador += dados[i];
    }
    
    if(denominador == 0)
        
        media = 0.0;
    
    else

        media = numerador / denominador;

    return media;
}
