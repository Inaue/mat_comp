#include <stdio.h>
#include "matrizes.h"

#define SUCESSO 0
#define SOMAR   1
#define MULTI_E 2
#define MULTI_M 3
#define SAIR    0

void print_linha();
void print_m(Matriz* m);
void scan_m(Matriz* m);
int tratar_cria_matriz(int erro);
int tratar_matriz_x_escalar(int erro);
int tratar_matriz_x_matriz(int erro);
void app_somar();
void app_multi_e();
void app_multi_m();

int main(int argc, char** argv)
{
	int opcao;

	do
	{
		print_linha();
		printf("ESCOLHA UMA OPCAO:\n");
		printf("%2d SOMAR MATRIZES\n",                 SOMAR);
		printf("%2d MULTIPLICAR MATRIZ POR ESCALAR\n", MULTI_E);
		printf("%2d MULTIPLICAR DUAS MATRIZES\n",      MULTI_M);
		printf("%2d SAIR\n",                           SAIR);
		print_linha();
		scanf("%d", &opcao);

		opcao == SOMAR   ? app_somar() :
		opcao == MULTI_E ? app_multi_e() :
		opcao == MULTI_M ? app_multi_m() :
		opcao == SAIR    ? : printf("ERRO: OPCAO INVALIDA!\n");
	}
	while(opcao != SAIR);

	return SUCESSO;
}

void print_linha() { printf("----------------------------------------------------------\n"); }

void print_m(Matriz* m)
{
	int i, j;

	for(i = 1; i <= m->linhas; i++)
	{
		putc('[', stdout);

		for(j = 1; j <= m->colunas; j++)
			printf(" %7.3f ", m->valores[i-1][j-1]);

		putc(']', stdout);
		putc('\n', stdout);
	}
}

void scan_m(Matriz *m)
{
	int i, j;
	
	for(i = 1; i <= m->linhas; i++)
	{
		for(j = 1; j <= m->colunas; j++)
			
			scanf("%f", &m->valores[i-1][j-1]);
	}
}

int tratar_cria_matriz(int erro)
{
	switch(erro)
	{
		case ERRO_MEMORIA:

			printf("ERRO: NAO FOI POSSIVEL CRIAR A MATRIZ!\n");
			return ERRO_MEMORIA;

		case ERRO_L_INVAL:

			printf("ERRO: VALOR DE LINHAS INVALIDO!\n");
			return ERRO_L_INVAL;

		case ERRO_C_INVAL:

			printf("ERRO: VALOR DE COLUNAS INVALIDO!\n");
			return ERRO_C_INVAL;
	}

	return EXEC_SUCCESS;
}

int tratar_soma_matrizes(int erro)
{
	switch(erro)
	{
		case ERRO_L_M1_M2:

			printf("ERRO: QUANTIDADES DE LINHAS DAS MATRIZES 1 E 2 DIFERENTES!\n");
			return ERRO_L_M1_M2;

		case ERRO_L_M1_MR:

			printf("ERRO: QUANTIDADES DE LINHAS DAS MATRIZES 1 E RESULTANTE DIFERENTES!\n");
			return ERRO_L_M1_MR;
		case ERRO_C_M1_M2:

			printf("ERRO: QUANTIDADES DE COLUNAS DAS MATRIZES 1 E 2 DIFERENTES!\n");
			return ERRO_C_M1_M2;

		case ERRO_C_M1_MR:

			printf("ERRO: QUANTIDADES DE COLUNAS DAS MATRIZES 1 E RESULTANTE DIFERENTES!\n");
			return ERRO_C_M1_MR;
	}

	return EXEC_SUCCESS;
}

int tratar_matriz_x_escalar(int erro)
{
	switch(erro)
	{
		case ERRO_L_M1_MR:

			printf("ERRO: QUANTIDADES DE LINHAS DAS MATRIZES 1 E 2 DIFERENTES!\n");
			return ERRO_L_M1_M2;

		case ERRO_C_M1_MR:

			printf("ERRO: QUANTIDADES DE COLUNAS DAS MATRIZES 1 E RESULTANTE DIFERENTES!\n");
			return ERRO_C_M1_MR;
	}

	return EXEC_SUCCESS;
}

int tratar_matriz_x_matriz(int erro)
{
	switch(erro)
	{
		case ERRO_NOT_MUL:

			printf("ERRO: MATRIZES 1 E 2 NAO PODEM SER MULTIPLICADAS!\n");
			return ERRO_NOT_MUL;

		case ERRO_L_M1_MR:

			printf("ERRO: QUANTIDADES DE LINHAS DAS MATRIZES 1 E RESULTANTE DIFERENTES!\n");
			return ERRO_L_M1_MR;

		case ERRO_C_M2_MR:

			printf("ERRO: QUANTIDADES DE COLUNAS DAS MATRIZES 2 E RESULTANTE DIFERENTES!\n");
			return ERRO_C_M2_MR;
	}

	return EXEC_SUCCESS;
}

void app_somar()
{
	int linhas, colunas;
	Matriz *matriz_1, *matriz_2, *matriz_resultante;

	print_linha();
	printf("DIGITE A QUANTIDADE DE LINHAS DAS MATRIZES\n");
	scanf("%d", &linhas);
	printf("DIGITE A QUANTIDADE DE COLUNAS DAS MATRIZES\n");
	scanf("%d", &colunas);
	print_linha();
	
	if(tratar_cria_matriz(cria_matriz(&matriz_1, linhas, colunas)) != EXEC_SUCCESS)

		return;

	if(tratar_cria_matriz(cria_matriz(&matriz_2, linhas, colunas)) != EXEC_SUCCESS)
	{
		deleta_matriz(matriz_1);
		return;
	}

	if(tratar_cria_matriz(cria_matriz(&matriz_resultante, linhas, colunas)) != EXEC_SUCCESS)
	{
		deleta_matriz(matriz_1);
		deleta_matriz(matriz_2);
		return;
	}

	printf("DIGITE A PRIMEIRA MATRIZ:\n");
	scan_m(matriz_1);
	printf("DIGITE A SEGUNDA MATRIZ:\n");
	scan_m(matriz_2);
	
	if(tratar_soma_matrizes(soma_matrizes(matriz_1, matriz_2, matriz_resultante)) == EXEC_SUCCESS)
	{
		print_linha();
		printf("MATRIZ RESULTANTE:\n");
		print_m(matriz_resultante);
	}

	deleta_matriz(matriz_1);
	deleta_matriz(matriz_2);
	deleta_matriz(matriz_resultante);
}

void app_multi_e()
{
	int linhas, colunas;
	float escalar;
	Matriz *matriz, *matriz_resultante;

	print_linha();
	printf("DIGITE A QUANTIDADE DE LINHAS DAS MATRIZES\n");
	scanf("%d", &linhas);
	printf("DIGITE A QUANTIDADE DE COLUNAS DAS MATRIZES\n");
	scanf("%d", &colunas);
	print_linha();
	
	if(tratar_cria_matriz(cria_matriz(&matriz, linhas, colunas)) != EXEC_SUCCESS)

		return;

	if(tratar_cria_matriz(cria_matriz(&matriz_resultante, linhas, colunas)) != EXEC_SUCCESS)
	{
		deleta_matriz(matriz);
		return;
	}

	printf("DIGITE A MATRIZ:\n");
	scan_m(matriz);
	printf("DIGITE O ESCALAR:\n");
	scanf("%f", &escalar);
	
	if(matriz_x_escalar(matriz, escalar, matriz_resultante) == ERRO_ES_NULL)
		
		printf("ERRO: ESCALAR NULO!\n");
	else
	{
		print_linha();
		printf("MATRIZ RESULTANTE:\n");
		print_m(matriz_resultante);
	}

	deleta_matriz(matriz);
	deleta_matriz(matriz_resultante);
}

void app_multi_m()
{
	int linhas_1, linhas_2, colunas_1, colunas_2;
	Matriz *matriz_1, *matriz_2, *matriz_resultante;

	print_linha();
	printf("DIGITE A QUANTIDADE DE LINHAS DA PRIMEIRA MATRIZ\n");
	scanf("%d", &linhas_1);
	printf("DIGITE A QUANTIDADE DE COLUNAS DA PRIMEIRA MATRIZ\n");
	scanf("%d", &colunas_1);
	
	if(tratar_cria_matriz(cria_matriz(&matriz_1, linhas_1, colunas_1)) != EXEC_SUCCESS)

		return;

	printf("DIGITE A QUANTIDADE DE LINHAS DA SEGUNDA MATRIZ\n");
	scanf("%d", &linhas_2);
	printf("DIGITE A QUANTIDADE DE COLUNAS DA SEGUNDA MATRIZ\n");
	scanf("%d", &colunas_2);
	print_linha();

	if(tratar_cria_matriz(cria_matriz(&matriz_2, linhas_2, colunas_2)) != EXEC_SUCCESS)
	{
		deleta_matriz(matriz_1);
		return;
	}

	if(tratar_cria_matriz(cria_matriz(&matriz_resultante, linhas_1, colunas_2)) != EXEC_SUCCESS)
	{
		deleta_matriz(matriz_1);
		deleta_matriz(matriz_2);
		return;
	}

	printf("DIGITE A PRIMEIRA MATRIZ:\n");
	scan_m(matriz_1);
	printf("DIGITE A SEGUNDA MATRIZ:\n");
	scan_m(matriz_2);
	
	if(tratar_matriz_x_matriz(matriz_x_matriz(matriz_1, matriz_2, matriz_resultante)) == EXEC_SUCCESS)
	{
		print_linha();
		printf("MATRIZ RESULTANTE:\n");
		print_m(matriz_resultante);
	}

	deleta_matriz(matriz_1);
	deleta_matriz(matriz_2);
	deleta_matriz(matriz_resultante);
}
