#include <stdlib.h>
#include "string_inaue.h"

#define FIM_DA_STRING            '\0'
#define CARACTERE_NAO_ENCONTRADO NULL
#define SUBSTRING_NAO_ENCONTRADA NULL

int ist_len(char *string)
{
    int indice = 0;
    
    while(string[indice++] != FIM_DA_STRING);

    return indice - 1;
}

char * ist_cat(char *string_de_destino, const char *string_de_origem)
{
    int indice_destino = 0, indice_origem = 0;

    while(string_de_destino[indice_destino++] != FIM_DA_STRING);
    indice_destino--;
    
    do
        string_de_destino[indice_destino++] = string_de_origem[indice_origem];
    
    while(string_de_origem[indice_origem++] != FIM_DA_STRING);
    
    return string_de_destino;
}

int ist_cmp(const char *string_1, const char *string_2)
{
    int indice = 0;

    while((string_1[indice] != FIM_DA_STRING) && (string_2[indice] != FIM_DA_STRING))
    {
        if(string_1[indice] != string_2[indice])
            
            return string_1[indice] - string_2[indice];

        indice++;
    }

    if(string_1[indice] == string_2[indice])
        return 0;

    return string_1[indice] - string_2[indice];
}

char * ist_cpy(char *string_de_destino, const char *string_de_origem)
{
    int indice = 0;

    do
        string_de_destino[indice] = string_de_origem[indice];
    
    while(string_de_origem[indice++] != FIM_DA_STRING);
    
    return string_de_destino;
}

char * ist_n_cat(char *string_de_destino, const char *string_de_origem, int tamanho)
{
    int indice_destino = 0, indice_origem = 0, chr_concatenados = 0;

    while(string_de_destino[indice_destino++] != FIM_DA_STRING);
    indice_destino--;
    
    while((string_de_origem[indice_origem] != FIM_DA_STRING) && (chr_concatenados++ < tamanho))
        
        string_de_destino[indice_destino++] = string_de_origem[indice_origem++];
    
    string_de_destino[indice_destino] = FIM_DA_STRING;
    
    return string_de_destino;
}

char * ist_n_cpy(char *string_de_destino, const char *string_de_origem, int tamanho)
{
    int indice = 0;

    while((string_de_origem[indice] != FIM_DA_STRING) && (indice < tamanho))
    {
        string_de_destino[indice] = string_de_origem[indice];
        indice++;
    }
    
    string_de_destino[indice] = FIM_DA_STRING;

    return string_de_destino;
}

int ist_n_cmp(const char *string_1, const char *string_2, int tamanho)
{
    int indice = 0, chr_comparados = 0;

    while((string_1[indice] != FIM_DA_STRING) && (string_2[indice] != FIM_DA_STRING))
    {
        if(chr_comparados++ >= tamanho)
            return 0;
        
        if(string_1[indice] != string_2[indice])
            
            return string_1[indice] - string_2[indice];

        indice++;
    }

    if(string_1[indice] == string_2[indice])
        return 0;

    return string_1[indice] - string_2[indice];
}

char * ist_chr(char *string, int caractere)
{
    while(string[0] != FIM_DA_STRING)
    {
        if(string[0] == caractere)
            return string;

        string++;
    }

    if(caractere == FIM_DA_STRING)
        return string;

    return CARACTERE_NAO_ENCONTRADO;
}

char * ist_r_chr(char *string, int caractere)
{
    char * ultima_ocorrencia = CARACTERE_NAO_ENCONTRADO;

    while(string[0] != FIM_DA_STRING)
    {
        if(string[0] == caractere)
            ultima_ocorrencia = string;

        string++;
    }

    if(caractere == FIM_DA_STRING)
        ultima_ocorrencia = string;

    return ultima_ocorrencia;
}

char * ist_str(char *string, char *substring_procurada)
{
    char *ocorrencia, *indice_da_substring;

    if(substring_procurada[0] == '\0')
        return string;

    while(string[0] != FIM_DA_STRING)
    {
        ocorrencia       = string;
        indice_da_substring = substring_procurada;
        
        while(string[0] == indice_da_substring[0])
        {
            string++;
            indice_da_substring++;
        }

        if(indice_da_substring[0] == FIM_DA_STRING)
            return ocorrencia;

        string++;
    }

    return SUBSTRING_NAO_ENCONTRADA;
}

char * ist_r_str(char *string, char *substring_procurada)
{
    char *ultima_ocorrencia = SUBSTRING_NAO_ENCONTRADA, *ocorrencia, *indice_da_substring;

    if(substring_procurada[0] == '\0')
        return string;

    while(string[0] != FIM_DA_STRING)
    {
        ocorrencia          = string;
        indice_da_substring = substring_procurada;
        
        while((string[0] == indice_da_substring[0]) && (string[0] != FIM_DA_STRING))
        {
            string++;
            indice_da_substring++;
        }

        if(indice_da_substring[0] == FIM_DA_STRING)
            ultima_ocorrencia = ocorrencia;

        string++;
    }

    return ultima_ocorrencia;
}

char * ist_rev(char *string_a_inverter)
{
    int indice_1 = 0, indice_2 = 0;
    
    while(string_a_inverter[indice_2++] != FIM_DA_STRING);
    indice_2 -= 2;

    for(indice_1 = 0; indice_1 < indice_2; indice_1++, indice_2--)
	{
		string_a_inverter[indice_1] = string_a_inverter[indice_1] ^ string_a_inverter[indice_2];
        string_a_inverter[indice_2] = string_a_inverter[indice_1] ^ string_a_inverter[indice_2];
        string_a_inverter[indice_1] = string_a_inverter[indice_1] ^ string_a_inverter[indice_2];
    }
    
    return string_a_inverter;
}
