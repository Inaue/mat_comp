#include <stdio.h>
#include <string.h>

#define SUCESSO           0
#define FIM_DE_STR        '\0'
#define CHAR_FIM_DE_STR   1
#define MAX_LEN_ANAGRAMAS (14 + CHAR_FIM_DE_STR)

int  main                   (int argc, char ** argv);
void remova_quebra_de_linha (char string[]);
void imprimaPermutacoes     (char prefixo[], char opcoes[]);
char removaOpcao            (char opcoes[], unsigned short opcaoARemover);
void strInsiraChrNoFim      (char string[], char caractere);
void strRemovaChrNoFim      (char string[]);

int main(int argc, char ** argv)
{
	char prefixoDosAnagramas[MAX_LEN_ANAGRAMAS] = "";
	char stringDosAnagramas[MAX_LEN_ANAGRAMAS];

	printf("digite uma string (maximo %d caracteres):\n", MAX_LEN_ANAGRAMAS - 1);
	fgets(stringDosAnagramas, MAX_LEN_ANAGRAMAS, stdin);
	remova_quebra_de_linha(stringDosAnagramas);

	printf("anagramas da string:\n");
	imprimaPermutacoes(prefixoDosAnagramas, stringDosAnagramas);

	return SUCESSO;
}

void imprimaPermutacoes(char prefixo[], char opcoes[])
{
	unsigned short opcao, quantidadeDeOpcoes = strlen(opcoes);

	if(tamanhoPrefixo == quantidadeDeOpcoes)
	{
		printf("%s\n", prefixo);

		return;
	}

	for(opcao = 0; opcao < quantidadeDeOpcoes; opcao++)
	{
		if(opcoes[opcao] != ' ')
		{
			strInsiraChrNoFim(prefixo, removaOpcao(opcoes, opcao));
			imprimaPermutacoes(prefixo, opcoes);
			opcoes[opcao] = strRemovaChrNoFim(prefixo);
		}
	}
}

void remova_quebra_de_linha(char string[])
{
	while(*string != '\n' && *string != FIM_DE_STR)
		string++;

	*string = FIM_DE_STR;
}

char removaOpcao(char opcoes[], unsigned short opcaoARemover)
{
	char tmpChr = opcoes[opcaoARemover];

	opcoes[opcaoARemover] = ' ';

	return tmpChr;
}

void strInsiraChrNoFim(char string[], char caractere)
{
	unsigned short tamanho = 0;

	while(string[tamanho] != FIM_DE_STR)
		tamanho++;

	string[tamanho]     = caractere;
	string[tamanho + 1] = FIM_DE_STR;
}

char strRemovaChrNoFim(char string[])
{
	char           tmpChr;
	unsigned short tamanho = 0;

	if(string[0] == FIM_DE_STR)
		return;

	while(string[tamanho] != FIM_DE_STR)
		tamanho++;

	tmpChr              = string[tamanho - 1];
	string[tamanho - 1] = FIM_DE_STR;

	return tmpChr;
}

