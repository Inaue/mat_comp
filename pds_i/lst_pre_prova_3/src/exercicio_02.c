#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define SUCESSO          0
#define FIM_DE_STR       '\0'
#define CHARS_FIM_DE_STR 1
#define CHARS_PALAVRA    (50   + CHARS_FIM_DE_STR)
#define CHARS_LINHA      (5000 + CHARS_FIM_DE_STR)

int  main           (int argc, char ** argv);
void padronizaLinha (char linha[]);

int main(int argc, char ** argv)
{
	char   linhaDoTexto[CHARS_LINHA] = "";
	char * numeroDoTexto;

	while(fgets(linhaDoTexto, CHARS_LINHA, stdin) != NULL)
	{
		padronizaLinha(linhaDoTexto);
		numeroDoTexto = strtok(linhaDoTexto, " ");

		while(numeroDoTexto != NULL)
		{
			printf("%11.5lf\n", strtod(numeroDoTexto, NULL));
			numeroDoTexto = strtok(NULL, " ");
		}
	}

	return SUCESSO;
}

void padronizaLinha(char linha[])
{
	while(*linha != FIM_DE_STR)
	{
		if((*linha != '.') && !isdigit(*linha))
			*linha = ' ';

		linha++;
	}
}

