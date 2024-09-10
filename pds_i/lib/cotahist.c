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

	strcpy(registro->nomeArquivo, campo);

	if(!extraiaCampo(campo, buffer, 15, 22))
		return false;

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

	strcpy(registro->codbdi, campo);

	if(!extraiaCampo(campo, buffer, 12, 23))
		return false;

	strcpy(registro->codneg, campo);

	if(!extraiaCampo(campo, buffer, 24, 26) || !ehNumerico(campo))
		return false;

	registro->tpmerc = strtoul(campo, NULL, 10);

	if(!extraiaCampo(campo, buffer, 27, 38))
		return false;

	strcpy(registro->nomres, campo);

	if(!extraiaCampo(campo, buffer, 39, 48))
		return false;

	strcpy(registro->especi, campo);

	if(!extraiaCampo(campo, buffer, 49, 51))
		return false;

	strcpy(registro->prazot, campo);

	if(!extraiaCampo(campo, buffer, 52, 55))
		return false;

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

	strcpy(registro->nomeArquivo, campo);

	if(!extraiaCampo(campo, buffer, 15, 22))
		return false;

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

