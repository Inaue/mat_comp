#include <stdio.h>

#define SUCESSO          0
#define TOTAL_DE_PESSOAS 10

typedef struct
{
    float salario;
    unsigned char idade;
    unsigned char numero_de_filhes;
}
pessoa;

int main();
void le_pessoa(FILE * arquivo_de_entrada, pessoa * pessoa_a_ler);
float obter_media_salarial(pessoa amostra[], unsigned short tamanho_da_amostragem);
float obter_media_de_filhes(pessoa amostra[], unsigned short tamanho_da_amostragem);
float obter_maior_salario(pessoa amostra[], unsigned short tamanho_da_amostragem);
float obter_percentual_com_salario_maior_que(pessoa amostra[], unsigned short tamanho_da_amostragem, float salario_limite);

int main()
{
    FILE * arquivo_com_dados = fopen("pessoas.txt", "r");
    pessoa amostragem[TOTAL_DE_PESSOAS];
    unsigned char indice_pessoa;
    float media_salarial;
    float media_de_filhes;
    float maior_salario;
    float percentual_de_ricos;

    for(indice_pessoa = 0; indice_pessoa < TOTAL_DE_PESSOAS; indice_pessoa++)
    {
        le_pessoa(arquivo_com_dados, &amostragem[indice_pessoa]);
    }

    media_salarial      = obter_media_salarial(amostragem, TOTAL_DE_PESSOAS);
    media_de_filhes     = obter_media_de_filhes(amostragem, TOTAL_DE_PESSOAS);
    maior_salario       = obter_maior_salario(amostragem, TOTAL_DE_PESSOAS);
    percentual_de_ricos = obter_percentual_com_salario_maior_que(amostragem, TOTAL_DE_PESSOAS, 1000.00);

    printf("media salarial:      %8.2f\n", media_salarial);
    printf("media de filhes:     %8.2f\n", media_de_filhes);
    printf("maior salario:       %8.2f\n", maior_salario);
    printf("percentual de ricos: %8.2f\n", percentual_de_ricos);

    fclose(arquivo_com_dados);

	return SUCESSO;
}

void le_pessoa(FILE * arquivo_de_entrada, pessoa * pessoa_a_ler)
{
    fscanf(arquivo_de_entrada, "%f %hhu %hhu", &pessoa_a_ler->salario, &pessoa_a_ler->idade, &pessoa_a_ler->numero_de_filhes);
}

float obter_media_salarial(pessoa amostra[], unsigned short tamanho_da_amostragem)
{
    float soma = 0.0f;
    unsigned short pessoa_analisada;

    for(pessoa_analisada = 0; pessoa_analisada < tamanho_da_amostragem; pessoa_analisada++)
    {
        soma += amostra[pessoa_analisada].salario;
    }

    return soma / tamanho_da_amostragem;
}

float obter_maior_salario(pessoa amostra[], unsigned short tamanho_da_amostragem)
{
    float maior_salario = 0.0f;
    unsigned short pessoa_analisada;

    for(pessoa_analisada = 0; pessoa_analisada < tamanho_da_amostragem; pessoa_analisada++)
        if(amostra[pessoa_analisada].salario > maior_salario)
        
            maior_salario = amostra[pessoa_analisada].salario;

    return maior_salario;
}

float obter_percentual_com_salario_maior_que(pessoa amostra[], unsigned short tamanho_da_amostragem, float salario_limite)
{
    unsigned short contagem_de_casos_favoraveis = 0;
    unsigned short pessoa_analisada;

    for(pessoa_analisada = 0; pessoa_analisada < tamanho_da_amostragem; pessoa_analisada++)
        if(amostra[pessoa_analisada].salario > salario_limite)
        
            contagem_de_casos_favoraveis++;

    return ((float) contagem_de_casos_favoraveis) / tamanho_da_amostragem * 100;
}

float obter_media_de_filhes(pessoa amostra[], unsigned short tamanho_da_amostragem)
{
    unsigned short soma = 0;
    unsigned short pessoa_analisada;

    for(pessoa_analisada = 0; pessoa_analisada < tamanho_da_amostragem; pessoa_analisada++)
    {
        soma += amostra[pessoa_analisada].numero_de_filhes;
    }

    return (float) soma / tamanho_da_amostragem;
}
