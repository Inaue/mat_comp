#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define SUCESSO          0
#define N_ENCONTRADO     1
#define FIM_DE_STR       '\0'
#define CHARS_FIM_DE_STR 1
#define CHARS_PALAVRA    (50   + CHARS_FIM_DE_STR)
#define CHARS_LINHA      (5000 + CHARS_FIM_DE_STR)

typedef struct
{
	char           palavra[CHARS_PALAVRA];
	unsigned short repeticoes;
}
Frequencia;

int           main                     (int argc, char ** argv);
void          padronizaLinha           (char linha[]);
void          imprimaHistograma        (FILE * saida, Frequencia histograma[], unsigned palavrasDistintas);
unsigned      criaHistogramaDePalavras (FILE * entrada, Frequencia histograma[]);
unsigned      insiraPalavraHisto       (char palavraAInserir[], Frequencia histograma[], unsigned palavrasDistintas);
unsigned      contaPalavrasArquivo     (FILE * entrada);
unsigned char contaPalavrasLinha       (char linha[]);

int main(int argc, char ** argv)
{
	unsigned     palavrasDistintas = 0, palavrasNoArquivo = 0;
	FILE       * entrada;
	Frequencia * histograma;
	
	if(argc > 1)
	{
		entrada = fopen(argv[1], "r");

		if(entrada == NULL)
			return N_ENCONTRADO;

		palavrasNoArquivo = contaPalavrasArquivo(entrada);
		histograma        = malloc(palavrasNoArquivo * sizeof(Frequencia));
		fclose(entrada);
		entrada           = fopen(argv[1], "r");
		palavrasDistintas = criaHistogramaDePalavras(entrada, histograma);
		fclose(entrada);

		imprimaHistograma(stdout, histograma, palavrasDistintas);

		free(histograma);
	}

	return SUCESSO;
}

void padronizaLinha(char linha[])
{
	while(*linha != FIM_DE_STR)
	{
		*linha = isalpha(*linha) ? *linha : ' ';
		*linha = isupper(*linha) ? tolower(*linha) : *linha;
		linha++;
	}
}
	
unsigned char contaPalavrasLinha(char linha[])
{
	unsigned char totalDePalavras = isalpha(*linha) ? 1 : 0;
	
	while(*linha != FIM_DE_STR)
	{
		if(!isalpha(*linha) && isalpha(*(linha + 1)))
			totalDePalavras++;
			
		linha++;
	}
	
	return totalDePalavras;
}

unsigned insiraPalavraHisto(char palavraAInserir[], Frequencia histograma[], unsigned palavrasDistintas)
{
	unsigned palavraVerificada;

	for(palavraVerificada = 0; palavraVerificada < palavrasDistintas; palavraVerificada++)
	{
		if(strcmp(histograma[palavraVerificada].palavra, palavraAInserir) == 0)
		{
			histograma[palavraVerificada].repeticoes++;

			return palavrasDistintas;
		}
	}

	strcpy(histograma[palavrasDistintas].palavra, palavraAInserir);
	histograma[palavrasDistintas].repeticoes = 1;

	return palavrasDistintas + 1;
}

unsigned contaPalavrasArquivo(FILE * entrada)
{
	char     linhaDoTexto[CHARS_LINHA] = "";
	unsigned totalDePalavras = 0;

	while(fgets(linhaDoTexto, CHARS_LINHA, entrada) != NULL)
	{
		padronizaLinha(linhaDoTexto);
		totalDePalavras += contaPalavrasLinha(linhaDoTexto);
	}
	
	return totalDePalavras;
}

unsigned criaHistogramaDePalavras(FILE * entrada, Frequencia histograma[])
{
	char     linhaDoTexto[CHARS_LINHA] = "";
	char *   palavraDoTexto;
	unsigned palavrasDistintas = 0;

	while(fgets(linhaDoTexto, CHARS_LINHA, entrada) != NULL)
	{
		padronizaLinha(linhaDoTexto);
		palavraDoTexto = strtok(linhaDoTexto, " ");

		while(palavraDoTexto != NULL)
		{
			palavrasDistintas = insiraPalavraHisto(palavraDoTexto, histograma, palavrasDistintas);
			palavraDoTexto    = strtok(NULL, " ");
		}
	}

	return palavrasDistintas;
}

void imprimaHistograma(FILE * saida, Frequencia histograma[], unsigned palavrasDistintas)
{
	unsigned palavraAImprimir = 0;

	for(palavraAImprimir = 0; palavraAImprimir < palavrasDistintas; palavraAImprimir++)

		fprintf(saida, "%03hhu %-*s\n", histograma[palavraAImprimir].repeticoes, CHARS_PALAVRA, histograma[palavraAImprimir].palavra);
}
