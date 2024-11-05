#include <iostream>
#include "../include/Onibus.hpp"
#include "../include/Empresa.hpp"

#define SUCESSO     0
#define INVAL_ARGS 10
#define N_OBTER_PC 20
#define N_REALI_CH 30

using namespace std;

int main (int argc, char * argv[]);

void listar_info   (Empresa * e);
void cadastrar_bus (Empresa * e);
void subir_no_bus  (Empresa * e);
void descer_do_bus (Empresa * e);
void trocar_de_bus (Empresa * e);

int main (int argc, char * argv[])
{
	char      operacao;
	Empresa * viacao_anchieta = new Empresa();

	while(true)
	{
		cin >> operacao;

		if(operacao == 'F')
			break;

		switch(operacao)
		{
			case 'C':
				cadastrar_bus(viacao_anchieta);
				break;
			case 'D':
				descer_do_bus(viacao_anchieta);
				break;
			case 'I':
				listar_info(viacao_anchieta);
				break;
			case 'S':
				subir_no_bus(viacao_anchieta);
				break;
			case 'T':
				trocar_de_bus(viacao_anchieta);
				break;
		}
	}

	delete viacao_anchieta;

	return SUCESSO;
}

void listar_info(Empresa * e)
{
	e->imprimir_estado();
}

void cadastrar_bus(Empresa * e)
{
	string placa;
	int    capacidade_max;

	cin >> placa >> capacidade_max;

	if(e->adicionar_onibus(placa, capacidade_max))
	
		cout << "novo onibus cadastrado" << endl;
	else
		cout << "ERRO : onibus repetido" << endl;
}

void subir_no_bus(Empresa * e)
{
	string   placa;
	int      num_passageiros;
	Onibus * o;
	
	cin >> placa >> num_passageiros;

	if(!(o = e->busca_onibus(placa)))
	{
		cout << "ERRO : onibus inexistente" << endl;

		return;
	}

	if(o->subir_passageiros(num_passageiros))

		cout << "passageiros subiram com sucesso" << endl;

	else
		cout << "ERRO : onibus lotado" << endl;
}

void descer_do_bus(Empresa * e)
{
	string   placa;
	int      num_passageiros;
	Onibus * o;
	
	cin >> placa >> num_passageiros;

	if(!(o = e->busca_onibus(placa)))
	{
		cout << "ERRO : onibus inexistente" << endl;

		return;
	}

	if(o->descer_passageiros(num_passageiros))

		cout << "passageiros desceram com sucesso" << endl;

	else
		cout << "ERRO : faltam passageiros" << endl;
}

void trocar_de_bus(Empresa * e)
{
	string   placa_1, placa_2;
	int      num_passageiros;
	Onibus * origem, * destino;
	
	cin >> placa_1 >> placa_2 >> num_passageiros;

	if(!(origem = e->busca_onibus(placa_1)) || !(destino = e->busca_onibus(placa_2)))
	{
		cout << "ERRO : onibus inexistente" << endl;

		return;
	}

	if(origem->transferir_passageiros(destino, num_passageiros))

		cout << "transferencia de passageiros efetuada" << endl;

	else
		cout << "ERRO : transferencia cancelada" << endl;
}
