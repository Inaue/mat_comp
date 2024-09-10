#include <stdio.h>
#include "cotahist.h"

#define SUCESSO  0
#define BAD_ARG 10
#define NOT_FIL 20
#define BAD_IN  30

int main (int argc, char* argv[]);

int main(int argc, char* argv[])
{
	FILE*         serieHistorica;
	Reg00         cabecalho;
	Reg01         cotacao;
	Reg99         trailer;
	char          buffer [STR_REGISTRO];
	char          campo  [STR_CAMPO];
	unsigned char tipo;

	if(argc == 1)
		return BAD_ARG;

	serieHistorica = fopen(argv[1], "r");

	if(serieHistorica == NULL)
		return NOT_FIL;

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

				imprimaReg00(cabecalho, stdout);
				break;
			case 01:
				if(!extraiaReg01(&cotacao, buffer))
					return BAD_IN;

				imprimaReg01(cotacao, stdout);
				break;
			case 99:
				if(!extraiaReg99(&trailer, buffer))
					return BAD_IN;

				imprimaReg99(trailer, stdout);
				break;
		}
	}
	while(tipo != 99);

	fclose(serieHistorica);

	return SUCESSO;
}
