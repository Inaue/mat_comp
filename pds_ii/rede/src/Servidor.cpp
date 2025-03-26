#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include "../include/Servidor.hpp"

Servidor::Servidor(const char * ip, unsigned int porta)
{
	ip_                 = ip;
	porta_              = porta;
	tamanho_do_endereco = sizeof(endereco);
}

Servidor::~Servidor() { close(socket_do_servidor); }

void Servidor::configura_servidor()
{
	cria_socket();
	configura_socket();
	cria_endereco();
	liga_endereco_ao_socket();
	ouve_porta();
}

const char * Servidor::ip() { return ip_; }

unsigned int Servidor::porta() { return porta_; }

void Servidor::cria_socket()
{
	socket_do_servidor = socket(AF_INET, SOCK_STREAM, 0);

	if(socket_do_servidor == -1)
	{
		throw Excecao_Nao_Possivel_Conectar();
	}
}

void Servidor::configura_socket()
{
	int config = 1;
	int erro   = setsockopt(socket_do_servidor, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT, &config, sizeof(config));

	if(erro == -1)
	{
		throw Excecao_Nao_Possivel_Conectar();
	}
}

void Servidor::cria_endereco()
{
	endereco.sin_family = AF_INET;
	endereco.sin_port   = htons(porta_);

	int erro = inet_aton(ip_, &endereco.sin_addr);

	if(erro == -1)
	{
		throw Excecao_IP_Invalido();
	}
}

void Servidor::liga_endereco_ao_socket()
{
	int erro = bind(socket_do_servidor, (sockaddr *) &endereco, tamanho_do_endereco);
	
	if(erro == -1)
	{
		throw Excecao_Nao_Possivel_Conectar();
	}
}

void Servidor::ouve_porta()
{
	int erro = listen(socket_do_servidor, 1);

	if(erro == -1)
	{
		throw Excecao_Nao_Possivel_Conectar();
	}
}

void Servidor::aceita_requisicao()
{
	socket_do_cliente = accept(socket_do_servidor, (sockaddr *) &endereco, &tamanho_do_endereco);

	if(socket_do_cliente == -1)
	{
		throw Excecao_Nao_Possivel_Conectar();
	}
}

void Servidor::receba_msg(void * msg, size_t tamanho)
{
	int erro = recv(socket_do_cliente, msg, tamanho, 0);

	if(erro == -1)
	{
		throw Excecao_Falha_na_Comunicacao();
	}
}

void Servidor::envia_msg(const void * msg, size_t tamanho)
{
	int erro = send(socket_do_cliente, msg, tamanho, 0);

	if(erro == -1)
	{
		throw Excecao_Falha_na_Comunicacao();
	}
}

void Servidor::termina_conexao() { close(socket_do_cliente); }

