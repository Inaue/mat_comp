#include <iostream>
#include <string>
#include "../include/Empresa.hpp"
#include "../include/Onibus.hpp"

using namespace std;

Empresa::Empresa()
{
	total_de_onibus = 0;

	for(int onibus = 0; onibus < MAX_BUS; onibus++)

		onibus_cadastrados[onibus] = nullptr;
}

Onibus * Empresa::adicionar_onibus(const string placa, const int lotacao_max)
{
	for(int onibus = 0; onibus < total_de_onibus; onibus++)
		if(onibus_cadastrados[onibus]->placa == placa)
			return nullptr;

	return onibus_cadastrados[total_de_onibus++] = new Onibus(placa, lotacao_max);
}

Onibus * Empresa::busca_onibus(const string placa)
{
	for(int onibus = 0; onibus < total_de_onibus; onibus++)
		if(onibus_cadastrados[onibus]->placa == placa)
			return onibus_cadastrados[onibus];

	return nullptr;
}

void Empresa::imprimir_estado()
{
	for(int onibus = 0; onibus < total_de_onibus; onibus++)

		onibus_cadastrados[onibus]->imprimir_estado();
}
