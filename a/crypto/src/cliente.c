/**
 * @file   cliente.c
 * @brief  Implementacao de biblioteca pa facilitar uso de rede como cliente.
 * @author Inaue Ferreira da Silva
 * @date   07-07-2025
 */

#include "../include/cliente.h"

char c_cria_cliente(Cliente * c, const char * ip_do_servidor, unsigned short porta_do_servidor)
{
	if(c == NULL || ip_do_servidor == NULL)
		return ERRO_NA_REDE;

	c->porta_do_servidor_ = porta_do_servidor;
	c->ip_do_servidor_    = ip_do_servidor;

	return SUCESSO_NA_REDE;
}

char c_configura_cliente(Cliente * c)
{
	if(c == NULL)
		return ERRO_NA_REDE;

	if(c_cria_socket_(c) == ERRO_NA_REDE)
		return ERRO_NA_REDE;

	if(c_cria_endereco_do_servidor_(c) == ERRO_NA_REDE)
		return ERRO_NA_REDE;

	return SUCESSO_NA_REDE;
}

char c_cria_socket_(Cliente * c)
{
	if(c == NULL)
		return ERRO_NA_REDE;

	c->socket_do_cliente_ = socket(AF_INET, SOCK_STREAM, 0);

	if(c->socket_do_cliente_ == -1)
		return ERRO_NA_REDE;

	return SUCESSO_NA_REDE;
}

char c_cria_endereco_do_servidor_(Cliente * c)
{
	if(c == NULL)
		return ERRO_NA_REDE;

	c->endereco_do_servidor_.sin_family = AF_INET;
	c->endereco_do_servidor_.sin_port   = htons(c->porta_do_servidor_);

	if(inet_aton(c->ip_do_servidor_, &c->endereco_do_servidor_.sin_addr) == -1)
		return ERRO_NA_REDE;

	return SUCESSO_NA_REDE;
}

char c_conecta(Cliente * c)
{
	if(c == NULL)
		return ERRO_NA_REDE;

	int erro = connect(c->socket_do_cliente_, (struct sockaddr *) &c->endereco_do_servidor_, sizeof(c->endereco_do_servidor_));

	if(erro == -1)
		return ERRO_NA_REDE;
	
	return SUCESSO_NA_REDE;
}

char c_receba_msg(Cliente * c, void * msg, size_t tamanho)
{
	if(c == NULL || msg == NULL || tamanho == 0)
		return ERRO_NA_REDE;

	int erro = recv(c->socket_do_cliente_, msg, tamanho, 0);

	if(erro == -1)
		return ERRO_NA_REDE;

	return SUCESSO_NA_REDE;
}

char c_envia_msg(Cliente * c, const void * msg, size_t tamanho)
{
	if(c == NULL || msg == NULL || tamanho == 0)
		return ERRO_NA_REDE;
	
	int erro = send(c->socket_do_cliente_, msg, tamanho, 0);

	if(erro == -1)
		return ERRO_NA_REDE;

	return SUCESSO_NA_REDE;
}

void c_destroi(Cliente * c)
{
	if(c == NULL)
		return;

	close(c->socket_do_cliente_);
}
