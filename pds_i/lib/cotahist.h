/**
 * @file   cotahist.h
 * @brief  Cabecalho da biblioteca COTAHIST
 * @author Inaue Ferreira da Silva
 * @date   07-09-2024
 */

#ifndef COTAHIST_H
#define COTAHIST_H

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define STR_REGISTRO 247
#define STR_CAMPO    20
#define STR_DATA     9
#define STR_CODBDI   3
#define STR_CODNEG   13
#define STR_NOMRES   13
#define STR_ESPECI   11
#define STR_PRAZOT   4
#define STR_MODREF   5
#define STR_CODISI   13
#define STR_NOME_ARQ 14
#define STR_ORIGEM   9

typedef struct
{
	unsigned char dia;
	unsigned char mes;
	unsigned char ano;
}
Data;

typedef struct
{
	unsigned char tipo;
	char          nomeArquivo   [STR_NOME_ARQ];
	char          origemArquivo [STR_ORIGEM];
	Data          dataGeracao;
}
Reg00;

typedef struct
{
	unsigned char      tipo;
	unsigned char      tpmerc;
	unsigned char      indopc;
	unsigned short     dismes;
	unsigned long      totneg;
	unsigned long      fatcot;
	unsigned long long quatot;
	unsigned long long voltot;
	unsigned long long ptoexe;
	unsigned long long preabe;
	unsigned long long preult;
	unsigned long long premax;
	unsigned long long premed;
	unsigned long long premin;
	unsigned long long preofc;
	unsigned long long preofv;
	unsigned long long preexe;
	Data               dataPregao;
	Data               datven;
	char               codbdi [STR_CODBDI];
	char               codneg [STR_CODNEG];
	char               nomres [STR_NOMRES];
	char               especi [STR_ESPECI];
	char               prazot [STR_PRAZOT];
	char               modref [STR_MODREF];
	char               codisi [STR_CODISI];
}
Reg01;

typedef struct
{
	unsigned char      tipo;
	char               nomeArquivo   [STR_NOME_ARQ];
	char               origemArquivo [STR_ORIGEM];
	Data               dataGeracao;
	unsigned long long totalRegistros;
}
Reg99;

unsigned char identificaTipoReg (char buffer [STR_REGISTRO]);

void removaReservas (char campo [STR_CAMPO]);

char comparaData (Data d1, Data d2);

bool extraiaReg00 (Reg00* registro, char buffer [STR_REGISTRO]);
bool extraiaReg01 (Reg01* registro, char buffer [STR_REGISTRO]);
bool extraiaReg99 (Reg99* registro, char buffer [STR_REGISTRO]);
bool extraiaCampo (char campo [STR_CAMPO], char buffer [STR_REGISTRO], unsigned char inicio, unsigned char fim);
bool extraiaData  (Data* dataExtrair, char campo [STR_CAMPO]);
bool ehNumerico   (char campo [STR_CAMPO]);

void imprimaReg00 (Reg00 registro, FILE* saida);
void imprimaReg01 (Reg01 registro, FILE* saida);
void imprimaReg99 (Reg99 registro, FILE* saida);
void imprimaData  (Data d, FILE* saida);

void inserirReg00    (Reg00 registro, char buffer [STR_REGISTRO]);
void inserirReg01    (Reg01 registro, char buffer [STR_REGISTRO]);
void inserirReg99    (Reg99 registro, char buffer [STR_REGISTRO]);
void inserirData     (Data dataInserir, char buffer [STR_REGISTRO], unsigned char inicio, unsigned char fim);
void inserirNumerico (unsigned long long numeroInserir, char buffer [STR_REGISTRO], unsigned char inicio, unsigned char fim);
void inserirTexto    (char campo [], char buffer [STR_REGISTRO], unsigned char inicio, unsigned char fim);

#endif
