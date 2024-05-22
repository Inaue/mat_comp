#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SUCESSO              0
#define ARQUIVO_NAO_ABERTO   1
#define VERDADEIRO           (1 == 1)
#define FALSO                !VERDADEIRO
#define FIM_DE_STR           '\0'
#define CHAR_FIM_DE_STR      1
#define FIM_DE_CABECALHO     ""
#define STR_FIM_DE_CABECALHO 1
#define MAX_CAMPOS           (32 + STR_FIM_DE_CABECALHO)
#define CHAR_SEPARADOR       1
#define CHARS_MASCARA        (10 + CHAR_FIM_DE_STR)
#define CHARS_CABECALHO      (MAX_CAMPOS * (CHARS_MASCARA + CHAR_SEPARADOR) + CHAR_FIM_DE_STR)
#define CHARS_REGISTRO       (1000 + CHAR_FIM_DE_STR)
#define CHARS_CAMPO          ((unsigned short) (CHARS_REGISTRO / MAX_CAMPOS * 1.2f) + CHAR_FIM_DE_STR)

int  main                   ();
void remova_quebra_de_linha (char string[]);
void le_cabecalho           (FILE * arquivo_de_leitura, char cabecalho[MAX_CAMPOS][CHARS_MASCARA], char separador[]);
void tabule_registro        (FILE * arquivo_de_escrita, char cabecalho[MAX_CAMPOS][CHARS_MASCARA], char registro[CHARS_REGISTRO], char separador[]);
void imprime_campo          (FILE * arquivo_de_escrita, char mascara[CHARS_MASCARA], char campo[CHARS_CAMPO]);

int main()
{
	char cabecalho[MAX_CAMPOS][CHARS_MASCARA];
	char registro[CHARS_REGISTRO];
	char * leitura_do_registro;

	le_cabecalho(stdin, cabecalho, " ");

	while(VERDADEIRO)
	{
		leitura_do_registro = fgets(registro, CHARS_REGISTRO, stdin);
		
		if(leitura_do_registro == NULL)
			break;

		remova_quebra_de_linha(registro);
		tabule_registro(stdout, cabecalho, registro, ";");
	}

	return SUCESSO;
}

void le_cabecalho(FILE * arquivo_de_leitura, char cabecalho[MAX_CAMPOS][CHARS_MASCARA], char separador[])
{
	char buffer[CHARS_CABECALHO];
	unsigned char mascara, campos;

	fgets(buffer, CHARS_CABECALHO, arquivo_de_leitura);
	remova_quebra_de_linha(buffer);
	
	campos = strtol(strtok(buffer, separador), NULL, 10);

	for(mascara = 0; mascara < campos; mascara++)
	{
		strcpy(cabecalho[mascara], strtok(NULL, separador));
	}

	strcpy(cabecalho[mascara], FIM_DE_CABECALHO);
}

void remova_quebra_de_linha(char string[])
{
	while(*string != '\n')
		string++;

	*string = FIM_DE_STR;
}

void tabule_registro(FILE * arquivo_de_escrita, char cabecalho[MAX_CAMPOS][CHARS_MASCARA], char registro[CHARS_REGISTRO], char separador[])
{
	char campo[CHARS_CAMPO];
	char * pedaco_do_registro;
	unsigned char mascara = 0;

	strcpy(campo, strtok(registro, separador));
	imprime_campo(arquivo_de_escrita, cabecalho[mascara], campo);
	putc(' ', arquivo_de_escrita);
	
	for(mascara = 1; strcmp(cabecalho[mascara], FIM_DE_CABECALHO) != 0; mascara++)
	{
		pedaco_do_registro = strtok(NULL, separador);

		if(pedaco_do_registro == NULL)
			break;

		strcpy(campo, pedaco_do_registro);
		imprime_campo(arquivo_de_escrita, cabecalho[mascara], campo);
		putc(' ', arquivo_de_escrita);
	}

	putc('\n', arquivo_de_escrita);
}

void imprime_campo(FILE * arquivo_de_escrita, char mascara[CHARS_MASCARA], char campo[CHARS_CAMPO])
{
	if((strchr(mascara, 'i') != NULL) || (strchr(mascara, 'd') != NULL))

		fprintf(arquivo_de_escrita, mascara, strtoll(campo, NULL, 10));

	else if(strchr(mascara, 'u') != NULL)

		fprintf(arquivo_de_escrita, mascara, strtoull(campo, NULL, 10));
	
	else if(strchr(mascara, 'f') != NULL)

		fprintf(arquivo_de_escrita, mascara, strtod(campo, NULL));
	
	else if(strchr(mascara, 'c') != NULL)

		fprintf(arquivo_de_escrita, mascara, campo[0]);
	
	else if(strchr(mascara, 's') != NULL)

		fprintf(arquivo_de_escrita, mascara, campo);
}
