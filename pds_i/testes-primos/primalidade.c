#include <math.h>
#include <stdbool.h>
#include <stdlib.h>
#include "primalidade.h"

bool school(unsigned long long numero_a_verificar)
{
    unsigned long long indice_1;

    if(numero_a_verificar == 2 || numero_a_verificar == 3)
        
        return true;

    if(numero_a_verificar < 2 || numero_a_verificar % 2 == 0 || numero_a_verificar % 3 == 0)
        
        return false;

    for(indice_1 = 6; indice_1 - 1 <= sqrt(numero_a_verificar); indice_1 += 6)
    {
        if(numero_a_verificar % (indice_1 - 1) == 0 || numero_a_verificar % (indice_1 + 1) == 0)
            
            return false;
    }

    return true;
}

bool little_fermat(unsigned long long numero_a_verificar, unsigned long long quantidade_de_testes)
{
    unsigned long long teste;

    if(numero_a_verificar == 2 || numero_a_verificar == 3)
        return true;

    if(numero_a_verificar < 2)
        return false;

    for(; quantidade_de_testes > 0; quantidade_de_testes--)
    {
        teste = ((unsigned long long)rand() % (numero_a_verificar - 3)) + 2; // 1 < teste < numero_a_verificar - 1

        if(pow_mod(teste, numero_a_verificar - 1, numero_a_verificar) != 1)

            return false;
    }

    return true;
}

void crivo_de_eratostenes(unsigned long long limite_superior, bool eh_primo[])
{
    unsigned long long indice_1 = 2, indice_2 = 2;

    if(limite_superior == 0)
        return;

    eh_primo[0] = false;

    if(limite_superior == 1)
        return;

    eh_primo[1] = false;
    
    for(indice_1 = 2; indice_1 < limite_superior; indice_1++)
        eh_primo[indice_1] = true;

    for(indice_1 = 2; indice_1 <= sqrt(limite_superior); indice_1++)
        if(eh_primo[indice_1])
            for(indice_2 = 2 * indice_1; indice_2 < limite_superior; indice_2 += indice_1)
                eh_primo[indice_2] = false;
}

unsigned long long pow_mod(unsigned long long base, unsigned long long expoente, unsigned long long mod)
{
    unsigned long long resultado = 1;

    base %= mod;

    while(expoente != 0)
    {
        if(expoente & 1)
        {
            resultado = (resultado * base) % mod;
        }

        expoente = expoente >> 1;   // DIVIDE O EXPOENTE POR 2
        base = (base * base) % mod; // ALTERA A BASE DE ACORDO COM O EXPOENTE
    }

    return resultado;
}
