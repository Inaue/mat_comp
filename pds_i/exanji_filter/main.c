#include <stdio.h>
#include <string.h>
#include "cotahist.h"

#define SUCESSO  0
#define BAD_ARG 10
#define NOT_FIL 20
#define BAD_IN  30

int main (int argc, char* argv[]);

bool ehFiltroValido  (char* argv[]);
bool ehChaveNumerica (char* argv[]);
bool ehChaveData     (char* argv[]);
bool filtrarReg      (Reg01 registro, char* argv[]);

int main(int argc, char* argv[])
{
	FILE*              serieHistorica;
	FILE*              serieFiltrada;
	Reg00              cabecalho;
	Reg01              cotacao;
	Reg99              trailer;
	Data               dataGeracao;
	char               buffer [STR_REGISTRO];
	unsigned char      tipo;
	unsigned long long totalRegistros = 0;

	if(argc != 6)
		return BAD_ARG;

	if(!ehFiltroValido(argv))
		return BAD_ARG;

	if(!extraiaData(&dataGeracao, argv[5]))
		return BAD_ARG;

	serieHistorica = fopen(argv[1], "r");
	serieFiltrada  = fopen(argv[2], "w");

	if(serieHistorica == NULL || serieFiltrada == NULL)
		return NOT_FIL;
	
	removaReservas(argv[4]);

	do
	{
		fgets(buffer, STR_REGISTRO, serieHistorica);
		fgetc(serieHistorica);
		tipo = identificaTipoReg(buffer);

		switch(tipo)
		{
			case 00:
				if(!extraiaReg00(&cabecalho, buffer))
					return BAD_IN;

				cabecalho.dataGeracao.ano = dataGeracao.ano;
				cabecalho.dataGeracao.mes = dataGeracao.mes;
				cabecalho.dataGeracao.dia = dataGeracao.dia;
				strcpy(cabecalho.nomeArquivo, argv[2]);
				inserirReg00(cabecalho, buffer);

				fputs(buffer, serieFiltrada);
				fputc('\n', serieFiltrada);
				break;
			case 01:
				if(!extraiaReg01(&cotacao, buffer))
					return BAD_IN;

				if(filtrarReg(cotacao, argv))
				{
					totalRegistros++;
					inserirReg01(cotacao, buffer);

					fputs(buffer, serieFiltrada);
					fputc('\n', serieFiltrada);
				}

				break;
			case 99:
				if(!extraiaReg99(&trailer, buffer))
					return BAD_IN;

				trailer.dataGeracao.ano = dataGeracao.ano;
				trailer.dataGeracao.mes = dataGeracao.mes;
				trailer.dataGeracao.dia = dataGeracao.dia;
				trailer.totalRegistros  = totalRegistros;
				strcpy(trailer.nomeArquivo, argv[2]);
				inserirReg99(trailer, buffer);

				fputs(buffer, serieFiltrada);
				fputc('\n', serieFiltrada);
				break;
		}
	}
	while(tipo != 99);

	fclose(serieHistorica);
	fclose(serieFiltrada);

	return SUCESSO;
}

bool ehFiltroValido(char* argv[])
{
	if(strcmp(argv[3], "codneg") == 0)
		return true;

	if(strcmp(argv[3], "codisi") == 0)
		return true;

	if(strcmp(argv[3], "data") == 0 && ehChaveNumerica(argv))
		return true;

	if(strcmp(argv[3], "tpmerc") == 0 && ehChaveNumerica(argv))
		return true;

	if(strcmp(argv[3], "preabe") == 0 && ehChaveNumerica(argv))
		return true;

	if(strcmp(argv[3], "premax") == 0 && ehChaveNumerica(argv))
		return true;

	if(strcmp(argv[3], "premed") == 0 && ehChaveNumerica(argv))
		return true;

	if(strcmp(argv[3], "premin") == 0 && ehChaveNumerica(argv))
		return true;

	if(strcmp(argv[3], "preult") == 0 && ehChaveNumerica(argv))
		return true;

	if(strcmp(argv[3], "preofc") == 0 && ehChaveNumerica(argv))
		return true;

	if(strcmp(argv[3], "preofv") == 0 && ehChaveNumerica(argv))
		return true;

	if(strcmp(argv[3], "totneg") == 0 && ehChaveNumerica(argv))
		return true;

	if(strcmp(argv[3], "quatot") == 0 && ehChaveNumerica(argv))
		return true;

	if(strcmp(argv[3], "voltot") == 0 && ehChaveNumerica(argv))
		return true;

	if(strcmp(argv[3], "ptoexe") == 0 && ehChaveNumerica(argv))
		return true;

	return false;
}

bool ehChaveNumerica(char* argv[])
{
	unsigned char d;

	if(argv[4][0] != '<' && argv[4][0] != '>' && argv[4][0] != '=')
		return false;

	for(d = 1; argv[4][d] != '\0'; d++)
		if(!('0' <= argv[4][d] && argv[4][d] <= '9'))
			return false;

	return true;
}

bool filtrarReg(Reg01 registro, char* argv[])
{
	Data dataPregao;
	char comparacaoData;

	if(strcmp(argv[3], "codneg") == 0 && strcmp(registro.codneg, argv[4]) == 0)
		return true;

	if(strcmp(argv[3], "codisi") == 0 && strcmp(registro.codisi, argv[4]) == 0)
		return true;

	if(strcmp(argv[3], "data") == 0)
	{
		extraiaData(&dataPregao, &argv[4][1]);
		comparacaoData = comparaData(registro.dataPregao, dataPregao);

		if( (argv[4][0] == '=' && comparacaoData == 0) ||
		    (argv[4][0] == '<' && comparacaoData  < 0) ||
		    (argv[4][0] == '>' && comparacaoData  > 0) )

			return true;
	}

	if(strcmp(argv[3], "tpmerc") == 0)
	{
		if( (argv[4][0] == '=' && registro.tpmerc == strtoull(&argv[4][1], NULL, 10)) ||
		    (argv[4][0] == '<' && registro.tpmerc  < strtoull(&argv[4][1], NULL, 10)) ||
		    (argv[4][0] == '>' && registro.tpmerc  > strtoull(&argv[4][1], NULL, 10)) )

			return true;
	}

	if(strcmp(argv[3], "preabe") == 0)
	{
		if( (argv[4][0] == '=' && registro.preabe == strtoull(&argv[4][1], NULL, 10)) ||
		    (argv[4][0] == '<' && registro.preabe  < strtoull(&argv[4][1], NULL, 10)) ||
		    (argv[4][0] == '>' && registro.preabe  > strtoull(&argv[4][1], NULL, 10)) )

			return true;
	}

	if(strcmp(argv[3], "preult") == 0)
	{
		if( (argv[4][0] == '=' && registro.preult == strtoull(&argv[4][1], NULL, 10)) ||
		    (argv[4][0] == '<' && registro.preult  < strtoull(&argv[4][1], NULL, 10)) ||
		    (argv[4][0] == '>' && registro.preult  > strtoull(&argv[4][1], NULL, 10)) )

			return true;
	}

	if(strcmp(argv[3], "premax") == 0)
	{
		if( (argv[4][0] == '=' && registro.premax == strtoull(&argv[4][1], NULL, 10)) ||
		    (argv[4][0] == '<' && registro.premax  < strtoull(&argv[4][1], NULL, 10)) ||
		    (argv[4][0] == '>' && registro.premax  > strtoull(&argv[4][1], NULL, 10)) )

			return true;
	}

	if(strcmp(argv[3], "premed") == 0)
	{
		if( (argv[4][0] == '=' && registro.premed == strtoull(&argv[4][1], NULL, 10)) ||
		    (argv[4][0] == '<' && registro.premed  < strtoull(&argv[4][1], NULL, 10)) ||
		    (argv[4][0] == '>' && registro.premed  > strtoull(&argv[4][1], NULL, 10)) )

			return true;
	}

	if(strcmp(argv[3], "premin") == 0)
	{
		if( (argv[4][0] == '=' && registro.premin == strtoull(&argv[4][1], NULL, 10)) ||
		    (argv[4][0] == '<' && registro.premin  < strtoull(&argv[4][1], NULL, 10)) ||
		    (argv[4][0] == '>' && registro.premin  > strtoull(&argv[4][1], NULL, 10)) )

			return true;
	}

	if(strcmp(argv[3], "preofc") == 0)
	{
		if( (argv[4][0] == '=' && registro.preofc == strtoull(&argv[4][1], NULL, 10)) ||
		    (argv[4][0] == '<' && registro.preofc  < strtoull(&argv[4][1], NULL, 10)) ||
		    (argv[4][0] == '>' && registro.preofc  > strtoull(&argv[4][1], NULL, 10)) )

			return true;
	}

	if(strcmp(argv[3], "preofv") == 0)
	{
		if( (argv[4][0] == '=' && registro.preofv == strtoull(&argv[4][1], NULL, 10)) ||
		    (argv[4][0] == '<' && registro.preofv  < strtoull(&argv[4][1], NULL, 10)) ||
		    (argv[4][0] == '>' && registro.preofv  > strtoull(&argv[4][1], NULL, 10)) )

			return true;
	}

	if(strcmp(argv[3], "totneg") == 0)
	{
		if( (argv[4][0] == '=' && registro.totneg == strtoull(&argv[4][1], NULL, 10)) ||
		    (argv[4][0] == '<' && registro.totneg  < strtoull(&argv[4][1], NULL, 10)) ||
		    (argv[4][0] == '>' && registro.totneg  > strtoull(&argv[4][1], NULL, 10)) )

			return true;
	}

	if(strcmp(argv[3], "quatot") == 0)
	{
		if( (argv[4][0] == '=' && registro.quatot == strtoull(&argv[4][1], NULL, 10)) ||
		    (argv[4][0] == '<' && registro.quatot  < strtoull(&argv[4][1], NULL, 10)) ||
		    (argv[4][0] == '>' && registro.quatot  > strtoull(&argv[4][1], NULL, 10)) )

			return true;
	}

	if(strcmp(argv[3], "voltot") == 0)
	{
		if( (argv[4][0] == '=' && registro.voltot == strtoull(&argv[4][1], NULL, 10)) ||
		    (argv[4][0] == '<' && registro.voltot  < strtoull(&argv[4][1], NULL, 10)) ||
		    (argv[4][0] == '>' && registro.voltot  > strtoull(&argv[4][1], NULL, 10)) )

			return true;
	}

	if(strcmp(argv[3], "ptoexe") == 0)
	{
		if( (argv[4][0] == '=' && registro.ptoexe == strtoull(&argv[4][1], NULL, 10)) ||
		    (argv[4][0] == '<' && registro.ptoexe  < strtoull(&argv[4][1], NULL, 10)) ||
		    (argv[4][0] == '>' && registro.ptoexe  > strtoull(&argv[4][1], NULL, 10)) )

			return true;
	}

	return false;
}
