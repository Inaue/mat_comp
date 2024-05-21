#include <stdio.h>
#include <math.h>
#include "../lib/vetores.h"

#define SUCESSO         0
#define CHAR_FIM_DE_STR 1
#define SIZE_STR        (64 + CHAR_FIM_DE_STR)

int main();
void dividir_sucessivamente(unsigned long long dividendo_inicial, unsigned long long divisor, unsigned long long quocientes[64], unsigned long long restos[64]);
void converter_inteiro_decimal(unsigned long long numero_a_converter, char base_a_converter, char string_do_resultado[], unsigned short tamanho_da_string);
char converter_inteiro_em_algarismo(unsigned long long numero_a_converter);

int main()
{
    unsigned long long teste = 271828183;
    char binario[SIZE_STR], octal[SIZE_STR], hexadesimal[SIZE_STR];
    
    converter_inteiro_decimal(teste, 'b', binario,     SIZE_STR);
    converter_inteiro_decimal(teste, 'o', octal,       SIZE_STR);
    converter_inteiro_decimal(teste, 'h', hexadesimal, SIZE_STR);

    printf("dec: %llu\n", teste);
    printf("bin: %s\n",   binario);
    printf("oct: %s\n",   octal);
    printf("hex: %s\n",   hexadesimal);

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
    
    return 'a' + numero_a_converter - 10;
}

void converter_inteiro_decimal(unsigned long long numero_a_converter, char base_a_converter, char string_do_resultado[], unsigned short tamanho_da_string)
{
    unsigned long long base_do_sistema_numerico = base_a_converter == 'b' ? 2 :
                                                  base_a_converter == 'o' ? 8 : 16;

    unsigned long long restos[64];
    unsigned short caractere, maximo_de_algarismos = floorf(log(numero_a_converter) / log(base_do_sistema_numerico)) + 1;

    if(tamanho_da_string == 0)
        return;

    dividir_sucessivamente(numero_a_converter, base_do_sistema_numerico, NULL, restos);

    for(caractere = 0; (caractere < maximo_de_algarismos) && (caractere < tamanho_da_string - 1); caractere++)
    {
        string_do_resultado[caractere] = converter_inteiro_em_algarismo(restos[caractere]);
    }

    string_do_resultado[caractere] = '\0';
    inverta_vetor_hh(string_do_resultado, caractere);
}
