#include <stdio.h>
#include <string.h>

#define SUCESSO         0
#define VERDADEIRO      (1 == 1)
#define FALSO           !VERDADEIRO
#define FIM_DE_STR      '\0'
#define CHAR_FIM_DE_STR 1
#define MAX_STR         (75 + CHAR_FIM_DE_STR)

int main(int argc, char ** argv);
void remova_quebra_de_linha (char string[]);

int main(int argc, char ** argv)
{
	FILE * arquivo_de_saida = fopen(argv[1], "r");
	char linha_da_entrada[MAX_STR], linha_da_saida[MAX_STR];
	unsigned char linha_atual = 0;

	printf("\n");
	printf("      DISCREPANCIAS:\n");
	printf("    | %-*s | %-*s \n", MAX_STR, "ENTRADA", MAX_STR, "SAIDA");

	while(VERDADEIRO)
	{
		fgets(linha_da_entrada, MAX_STR, stdin);
		remova_quebra_de_linha(linha_da_entrada);
		fgets(linha_da_saida, MAX_STR, arquivo_de_saida);
		remova_quebra_de_linha(linha_da_saida);

		if(feof(stdin) && feof(arquivo_de_saida))
			break;

		if(feof(stdin))
			strcpy(linha_da_entrada, "FIM DA ENTRADA");

		if(feof(arquivo_de_saida))
			strcpy(linha_da_saida, "FIM DA SAIDA");

		if(strcmp(linha_da_entrada, linha_da_saida) != 0)
			printf("%3hhu | %-*s | %-*s \n", linha_atual, MAX_STR, linha_da_entrada, MAX_STR, linha_da_saida);

		linha_atual++;

	}

	printf("\n");

	fclose(arquivo_de_saida);
	
	return SUCESSO;
}

void remova_quebra_de_linha(char string[])
{
	while(*string != '\n' && *string != FIM_DE_STR)
		string++;

	*string = FIM_DE_STR;
}

