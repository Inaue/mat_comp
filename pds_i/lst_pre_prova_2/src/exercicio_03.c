#include <stdio.h>
#include <math.h>
#include "../lib/vetores.h"

#define SUCESSO 0

int main();
void dividir_sucessivamente(unsigned long long dividendo_inicial, unsigned long long divisor, unsigned long long quocientes[64], unsigned long long restos[64]);
void converter_inteiro_decimal(unsigned long long numero_a_converter, char base_a_converter, char string_do_resultado[], unsigned short tamanho_da_string);
char converter_inteiro_em_algarismo(unsigned long long numero_a_converter);

int main()
{
    char teste[65];
    
    converter_inteiro_decimal(56, 'b', teste, 65);
    fputs(teste, stdout);

	return SUCESSO;
}

void dividir_sucessivamente(unsigned long long dividendo_inicial, unsigned long long divisor, unsigned long long quocientes[64], unsigned long long restos[64])
{
    unsigned long long quociente;
    unsigned long long resto;
    unsigned char      indice_dos_quocientes, indice_dos_restos;

    if(quocientes != NULL)
    {
        quociente             = dividendo_inicial;
        indice_dos_quocientes = 0;

        do
        {
            quociente /= divisor;
            quocientes[indice_dos_quocientes++] = quociente;
            
        } while (quociente != 0);
    }

    if(restos != NULL)
    {
        quociente         = dividendo_inicial;
        indice_dos_restos = 0;

        do
        {
            resto      = quociente % divisor;
            quociente /= divisor;
            restos[indice_dos_restos++] = resto;
            
        } while (quociente != 0);
    }
}

char converter_inteiro_em_algarismo(unsigned long long numero_a_converter)
{
    if(numero_a_converter < 10)
        return '0' + numero_a_converter;
    
    return 'a' + numero_a_converter;
}

void converter_inteiro_decimal(unsigned long long numero_a_converter, char base_a_converter, char string_do_resultado[], unsigned short tamanho_da_string)
{
    unsigned long long base = base_a_converter == 'b' ? 2 :
                              base_a_converter == 'o' ? 8 : 16;

    unsigned long long restos[64];
    unsigned short caractere, maximo_de_algarismos = ceilf(log(numero_a_converter) / log(base_a_converter));

    if(tamanho_da_string == 0)
        return;

    dividir_sucessivamente(numero_a_converter, base, NULL, restos);

    for(caractere = 0; (caractere < maximo_de_algarismos) && (caractere < tamanho_da_string - 1); caractere++)
    {
        string_do_resultado[caractere] = converter_inteiro_em_algarismo(restos[caractere]);
    }

    string_do_resultado[caractere] = '\0';
}
