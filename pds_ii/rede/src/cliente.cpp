#include <iostream>
#include <cstdlib>
#include "../include/Cliente.hpp"

int main()
{
	const char     tamanho_maximo_de_ip    = 16;
	char           ip_do_servidor [tamanho_maximo_de_ip];
	unsigned short porta_do_servidor;

	std::cout << "Digite o endereco IPv4 do servidor: ";
	std::cin >> ip_do_servidor;

	std::cout << "Digite a porta do servidor: ";
	std::cin >> porta_do_servidor;
	std::cin.ignore();

	Cliente   c (ip_do_servidor, porta_do_servidor);
	const int tamanho_maximo_de_msg = 1024;
	char      buffer_da_comunicacao [tamanho_maximo_de_msg];

	c.configura();
	c.conecta();

	std::cout << "Cliente: ";
	std::cin.getline(buffer_da_comunicacao, tamanho_maximo_de_msg);
	c.envia_msg(buffer_da_comunicacao, sizeof(buffer_da_comunicacao));

	c.receba_msg(buffer_da_comunicacao, sizeof(buffer_da_comunicacao));
	std::cout << "Servidor: " << buffer_da_comunicacao << std::endl;

	std::cout << "Cliente: ";
	std::cin.getline(buffer_da_comunicacao, tamanho_maximo_de_msg);
	c.envia_msg(buffer_da_comunicacao, sizeof(buffer_da_comunicacao));

	c.receba_msg(buffer_da_comunicacao, sizeof(buffer_da_comunicacao));
	std::cout << "Servidor: " << buffer_da_comunicacao << std::endl;

	exit(EXIT_SUCCESS);
}
