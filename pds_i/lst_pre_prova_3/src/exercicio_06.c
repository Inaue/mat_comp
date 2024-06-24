#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SUCESSO         0
#define FIM_DE_STR      '\0'
#define CHAR_FIM_DE_STR 1

int  main                   (int argc, char ** argv);
void strInverta             (char * string, unsigned tamanho);
void remova_quebra_de_linha (char string[]);

int main(int argc, char ** argv)
{
	char     * string;
	unsigned   tamanho;

	printf("digita um tamanho pra string:\n");
	scanf("%u", &tamanho);
	getchar();
	string = malloc((tamanho + CHAR_FIM_DE_STR) * sizeof(char));

	printf("digita a string:\n");
	fgets(string, tamanho, stdin);
	remova_quebra_de_linha(string);
	strInverta(string, strlen(string));

	printf("string invertida:\n");
	printf("%s\n", string);

	free(string);

	return SUCESSO;
}

void strInverta(char * string, unsigned tamanho)
{
	if(tamanho < 2)
		return;

	string[0]           ^= string[tamanho - 1];
	string[tamanho - 1] ^= string[0];
	string[0]           ^= string[tamanho - 1];
	
	strInverta(&string[1], tamanho - 2);
}

void remova_quebra_de_linha(char string[])
{
	while(*string != '\n' && *string != FIM_DE_STR)
		string++;

	*string = FIM_DE_STR;
}

