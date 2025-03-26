#include <iostream>
#include <cstdlib>
#include "../include/Servidor.hpp"

#define TAMANHO_MAX_DE_IP  16
#define TAMANHO_MAX_DE_MSG 1024

int main()
{
	char     ip [TAMANHO_MAX_DE_IP];
	unsigned porta;

	std::cout << "Digite o endereco IPv4 do servidor: ";
	std::cin >> ip;

	std::cout << "Digite a porta do servidor: ";
	std::cin >> porta;
	std::cin.ignore();

	Servidor s (ip, porta);

	try
	{
		s.configura_servidor();
		std::cout << "Endereco e porta do servidor: " << s.ip() << ":" << s.porta() << std::endl;
		s.aceita_requisicao();
		std::cout << "Comunicacao estabelecida." << std::endl;

		const int   tamanho_maximo_da_msg = 1024;
		char        buffer_da_comunicacao [tamanho_maximo_da_msg];

		s.receba_msg(buffer_da_comunicacao, sizeof(buffer_da_comunicacao));
		std::cout << "Cliente: " << buffer_da_comunicacao << std::endl;

		std::cout << "Servidor: ";
		std::cin.getline(buffer_da_comunicacao, tamanho_maximo_da_msg);
		s.envia_msg(buffer_da_comunicacao, sizeof(buffer_da_comunicacao));

		s.receba_msg(buffer_da_comunicacao, sizeof(buffer_da_comunicacao));
		std::cout << "Cliente: " << buffer_da_comunicacao << std::endl;

		std::cout << "Servidor: ";
		std::cin.getline(buffer_da_comunicacao, tamanho_maximo_da_msg);
		s.envia_msg(buffer_da_comunicacao, sizeof(buffer_da_comunicacao));

		s.termina_conexao();
		std::cout << "Conexao terminada." << std::endl;
	}
	catch(std::exception & e)
	{
		std::cout << "ERRO: " << e.what() << std::endl;
	}

	exit(EXIT_SUCCESS);
}
