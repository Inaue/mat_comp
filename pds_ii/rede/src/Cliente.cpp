#include <unistd.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include "../include/Cliente.hpp"

Cliente::Cliente(const char * ip_do_servidor, unsigned int porta_do_servidor)
{
	ip_do_servidor_    = ip_do_servidor;
	porta_do_servidor_ = porta_do_servidor;
}

void Cliente::configura()
{
	cria_socket();
	cria_endereco_do_servidor();
}

void Cliente::cria_socket()
{
	socket_do_cliente = socket(AF_INET, SOCK_STREAM, 0);

	if(socket_do_cliente == -1)
	{
		throw Excecao_Nao_Possivel_Conectar();
	}
}

void Cliente::cria_endereco_do_servidor()
{
	endereco_do_servidor.sin_family = AF_INET;
	endereco_do_servidor.sin_port   = htons(porta_do_servidor_);

	if(inet_aton(ip_do_servidor_, &endereco_do_servidor.sin_addr) == -1)
	{
		throw Excecao_IP_Invalido();
	}
}

void Cliente::conecta()
{
	int erro = connect(socket_do_cliente, (sockaddr *) &endereco_do_servidor, sizeof(endereco_do_servidor));

	if(erro == -1)
	{
		throw Excecao_Nao_Possivel_Conectar();
	}
}

void Cliente::receba_msg(void * msg, size_t tamanho)
{
	int erro = recv(socket_do_cliente, msg, tamanho, 0);

	if(erro == -1)
	{
		throw Excecao_Falha_na_Comunicacao();
	}
}

void Cliente::envia_msg(const void * msg, size_t tamanho)
{
	int erro = send(socket_do_cliente, msg, tamanho, 0);

	if(erro == -1)
	{
		throw Excecao_Falha_na_Comunicacao();
	}
}

Cliente::~Cliente() { close(socket_do_cliente); }

