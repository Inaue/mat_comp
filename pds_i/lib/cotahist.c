#include "cotahist.h"

unsigned char identificaTipoReg(char buffer [STR_REGISTRO])
{
	char campo [STR_CAMPO];

	extraiaCampo(campo, buffer, 0, 1);

	return strtoul(campo, NULL, 10);
}

bool extraiaReg00(Reg00* registro, char buffer [STR_REGISTRO])
{
	char campo [STR_CAMPO];

	if(!extraiaCampo(campo, buffer, 0, 1) || strcmp(campo, "00") != 0)
		return false;

	registro->tipo = strtoul(campo, NULL, 10);

	if(!extraiaCampo(campo, buffer, 2, 14))
		return false;

	removaReservas(campo);
	strcpy(registro->nomeArquivo, campo);

	if(!extraiaCampo(campo, buffer, 15, 22))
		return false;

	removaReservas(campo);
	strcpy(registro->origemArquivo, campo);

	if(!extraiaCampo(campo, buffer, 23, 30) || !extraiaData(&registro->dataGeracao, campo))
		return false;

	return true;
}

bool extraiaReg01(Reg01* registro, char buffer [STR_REGISTRO])
{
	char campo [STR_CAMPO];

	if(!extraiaCampo(campo, buffer, 0, 1) || strcmp(campo, "01") != 0)
		return false;

	registro->tipo = strtoul(campo, NULL, 10);

	if(!extraiaCampo(campo, buffer, 2, 9) || !extraiaData(&registro->dataPregao, campo))
		return false;

	if(!extraiaCampo(campo, buffer, 10, 11))
		return false;

	removaReservas(campo);
	strcpy(registro->codbdi, campo);

	if(!extraiaCampo(campo, buffer, 12, 23))
		return false;

	removaReservas(campo);
	strcpy(registro->codneg, campo);

	if(!extraiaCampo(campo, buffer, 24, 26) || !ehNumerico(campo))
		return false;

	registro->tpmerc = strtoul(campo, NULL, 10);

	if(!extraiaCampo(campo, buffer, 27, 38))
		return false;

	removaReservas(campo);
	strcpy(registro->nomres, campo);

	if(!extraiaCampo(campo, buffer, 39, 48))
		return false;

	removaReservas(campo);
	strcpy(registro->especi, campo);

	if(!extraiaCampo(campo, buffer, 49, 51))
		return false;

	removaReservas(campo);
	strcpy(registro->prazot, campo);

	if(!extraiaCampo(campo, buffer, 52, 55))
		return false;

	removaReservas(campo);
	strcpy(registro->modref, campo);

	if(!extraiaCampo(campo, buffer, 56, 68) || !ehNumerico(campo))
		return false;

	registro->preabe = strtoull(campo, NULL, 10);

	if(!extraiaCampo(campo, buffer, 69, 81) || !ehNumerico(campo))
		return false;

	registro->premax = strtoull(campo, NULL, 10);

	if(!extraiaCampo(campo, buffer, 82, 94) || !ehNumerico(campo))
		return false;

	registro->premin = strtoull(campo, NULL, 10);

	if(!extraiaCampo(campo, buffer, 95, 107) || !ehNumerico(campo))
		return false;

	registro->premed = strtoull(campo, NULL, 10);

	if(!extraiaCampo(campo, buffer, 108, 120) || !ehNumerico(campo))
		return false;

	registro->preult = strtoull(campo, NULL, 10);

	if(!extraiaCampo(campo, buffer, 121, 133) || !ehNumerico(campo))
		return false;

	registro->preofc = strtoull(campo, NULL, 10);

	if(!extraiaCampo(campo, buffer, 134, 146) || !ehNumerico(campo))
		return false;

	registro->preofv = strtoull(campo, NULL, 10);

	if(!extraiaCampo(campo, buffer, 147, 151) || !ehNumerico(campo))
		return false;

	registro->totneg = strtoul(campo, NULL, 10);

	if(!extraiaCampo(campo, buffer, 152, 169) || !ehNumerico(campo))
		return false;

	registro->quatot = strtoull(campo, NULL, 10);

	if(!extraiaCampo(campo, buffer, 170, 187) || !ehNumerico(campo))
		return false;

	registro->voltot = strtoull(campo, NULL, 10);

	if(!extraiaCampo(campo, buffer, 188, 200) || !ehNumerico(campo))
		return false;

	registro->preexe = strtoull(campo, NULL, 10);

	if(!extraiaCampo(campo, buffer, 201, 201) || !ehNumerico(campo))
		return false;

	registro->preexe = strtoull(campo, NULL, 10);

	if(!extraiaCampo(campo, buffer, 202, 209) || !extraiaData(&registro->datven, campo))
		return false;

	if(!extraiaCampo(campo, buffer, 210, 216) || !ehNumerico(campo))
		return false;

	registro->fatcot = strtoul(campo, NULL, 10);

	if(!extraiaCampo(campo, buffer, 217, 229) || !ehNumerico(campo))
		return false;

	registro->ptoexe = strtoull(campo, NULL, 10);

	if(!extraiaCampo(campo, buffer, 230, 241))
		return false;

	removaReservas(campo);
	strcpy(registro->codisi, campo);

	if(!extraiaCampo(campo, buffer, 242, 244) || !ehNumerico(campo))
		return false;

	registro->dismes = strtoul(campo, NULL, 10);

	return true;
}

bool extraiaReg99(Reg99* registro, char buffer [STR_REGISTRO])
{
	char campo [STR_CAMPO];

	if(!extraiaCampo(campo, buffer, 0, 1) || strcmp(campo, "99") != 0)
		return false;

	registro->tipo = strtoul(campo, NULL, 10);

	if(!extraiaCampo(campo, buffer, 2, 14))
		return false;

	removaReservas(campo);
	strcpy(registro->nomeArquivo, campo);

	if(!extraiaCampo(campo, buffer, 15, 22))
		return false;

	removaReservas(campo);
	strcpy(registro->origemArquivo, campo);

	if(!extraiaCampo(campo, buffer, 23, 30) || !extraiaData(&registro->dataGeracao, campo))
		return false;

	if(!extraiaCampo(campo, buffer, 31, 41) || !ehNumerico(campo))
		return false;

	registro->totalRegistros = strtoull(campo, NULL, 10);

	return true;
}

bool extraiaCampo(char campo [STR_CAMPO], char buffer [STR_REGISTRO], unsigned char inicio, unsigned char fim)
{
	unsigned char i, j = 0;

	if(inicio > fim)
		return false;

	if(inicio >= STR_REGISTRO || fim >= STR_REGISTRO)
		return false;

	for(i = inicio; i <= fim; i++, j++)
		campo[j] = buffer[i];

	campo[j] = '\0';
	
	return true;
}

void removaReservas(char campo [STR_CAMPO])
{
	unsigned char i = 0, j = 0, k = 0;

	while(campo[j] != '\0') j++;

	if(i == j--) return;

	while(campo[i] == ' ' && i != j) i++;

	if(i == j && campo[i] == ' ') return;

	while(campo[j] == ' ' && i != j) j--;

	if(i == j && campo[j] == ' ') return;

	for(k = 0; i + k <= j; k++)
		campo[k] = campo[i + k];

	campo[k] = '\0';
}

bool extraiaData(Data* dataExtrair, char campo [STR_CAMPO])
{
	if(!ehNumerico(campo))
		return false;

	dataExtrair->ano = 10 * (campo[2] - '0') + (campo[3] - '0');
	dataExtrair->mes = 10 * (campo[4] - '0') + (campo[5] - '0');
	dataExtrair->dia = 10 * (campo[6] - '0') + (campo[7] - '0');

	return true;
}

bool ehNumerico(char campo [STR_CAMPO])
{
	unsigned char d;

	for(d = 0; campo[d] != '\0'; d++)
		if(!('0' <= campo[d] && campo[d] <= '9'))
			return false;

	return true;
}

void imprimaReg00(Reg00 registro, FILE* saida)
{
	fprintf(saida, "______________________________________________________________________\n");
	fprintf(saida, "CABECALHO\n");
	fprintf(saida, "            codigo: %02hhu\n", registro.tipo);
	fprintf(saida, "   nome do arquivo: %s\n",     registro.nomeArquivo);
	fprintf(saida, " origem do arquivo: %s\n",     registro.origemArquivo);
	fprintf(saida, "   data de geracao: ");
	imprimaData(registro.dataGeracao, saida);
	fprintf(saida, "\n");
	fprintf(saida, "______________________________________________________________________\n");
}

void imprimaReg01(Reg01 registro, FILE* saida)
{
	fprintf(saida, "______________________________________________________________________\n");
	fprintf(saida, "COTACAO\n");
	fprintf(saida, "                          codigo: %02hhu\n", registro.tipo);
	fprintf(saida, "                  data do pregao: ");
	imprimaData(registro.dataPregao, saida);
	fprintf(saida, "\n");
	fprintf(saida, "                      codigo bdi: %s\n",     registro.codbdi);
	fprintf(saida, "   codigo de negociacao do papel: %s\n",     registro.codneg);
	fprintf(saida, "         codigo interno do papel: %s\n",     registro.codisi);
	fprintf(saida, "                 tipo de mercado: %02hhu\n", registro.tpmerc);
	fprintf(saida, "                empresa emissora: %s\n",     registro.nomres);
	fprintf(saida, "               fator de correcao: %4lu\n",   registro.fatcot);
	fprintf(saida, " numero de distribuicao do papel: %3hu\n",   registro.dismes);
	fprintf(saida, "          especificacao do papel: %s\n",     registro.especi);
	fprintf(saida, "             moeda de referencia: %s\n",     registro.modref);
	fprintf(saida, "               total de negocios: %lu\n",    registro.totneg);
	fprintf(saida, "                 total de papeis: %13llu\n", registro.quatot);
	fprintf(saida, "          volume total negociado: %13llu\n", registro.voltot);
	fprintf(saida, "               preco de abertura: %13llu\n", registro.preabe);
	fprintf(saida, "             preco de fechamento: %13llu\n", registro.preult);
	fprintf(saida, "                    preco maximo: %13llu\n", registro.premax);
	fprintf(saida, "                     preco medio: %13llu\n", registro.premed);
	fprintf(saida, "                    preco minimo: %13llu\n", registro.premin);
	fprintf(saida, "          melhor preco de compra: %13llu\n", registro.preofc);
	fprintf(saida, "           melhor preco de venda: %13llu\n", registro.preofv);
	fprintf(saida, "  preco em moeda de opcoes/termo: %13llu\n", registro.preexe);
	fprintf(saida, " preco em pontos de opcoes/termo: %13llu\n", registro.ptoexe);
	fprintf(saida, " indice de correcao opcoes/termo: %1hhu\n",  registro.indopc);
	fprintf(saida, "         vencimento opcoes/termo: ");
	imprimaData(registro.datven, saida);
	fprintf(saida, "\n");
	fprintf(saida, " prazo do mercado a termo (dias): %s\n",     registro.prazot);
	fprintf(saida, "______________________________________________________________________\n");
}

void imprimaReg99(Reg99 registro, FILE* saida)
{
	fprintf(saida, "______________________________________________________________________\n");
	fprintf(saida, "TRAILER\n");
	fprintf(saida, "             codigo: %02hhu\n", registro.tipo);
	fprintf(saida, "    nome do arquivo: %s\n",     registro.nomeArquivo);
	fprintf(saida, "  origem do arquivo: %s\n",     registro.origemArquivo);
	fprintf(saida, "    data de geracao: ");
	imprimaData(registro.dataGeracao, saida);
	fprintf(saida, "\n");
	fprintf(saida, " total de registros: %11llu\n", registro.totalRegistros);
	fprintf(saida, "______________________________________________________________________\n");
}

void imprimaData(Data d, FILE* saida)
{
	fprintf(saida, "%02hhu/%02hhu/%02hhu", d.dia, d.mes, d.ano);
}

void inserirReg99(Reg99 registro, char buffer [STR_REGISTRO])
{
	char reserva [STR_CAMPO] = "";

	inserirNumerico (registro.tipo,           buffer,   0,   1);
	inserirTexto    (registro.nomeArquivo,    buffer,   2,  14);
	inserirTexto    (registro.origemArquivo,  buffer,  15,  22);
	inserirData     (registro.dataGeracao,    buffer,  23,  30);
	inserirNumerico (registro.totalRegistros, buffer,  31,  41);
	inserirTexto    (reserva,                 buffer,  42, 244);
}

void inserirReg01(Reg01 registro, char buffer [STR_REGISTRO])
{
	inserirNumerico (registro.tipo,       buffer,   0,   1);
	inserirData     (registro.dataPregao, buffer,   2,   9);
	inserirTexto    (registro.codbdi,     buffer,  10,  11);
	inserirTexto    (registro.codneg,     buffer,  12,  23);
	inserirNumerico (registro.tpmerc,     buffer,  24,  26);
	inserirTexto    (registro.nomres,     buffer,  27,  38);
	inserirTexto    (registro.especi,     buffer,  39,  48);
	inserirTexto    (registro.prazot,     buffer,  49,  51);
	inserirTexto    (registro.modref,     buffer,  52,  55);
	inserirNumerico (registro.preabe,     buffer,  56,  68);
	inserirNumerico (registro.premax,     buffer,  69,  81);
	inserirNumerico (registro.premin,     buffer,  82,  94);
	inserirNumerico (registro.premed,     buffer,  95, 107);
	inserirNumerico (registro.preult,     buffer, 108, 120);
	inserirNumerico (registro.preofc,     buffer, 121, 133);
	inserirNumerico (registro.preofv,     buffer, 134, 146);
	inserirNumerico (registro.totneg,     buffer, 147, 151);
	inserirNumerico (registro.quatot,     buffer, 152, 169);
	inserirNumerico (registro.voltot,     buffer, 170, 187);
	inserirNumerico (registro.preexe,     buffer, 188, 200);
	inserirNumerico (registro.indopc,     buffer, 201, 201);
	inserirData     (registro.datven,     buffer, 202, 209);
	inserirNumerico (registro.fatcot,     buffer, 210, 216);
	inserirNumerico (registro.ptoexe,     buffer, 217, 229);
	inserirTexto    (registro.codisi,     buffer, 230, 241);
	inserirNumerico (registro.dismes,     buffer, 242, 244);
}

void inserirReg00(Reg00 registro, char buffer [STR_REGISTRO])
{
	char reserva [STR_CAMPO] = "";

	inserirNumerico (registro.tipo,           buffer,   0,   1);
	inserirTexto    (registro.nomeArquivo,    buffer,   2,  14);
	inserirTexto    (registro.origemArquivo,  buffer,  15,  22);
	inserirData     (registro.dataGeracao,    buffer,  23,  30);
	inserirTexto    (reserva,                 buffer,  31, 244);
}

void inserirData(Data dataInserir, char buffer [STR_REGISTRO], unsigned char inicio, unsigned char fim)
{
	unsigned long dataFormatada = 0;

	dataFormatada += (dataInserir.ano + (dataInserir.ano < 50 ? 2000 : 1900)) * 10000;
	dataFormatada += dataInserir.mes * 100;
	dataFormatada += dataInserir.dia * 1;

	inserirNumerico(dataFormatada, buffer, inicio, fim);
}


void inserirNumerico (unsigned long long numeroInserir, char buffer [STR_REGISTRO], unsigned char inicio, unsigned char fim)
{
	unsigned char d;

	for(d = fim; d >= inicio && (unsigned char) (d + 1) > d; d--, numeroInserir /= 10)

		buffer[d] = (numeroInserir % 10) + '0';
}

void inserirTexto(char campo [], char buffer [STR_REGISTRO], unsigned char inicio, unsigned char fim)
{
	unsigned char c1, c2;

	for(c1 = inicio, c2 = 0; (c1 <= fim && (unsigned char) (c1 - 1) < c1) && campo[c2] != '\0'; c1++, c2++)

		buffer[c1] = campo[c2];

	while(c1 <= fim)
		buffer[c1++] = ' ';
}

char comparaData(Data d1, Data d2)
{
	if(d1.ano > d2.ano) return +1;
	if(d1.ano < d2.ano) return -1;
	if(d1.mes > d2.mes) return +1;
	if(d1.mes < d2.mes) return -1;
	if(d1.dia > d2.dia) return +1;
	if(d1.dia < d2.dia) return -1;
	return 0;
}

