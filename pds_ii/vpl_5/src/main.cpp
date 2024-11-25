#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <cctype>
#include <algorithm>
#include <vector>
#include <map>

#define SUCESSO     0
#define INVAL_ARGS 10
#define N_OBTER_PC 20
#define N_REALI_CH 30
#define FIM_DE_STR '\0'

typedef std::vector<std::string> vetor_str;
typedef std::map<std::string, int> histograma_str;

int main (int argc, char * argv[]);

void registrar_palavra (vetor_str & encontradas, histograma_str & frequencia_das_palavras, std::string palavra);

void padronizaLinha (std::string & linha);

int main (int argc, char * argv[])
{
	std::ifstream  entrada;
	std::string    nome_do_arquivo, linha;
	vetor_str      encontradas;
	histograma_str frequencia_das_palavras;

	std::cin >> nome_do_arquivo;

	entrada.open(nome_do_arquivo);

	while(std::getline(entrada, linha))
	{
		std::string       palavra;
		std::stringstream buffer;

		padronizaLinha(linha);
		buffer << linha;

		while(buffer >> palavra)
			registrar_palavra(encontradas, frequencia_das_palavras, palavra);
	}

	entrada.close();

	std::sort(encontradas.begin(), encontradas.end());

	for(auto palavra : encontradas)
		std::cout << palavra << " " << frequencia_das_palavras[palavra] << std::endl;
	
	return SUCESSO;
}

void registrar_palavra(vetor_str & encontradas, histograma_str & frequencia_das_palavras, std::string palavra)
{
	auto resultado_da_busca = std::find(encontradas.begin(), encontradas.end(), palavra);

	if(resultado_da_busca == encontradas.end())
	{
		encontradas.push_back(palavra);
		frequencia_das_palavras[palavra] = 1;
	}
	else
	{
		frequencia_das_palavras[palavra]++;
	}
}

void padronizaLinha(std::string & linha)
{
	int tamanho = linha.length();

	for(int i = 0; i < tamanho; i++)
	{
		if(isalnum(linha[i]))
			linha[i] = tolower(linha[i]);
		else
			linha[i] = ' ';
	}
}
