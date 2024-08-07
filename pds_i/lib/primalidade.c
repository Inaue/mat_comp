#include <math.h>
#include <stdbool.h>
#include <stdlib.h>
#include "primalidade.h"

#define BITS_P_BYTE 8
#define HU_MAX      (int) pow(2, sizeof(unsigned short) * BITS_P_BYTE) - 1

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

void crivo_de_eratostenes(unsigned short limite_superior, bool eh_primo[])
{
    unsigned short indice_1 = 2, indice_2 = 2;

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
            for(indice_2 = indice_1 * indice_1; indice_2 < limite_superior; indice_2 += indice_1)
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

void crivo_segmentado(unsigned limite_superior, unsigned lista_dos_primos[], unsigned short *primos_descobertos, unsigned short maximo_de_primos)
{
    bool crivo[HU_MAX];
    unsigned short tamanho_dos_intervalos = (unsigned short) sqrt(limite_superior);
    unsigned short indice_primos = 0;
    unsigned short primos_iniciais = 0;
    unsigned inicio_do_intervalo = 0, final_do_intervalo = 0;

    crivo_de_eratostenes(tamanho_dos_intervalos, crivo);
    
    for(indice_primos = 0; indice_primos < tamanho_dos_intervalos; indice_primos++)
    {
        if(*primos_descobertos >= maximo_de_primos)
            return;

        if(crivo[indice_primos])
            lista_dos_primos[(*primos_descobertos)++] = indice_primos;
    }

    primos_iniciais     = *primos_descobertos;
    inicio_do_intervalo = tamanho_dos_intervalos;
    final_do_intervalo  = inicio_do_intervalo + tamanho_dos_intervalos;

    while(final_do_intervalo < limite_superior)
    {
        primos_no_intervalo(inicio_do_intervalo, final_do_intervalo, lista_dos_primos, primos_iniciais, crivo);
        
        for(indice_primos = 0; indice_primos < tamanho_dos_intervalos; indice_primos++)
        {
            if(*primos_descobertos >= maximo_de_primos)
                return;

            if(crivo[indice_primos])
                lista_dos_primos[(*primos_descobertos)++] = indice_primos + inicio_do_intervalo;
        }

        inicio_do_intervalo += tamanho_dos_intervalos;
        final_do_intervalo  += tamanho_dos_intervalos;
    }

    primos_no_intervalo(inicio_do_intervalo, limite_superior, lista_dos_primos, primos_iniciais, crivo);

    for(indice_primos = 0; indice_primos < (limite_superior - inicio_do_intervalo); indice_primos++)
    {
        if(*primos_descobertos >= maximo_de_primos)
                return;

        if(crivo[indice_primos])
            lista_dos_primos[(*primos_descobertos)++] = indice_primos + inicio_do_intervalo;
    }
}

void primos_no_intervalo(unsigned limite_inferior, unsigned limite_superior, unsigned primos_anteriores[], unsigned short quantidade_de_primos_anteriores, bool eh_primo[])
{
    unsigned short indice_intervalo = 0, indice_primo = 0;
    unsigned short tamanho_do_intervalo = limite_superior - limite_inferior;
    unsigned short primo = 0, multiplo = 0;

    for(indice_intervalo = 0; indice_intervalo < tamanho_do_intervalo; indice_intervalo++)
        
        eh_primo[indice_intervalo] = true;

    for(indice_primo = 0; indice_primo < quantidade_de_primos_anteriores; indice_primo++)
    {
        primo    = primos_anteriores[indice_primo];
        multiplo = (primo - (limite_inferior % primo)) % primo;

        while(multiplo < tamanho_do_intervalo)
        {
            eh_primo[multiplo] = false;
            multiplo += primo;
        }
    }
}

bool miller_rabin(unsigned long long numero_a_verificar, unsigned long long quantidade_de_testes)
{
    unsigned long long fator_impar = numero_a_verificar - 1;

    if(numero_a_verificar == 2 || numero_a_verificar == 3)
        return true;

    if(numero_a_verificar < 2)
        return false;

    if(numero_a_verificar % 2 == 0)
        return false;

    while(!(fator_impar & 1))           // ENQUANTO fator_impar NAO FOR IMPAR
        fator_impar = fator_impar >> 1; // DIVIDA POR 2

    for(; quantidade_de_testes > 0; quantidade_de_testes--)
        if(!teste_de_miller(numero_a_verificar, fator_impar))
            return false;

    return true;
}

bool teste_de_miller(unsigned long long numero_a_verificar, unsigned long long fator_impar)
{
    unsigned long long teste, expoente, resto_de_divisao;

    teste            = ((unsigned long long)rand() % (numero_a_verificar - 3)) + 2; // 1 < teste < numero_a_verificar - 1
    expoente         = fator_impar;
    resto_de_divisao = pow_mod(teste, expoente, numero_a_verificar);
    
    if((resto_de_divisao == 1) || (resto_de_divisao == (numero_a_verificar - 1)))
        
        return true;

    while(expoente != (numero_a_verificar - 1))
    {
        resto_de_divisao = (resto_de_divisao * resto_de_divisao) % numero_a_verificar;
        expoente         = expoente << 1; // MULTIPLICA POR 2
        
        if(resto_de_divisao == 1)
            return false;

        if(resto_de_divisao == (numero_a_verificar - 1))
            return true;
    }

    return false;
}

char simbolo_de_jacobi(unsigned long long numerador, unsigned long long denominador)
{
    if(numerador == 0)
        return 0;

    if(numerador == 1 || denominador == 1)
        return 1;

    if(numerador == 2)
        return (denominador % 8 == 1 || denominador % 8 == 7) ? 1 : -1;

    if(numerador >= denominador)
        return simbolo_de_jacobi(numerador % denominador, denominador);

    if((numerador & 1) == 0)
        
        return simbolo_de_jacobi(2, denominador) * simbolo_de_jacobi(numerador >> 1, denominador);

    if(mdc(numerador, denominador) == 1)
        return simbolo_de_jacobi(denominador, numerador) * ((numerador % 4 == 3 && denominador % 4 == 3) ? -1 : 1);

    return 0;
}

unsigned long long mdc(unsigned long long numero_1, unsigned long long numero_2)
{
    if(numero_2 == 0)
        return numero_1;

    return mdc(numero_2, numero_1 % numero_2);
}

bool solovay_strassen(unsigned long long numero_a_verificar, unsigned long long quantidade_de_testes)
{
    unsigned long long teste;

    if(numero_a_verificar == 2 || numero_a_verificar == 3)
        return true;

    if(numero_a_verificar < 2)
        return false;

    for(; quantidade_de_testes > 0; quantidade_de_testes--)
    {
        teste = ((unsigned long long)rand() % (numero_a_verificar - 3)) + 2; // 1 < teste < numero_a_verificar - 1

        if(mdc(numero_a_verificar, teste) != 1)
            return false;

        if(simbolo_de_jacobi(teste, numero_a_verificar) != simbolo_de_legendre(teste, numero_a_verificar))

            return false;
    }

    return true;
}

char simbolo_de_legendre(unsigned long long numerador, unsigned long long denominador)
{
    unsigned long long resultado = pow_mod(numerador, (denominador - 1) / 2, denominador);

    return resultado < 2 ? (char) resultado : -1;
}
