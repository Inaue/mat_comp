#include <iostream>
#include <string>
#include "../include/Onibus.hpp"

using namespace std;

Onibus::Onibus(const string placa, const int lotacao_max)
{
	this->placa          = placa;
	this->lotacao_max = lotacao_max;
	this->lotacao_atual  = 0;
}

Onibus * Onibus::subir_passageiros(const int num_passageiros)
{
	if(lotacao_atual + num_passageiros > lotacao_max)
		return nullptr;

	this->lotacao_atual += num_passageiros;

	return this;
}

Onibus * Onibus::descer_passageiros(const int num_passageiros)
{
	if(lotacao_atual < num_passageiros)
		return nullptr;

	this->lotacao_atual -= num_passageiros;

	return this;
}

Onibus * Onibus::transferir_passageiros(Onibus * onibus_a_transferir, const int num_passageiros)
{
	if(!this->descer_passageiros(num_passageiros))
		return nullptr;

	if(!onibus_a_transferir->subir_passageiros(num_passageiros))
	{
		this->subir_passageiros(num_passageiros);

		return nullptr;
	}

	return this;
}

void Onibus::imprimir_estado()
{
	cout << placa << " (" << lotacao_atual << "/" << lotacao_max << ")" << endl;
}
