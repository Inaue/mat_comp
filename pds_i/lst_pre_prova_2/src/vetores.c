#include <stdio.h>
#include "../lib/vetores.h"

void le_vetor_i(int vetor_ler[], int tamanho)
{
	int i = 0;
	
	for(i = 0; i < tamanho; i++)
	{
		scanf("%d", &vetor_ler[i]);
	}
}

void le_vetor_lf(double vetor_ler[], int tamanho)
{
	int i = 0;
	
	for(i = 0; i < tamanho; i++)
	{
		scanf("%lf", &vetor_ler[i]);
	}
}

void printa_vetor_i(const int vetor_printar[], int tamanho)
{
	int i = 0;
	
	for(i = 0; i < tamanho; i++)
	{
		printf("%d ", vetor_printar[i]);
	}
}

void printa_vetor_llu(const unsigned long long vetor_printar[], int tamanho, const char * formatacao)
{
	int i = 0;
	
	for(i = 0; i < tamanho; i++)
	{
		printf(formatacao, vetor_printar[i]);
	}
}

void printa_vetor_lf(const double vetor_printar[], int tamanho)
{
	int i = 0;
	
	for(i = 0; i < tamanho; i++)
	{
		printf("%g ", vetor_printar[i]);
	}
}

int obter_total_vetor_i(const int vetor_somar[], int tamanho)
{
	int i = 0, soma = 0;

	for (i = 0; i < tamanho; i++)
	{
		soma += vetor_somar[i];
	}
	
	return soma;
}

int procura_no_vetor_lf(const double vetor_procurar[], int tamanho, double numero_procurar)
{
	int indice = 0;

	for(indice = 0; indice < tamanho; indice++)
	{
		if(vetor_procurar[indice] == numero_procurar)
		{
			return indice;
		}
	}

	return ELEMENTO_NAO_ENCONTRADO;
}

void inverta_vetor_i(int vetor_inverter[], int tamanho)
{
	int indice_1 = 0, indice_2 = 0;

	for(indice_1 = 0, indice_2 = tamanho - 1; indice_1 < indice_2; indice_1++, indice_2--)
	{
		vetor_inverter[indice_1] = vetor_inverter[indice_1] ^ vetor_inverter[indice_2];
		vetor_inverter[indice_2] = vetor_inverter[indice_1] ^ vetor_inverter[indice_2];
		vetor_inverter[indice_1] = vetor_inverter[indice_1] ^ vetor_inverter[indice_2];
	}
}

void inverta_vetor_lf(double vetor_inverter[], int tamanho)
{
	int indice = 0, limitador = tamanho / 2;

	for(indice = 0; indice < limitador; indice++)
	{
		vetor_inverter[indice]               += vetor_inverter[tamanho - indice - 1];
		vetor_inverter[tamanho - indice - 1]  = vetor_inverter[indice] - vetor_inverter[tamanho - indice - 1];
		vetor_inverter[indice]               -= vetor_inverter[tamanho - indice - 1];
	}
}

int procura_no_vetor_i(const int vetor_procurar[], int tamanho, int numero_procurar)
{
	int indice = 0;

	for(indice = 0; indice < tamanho; indice++)
	{
		if(vetor_procurar[indice] == numero_procurar)
		{
			return indice;
		}
	}

	return ELEMENTO_NAO_ENCONTRADO;
}

double deslocar_para_a_direita_vetor_lf(double vetor_deslocar[], int tamanho)
{
	int indice = 0;
	double armazenamento_temporario_1 = 0.0, armazenamento_temporario_2 = 0.0, elemento_retirado = 0.0;

	for(indice = 0; indice < tamanho; indice++)
	{
		armazenamento_temporario_1  = vetor_deslocar[indice];
		vetor_deslocar[indice]      = armazenamento_temporario_2;
		armazenamento_temporario_2 += armazenamento_temporario_1;
		armazenamento_temporario_1  = armazenamento_temporario_2 - armazenamento_temporario_1;
		armazenamento_temporario_2 -= armazenamento_temporario_1;
	}

	elemento_retirado = armazenamento_temporario_2;

	return elemento_retirado;
}

int deslocar_para_a_direita_vetor_i(int vetor_deslocar[], int tamanho)
{
	int indice = 0;
	int armazenamento_temporario_1 = 0, armazenamento_temporario_2 = 0, elemento_retirado = 0;

	for(indice = 0; indice < tamanho; indice++)
	{
		armazenamento_temporario_1  = vetor_deslocar[indice];
		vetor_deslocar[indice]      = armazenamento_temporario_2;
		armazenamento_temporario_2 += armazenamento_temporario_1;
		armazenamento_temporario_1  = armazenamento_temporario_2 - armazenamento_temporario_1;
		armazenamento_temporario_2 -= armazenamento_temporario_1;
	}

	elemento_retirado = armazenamento_temporario_2;

	return elemento_retirado;
}

int deslocar_para_a_esquerda_vetor_i(int vetor_deslocar[], int tamanho)
{
	int indice = 0;
	int armazenamento_temporario_1 = 0, armazenamento_temporario_2 = 0, elemento_retirado = 0;

	for(indice = tamanho - 1; indice >= 0; indice--)
	{
		armazenamento_temporario_1  = vetor_deslocar[indice];
		vetor_deslocar[indice]      = armazenamento_temporario_2;
		armazenamento_temporario_2 += armazenamento_temporario_1;
		armazenamento_temporario_1  = armazenamento_temporario_2 - armazenamento_temporario_1;
		armazenamento_temporario_2 -= armazenamento_temporario_1;
	}

	elemento_retirado = armazenamento_temporario_2;

	return elemento_retirado;
}

double deslocar_para_a_esquerda_vetor_lf(double vetor_deslocar[], int tamanho)
{
	int indice = 0;
	double armazenamento_temporario_1 = 0.0, armazenamento_temporario_2 = 0.0, elemento_retirado = 0.0;

	for(indice = tamanho - 1; indice >= 0; indice--)
	{
		armazenamento_temporario_1  = vetor_deslocar[indice];
		vetor_deslocar[indice]      = armazenamento_temporario_2;
		armazenamento_temporario_2 += armazenamento_temporario_1;
		armazenamento_temporario_1  = armazenamento_temporario_2 - armazenamento_temporario_1;
		armazenamento_temporario_2 -= armazenamento_temporario_1;
	}

	elemento_retirado = armazenamento_temporario_2;

	return elemento_retirado;
}

double retirar_elemento_vetor_lf(double vetor_retirar[], int tamanho, int posicao)
{
	int total_de_elementos_a_deslocar = 0;
	double elemento_retirado = 0.0;

	total_de_elementos_a_deslocar = tamanho - posicao;
	elemento_retirado = deslocar_para_a_esquerda_vetor_lf(&vetor_retirar[posicao], total_de_elementos_a_deslocar);

	return elemento_retirado;
}

void inserir_elemento_vetor_lf(double vetor_inserir[], int tamanho, int posicao, int elemento_inserir)
{
	int total_de_elementos_a_deslocar = 0, ultimo_elemento = 0;
	
	total_de_elementos_a_deslocar = tamanho - posicao;
	ultimo_elemento = deslocar_para_a_direita_vetor_lf(&vetor_inserir[posicao], total_de_elementos_a_deslocar);
	vetor_inserir[tamanho] = ultimo_elemento;
    vetor_inserir[posicao] = elemento_inserir;
}

void inverta_vetor_hh(char vetor_inverter[], int tamanho)
{
	int indice_1 = 0, indice_2 = 0;

	for(indice_1 = 0, indice_2 = tamanho - 1; indice_1 < indice_2; indice_1++, indice_2--)
	{
		vetor_inverter[indice_1] = vetor_inverter[indice_1] ^ vetor_inverter[indice_2];
		vetor_inverter[indice_2] = vetor_inverter[indice_1] ^ vetor_inverter[indice_2];
		vetor_inverter[indice_1] = vetor_inverter[indice_1] ^ vetor_inverter[indice_2];
	}
}
