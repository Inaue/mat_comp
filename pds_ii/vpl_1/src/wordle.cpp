#include <iostream>
#include <fstream>
#include <string>
#include <cctype>

#define SUCESSO     0
#define INVAL_ARGS 10
#define N_OBTER_PC 20
#define N_REALI_CH 30

using namespace std;

int  main       (int argc, char * argv[]);
bool validaArgs (int argc, char * argv[]);

bool obterChave            (string nomeDoArquivoDeEntrada, string * chave);
bool abrirArquivoDeEntrada (ifstream * entrada, string nomeDoArquivoDeEntrada);
bool lerTotalDeChaves      (ifstream * entrada, int * totalDeChaves);
bool lerChaveEscolhida     (int * idxPalavraEscolhida);
bool procurarChave         (ifstream * entrada, string * chave, int idxPalavraEscolhida, int totalDeChaves);

bool realizarChute     (string chave, bool * resultado);
bool lerChute          (string * chute);
void inicializarDicas  (string * dicas);
void processarChute    (string chute, string chave, string * dicas, string * listaDeErros);
void verPresenca       (string chute, string chave, string * dicas);
void verPosicao        (string chute, string chave, string * dicas);
void criarListaDeErros (string chute, string dicas, string * listaDeErros);

void realizarFimDeJogo(bool resultado, string chave);

int main (int argc, char * argv[])
{
	string chave;
	bool   resultado;

	if(validaArgs(argc, argv))
	{
		cerr << "ERRO: argumentos invalidos!" << endl;

		return INVAL_ARGS;
	}

	if(obterChave(argv[1], &chave))
	{
		cerr << "ERRO: falha na obtencao da palavra chave!" << endl;

		return N_OBTER_PC;
	}

	if(realizarChute(chave, &resultado))
	{
		cerr << "ERRO: falha na realizacao do chute!" << endl;

		return N_REALI_CH;
	}

	realizarFimDeJogo(resultado, chave);

	return SUCESSO;
}

bool validaArgs(int argc, char * argv[])
{
	if(argc != 2)
		return true;

	return false;
}

bool obterChave(string nomeDoArquivoDeEntrada, string * chave)
{
	ifstream entrada;
	int      totalDeChaves, idxPalavraEscolhida;

	if(abrirArquivoDeEntrada(&entrada, nomeDoArquivoDeEntrada))
	{
		cerr << "ERRO: falha na abertura do arquivo com as palavras!" << endl;

		return true;
	}

	if(lerTotalDeChaves(&entrada, &totalDeChaves))
	{
		cerr << "ERRO: falha na leitura do total de palavras no arquivo!" << endl;

		return true;
	}

	if(lerChaveEscolhida(&idxPalavraEscolhida))
	{
		cerr << "ERRO: falha na leitura do indice da chave escolhida!" << endl;

		return true;
	}

	if(procurarChave(&entrada, chave, totalDeChaves, idxPalavraEscolhida))
	{
		cerr << "ERRO: falha na leitura da chave escolhida!" << endl;

		return true;
	}

	return false;
}

bool abrirArquivoDeEntrada(ifstream * entrada, string nomeDoArquivoDeEntrada)
{
	entrada->open(nomeDoArquivoDeEntrada);

	if(!entrada->is_open())

		return true;

	return false;
}

bool lerTotalDeChaves(ifstream * entrada, int * totalDeChaves)
{
	int total;

	*entrada >> total;

	if(entrada->bad() || entrada->fail())

		return true;

	*totalDeChaves = total;

	return false;
}

bool lerChaveEscolhida (int * idxPalavraEscolhida)
{
	int idxPalavra;

	cin >> idxPalavra;

	if(cin.bad() || cin.fail())

		return true;

	*idxPalavraEscolhida = idxPalavra;

	return false;
}

bool procurarChave(ifstream * entrada, string * chave, int totalDeChaves, int idxPalavraEscolhida)
{
	int    idx;
	string palavraLida;

	if(idxPalavraEscolhida > totalDeChaves)

		return true;

	for(idx = 0; idx < idxPalavraEscolhida && idx < totalDeChaves; idx++)
	{
		*entrada >> palavraLida;

		if(entrada->bad() || entrada->fail())

			return true;
	}

	*chave = palavraLida;

	return false;
}

bool realizarChute (string chave, bool * resultado)
{
	int    tentativasFeitas;
	string chute, listaDeErros = "", dicas = chave;

	for(tentativasFeitas = 0; tentativasFeitas < 5; tentativasFeitas++)
	{
		inicializarDicas(&dicas);

		if(lerChute(&chute))
		{
			cerr << "ERRO: falha na leitura do chute!" << endl;

			return true;
		}

		processarChute(chute, chave, &dicas, &listaDeErros);

		cout << dicas << " (" << listaDeErros << ")" << endl;

		if(dicas == chave)
		{
			*resultado = true;

			return false;
		}
	}

	return false;
}

bool lerChute(string * chute)
{
	string palavraLida;

	cin >> palavraLida;

	if(cin.bad() || cin.fail())

		return true;

	*chute = palavraLida;

	return false;
}

void processarChute(string chute, string chave, string * dicas, string * listaDeErros)
{
	verPosicao(chute, chave, dicas);
	verPresenca(chute, chave, dicas);
	criarListaDeErros(chute, *dicas, listaDeErros);
}

void verPosicao(string chute, string chave, string * dicas)
{
	int idx, tamanho = chave.size();

	for(idx = 0; idx < tamanho; idx++)
		if(chute[idx] == chave[idx])
			(*dicas)[idx] = chave[idx];
}

void verPresenca(string chute, string chave, string * dicas)
{
	int idx, tamanho = chave.size();

	for(idx = 0; idx < tamanho; idx++)
		if(!isalpha((*dicas)[idx]) && chave.find(chute[idx]) != string::npos)
			(*dicas)[idx] = tolower(chute[idx]);
}

void criarListaDeErros(string chute, string dicas, string * listaDeErros)
{
	int idx, tamanho = chute.size();

	for(idx = 0; idx < tamanho; idx++)
		if(!isalpha(dicas[idx]) && (*listaDeErros).find(chute[idx]) == string::npos)
			*listaDeErros += chute[idx];
}

void inicializarDicas(string * dicas)
{
	int idx, tamanho = dicas->size();

	for(idx = 0; idx < tamanho; idx++)

		(*dicas)[idx] = '*';
}

void realizarFimDeJogo(bool resultado, string chave)
{
	if(resultado)
		cout << "GANHOU!" << endl;
	else
		cout << "PERDEU! " << chave << endl;
}
